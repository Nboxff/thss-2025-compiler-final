#include "ir/Instruction.h"
#include "ir/BasicBlock.h"
#include "ir/Function.h"
#include <iostream>

Instruction::Instruction(Type *ty, OpID id, unsigned num_ops, BasicBlock *parent)
    : User(ty, "", num_ops), op_id_(id), parent_(parent) {
    if (parent_) {
        parent_->addInstruction(this);
    }
}

bool Instruction::isBinary() const {
    return op_id_ >= Add && op_id_ <= SRem;
}

bool Instruction::isTerminator() const {
    return op_id_ == Ret || op_id_ == Br;
}

BinaryInst::BinaryInst(Type *ty, OpID id, Value *v1, Value *v2, BasicBlock *parent)
    : Instruction(ty, id, 2, parent) {
    setOperand(0, v1);
    setOperand(1, v2);
}

BinaryInst *BinaryInst::createAdd(Value *v1, Value *v2, BasicBlock *parent) {
    return new BinaryInst(v1->getType(), Add, v1, v2, parent);
}

BinaryInst *BinaryInst::createSub(Value *v1, Value *v2, BasicBlock *parent) {
    return new BinaryInst(v1->getType(), Sub, v1, v2, parent);
}

BinaryInst *BinaryInst::createMul(Value *v1, Value *v2, BasicBlock *parent) {
    return new BinaryInst(v1->getType(), Mul, v1, v2, parent);
}

BinaryInst *BinaryInst::createSDiv(Value *v1, Value *v2, BasicBlock *parent) {
    return new BinaryInst(v1->getType(), SDiv, v1, v2, parent);
}

BinaryInst *BinaryInst::createSRem(Value *v1, Value *v2, BasicBlock *parent) {
    return new BinaryInst(v1->getType(), SRem, v1, v2, parent);
}

std::string BinaryInst::getOpName() const {
    switch (op_id_) {
        case Add: return "add";
        case Sub: return "sub";
        case Mul: return "mul";
        case SDiv: return "sdiv";
        case SRem: return "srem";
        default: return "";
    }
}

std::string BinaryInst::print() const {
    std::string s = "%" + getName() + " = " + getOpName() + " " + getType()->print() + " ";
    s += getOperand(0)->getNameStr() + ", " + getOperand(1)->getNameStr();
    return s;
}

AllocaInst::AllocaInst(Type *ty, BasicBlock *parent)
    : Instruction(PointerType::get(ty), Alloca, 0, parent) {}

Type *AllocaInst::getAllocatedType() const {
    return static_cast<PointerType *>(getType())->getElementType();
}

std::string AllocaInst::print() const {
    return "%" + getName() + " = alloca " + getAllocatedType()->print();
}

LoadInst::LoadInst(Type *ty, Value *ptr, BasicBlock *parent)
    : Instruction(ty, Load, 1, parent) {
    setOperand(0, ptr);
}

std::string LoadInst::print() const {
    return "%" + getName() + " = load " + getType()->print() + ", " + getOperand(0)->getType()->print() + " " + getOperand(0)->getNameStr();
}

StoreInst::StoreInst(Value *val, Value *ptr, BasicBlock *parent)
    : Instruction(Type::getVoidTy(), Store, 2, parent) {
    setOperand(0, val);
    setOperand(1, ptr);
}

std::string StoreInst::print() const {
    return "store " + getOperand(0)->getType()->print() + " " + getOperand(0)->getNameStr() + ", " + getOperand(1)->getType()->print() + " " + getOperand(1)->getNameStr();
}

ReturnInst::ReturnInst(Value *val, BasicBlock *parent)
    : Instruction(Type::getVoidTy(), Ret, val ? 1 : 0, parent) {
    if (val) setOperand(0, val);
}

ReturnInst *ReturnInst::createVoid(BasicBlock *parent) {
    return new ReturnInst(nullptr, parent);
}

ReturnInst *ReturnInst::create(Value *val, BasicBlock *parent) {
    return new ReturnInst(val, parent);
}

bool ReturnInst::isVoidRet() const {
    return getNumOperands() == 0;
}

std::string ReturnInst::print() const {
    if (isVoidRet()) {
        return "ret void";
    } else {
        return "ret " + getOperand(0)->getType()->print() + " " + getOperand(0)->getNameStr();
    }
}

BranchInst::BranchInst(BasicBlock *if_true, BasicBlock *parent)
    : Instruction(Type::getVoidTy(), Br, 1, parent) {
    setOperand(0, if_true);
}

BranchInst::BranchInst(Value *cond, BasicBlock *if_true, BasicBlock *if_false, BasicBlock *parent)
    : Instruction(Type::getVoidTy(), Br, 3, parent) {
    setOperand(0, cond);
    setOperand(1, if_true);
    setOperand(2, if_false);
}

BranchInst *BranchInst::create(BasicBlock *if_true, BasicBlock *parent) {
    return new BranchInst(if_true, parent);
}

BranchInst *BranchInst::create(Value *cond, BasicBlock *if_true, BasicBlock *if_false, BasicBlock *parent) {
    return new BranchInst(cond, if_true, if_false, parent);
}

bool BranchInst::isCond() const {
    return getNumOperands() == 3;
}

std::string BranchInst::print() const {
    if (isCond()) {
        return "br " + getOperand(0)->getType()->print() + " " + getOperand(0)->getNameStr() + ", label %" + getOperand(1)->getNameStr() + ", label %" + getOperand(2)->getNameStr();
    } else {
        return "br label %" + getOperand(0)->getNameStr();
    }
}

ICmpInst::ICmpInst(ICmpOp op, Value *lhs, Value *rhs, BasicBlock *parent)
    : Instruction(Type::getInt1Ty(), ICmp, 2, parent), cmp_op_(op) {
    setOperand(0, lhs);
    setOperand(1, rhs);
}

std::string ICmpInst::getOpName() const {
    switch (cmp_op_) {
        case EQ: return "eq";
        case NE: return "ne";
        case GT: return "sgt";
        case GE: return "sge";
        case LT: return "slt";
        case LE: return "sle";
        default: return "";
    }
}

std::string ICmpInst::print() const {
    return "%" + getName() + " = icmp " + getOpName() + " " + getOperand(0)->getType()->print() + " " + getOperand(0)->getNameStr() + ", " + getOperand(1)->getNameStr();
}

CallInst::CallInst(Function *func, std::vector<Value *> args, BasicBlock *parent)
    : Instruction(func->getFunctionType()->getReturnType(), Call, args.size() + 1, parent) {
    setOperand(0, func);
    for (size_t i = 0; i < args.size(); ++i) {
        setOperand(i + 1, args[i]);
    }
}

std::string CallInst::print() const {
    std::string s;
    if (!getType()->isVoidTy()) {
        s += "%" + getName() + " = ";
    }
    s += "call " + getType()->print() + " @" + getOperand(0)->getNameStr() + "(";
    for (size_t i = 1; i < getNumOperands(); ++i) {
        s += getOperand(i)->getType()->print() + " " + getOperand(i)->getNameStr();
        if (i < getNumOperands() - 1)
            s += ", ";
    }
    s += ")";
    return s;
}

ZExtInst::ZExtInst(Value *val, Type *ty, BasicBlock *parent)
    : Instruction(ty, ZExt, 1, parent) {
    setOperand(0, val);
}

std::string ZExtInst::print() const {
    return "%" + getName() + " = zext " + getOperand(0)->getType()->print() + " " + getOperand(0)->getNameStr() + " to " + getType()->print();
}

GetElementPtrInst::GetElementPtrInst(Value *ptr, std::vector<Value *> idxs, BasicBlock *parent)
    : Instruction(PointerType::get(static_cast<PointerType *>(ptr->getType())->getElementType()), GetElementPtr, idxs.size() + 1, parent) {
    setOperand(0, ptr);
    for (size_t i = 0; i < idxs.size(); ++i) {
        setOperand(i + 1, idxs[i]);
    }
}

Type *GetElementPtrInst::getElementType() const {
    return static_cast<PointerType *>(getOperand(0)->getType())->getElementType();
}

std::string GetElementPtrInst::print() const {
    std::string s = "%" + getName() + " = getelementptr " + getElementType()->print() + ", " + getOperand(0)->getType()->print() + " " + getOperand(0)->getNameStr();
    for (size_t i = 1; i < getNumOperands(); ++i) {
        s += ", " + getOperand(i)->getType()->print() + " " + getOperand(i)->getNameStr();
    }
    return s;
}
