#pragma once

#include "ir/BasicBlock.h"
#include "ir/Instruction.h"
#include "ir/Type.h"
#include "ir/Value.h"

class IRBuilder {
public:
    IRBuilder(BasicBlock *bb = nullptr) : insert_point_(bb) {}

    void setInsertPoint(BasicBlock *bb) {
        insert_point_ = bb;
    }

    BasicBlock *getInsertPoint() const {
        return insert_point_;
    }

    BinaryInst *createAdd(Value *lhs, Value *rhs) {
        auto *inst = BinaryInst::createAdd(lhs, rhs, insert_point_);
        inst->setName(getNextName());
        return inst;
    }

    BinaryInst *createSub(Value *lhs, Value *rhs) {
        auto *inst = BinaryInst::createSub(lhs, rhs, insert_point_);
        inst->setName(getNextName());
        return inst;
    }

    BinaryInst *createMul(Value *lhs, Value *rhs) {
        auto *inst = BinaryInst::createMul(lhs, rhs, insert_point_);
        inst->setName(getNextName());
        return inst;
    }

    BinaryInst *createSDiv(Value *lhs, Value *rhs) {
        auto *inst = BinaryInst::createSDiv(lhs, rhs, insert_point_);
        inst->setName(getNextName());
        return inst;
    }

    BinaryInst *createSRem(Value *lhs, Value *rhs) {
        auto *inst = BinaryInst::createSRem(lhs, rhs, insert_point_);
        inst->setName(getNextName());
        return inst;
    }

    ReturnInst *createRet(Value *val) {
        return ReturnInst::create(val, insert_point_);
    }

    ReturnInst *createRetVoid() {
        return ReturnInst::createVoid(insert_point_);
    }

    BranchInst *createBr(BasicBlock *dest) {
        return BranchInst::create(dest, insert_point_);
    }

    BranchInst *createCondBr(Value *cond, BasicBlock *if_true, BasicBlock *if_false) {
        return BranchInst::create(cond, if_true, if_false, insert_point_);
    }

    AllocaInst *createAlloca(Type *ty) {
        auto *inst = new AllocaInst(ty, insert_point_);
        inst->setName(getNextName());
        return inst;
    }

    LoadInst *createLoad(Type *ty, Value *ptr) {
        auto *inst = new LoadInst(ty, ptr, insert_point_);
        inst->setName(getNextName());
        return inst;
    }

    StoreInst *createStore(Value *val, Value *ptr) {
        return new StoreInst(val, ptr, insert_point_);
    }

    ICmpInst *createICmpEQ(Value *lhs, Value *rhs) {
        auto *inst = new ICmpInst(ICmpInst::EQ, lhs, rhs, insert_point_);
        inst->setName(getNextName());
        return inst;
    }

    ICmpInst *createICmpNE(Value *lhs, Value *rhs) {
        auto *inst = new ICmpInst(ICmpInst::NE, lhs, rhs, insert_point_);
        inst->setName(getNextName());
        return inst;
    }

    ICmpInst *createICmpGT(Value *lhs, Value *rhs) {
        auto *inst = new ICmpInst(ICmpInst::GT, lhs, rhs, insert_point_);
        inst->setName(getNextName());
        return inst;
    }

    ICmpInst *createICmpGE(Value *lhs, Value *rhs) {
        auto *inst = new ICmpInst(ICmpInst::GE, lhs, rhs, insert_point_);
        inst->setName(getNextName());
        return inst;
    }

    ICmpInst *createICmpLT(Value *lhs, Value *rhs) {
        auto *inst = new ICmpInst(ICmpInst::LT, lhs, rhs, insert_point_);
        inst->setName(getNextName());
        return inst;
    }

    ICmpInst *createICmpLE(Value *lhs, Value *rhs) {
        auto *inst = new ICmpInst(ICmpInst::LE, lhs, rhs, insert_point_);
        inst->setName(getNextName());
        return inst;
    }

    CallInst *createCall(Function *func, std::vector<Value *> args) {
        auto *inst = new CallInst(func, args, insert_point_);
        if (!inst->getType()->isVoidTy()) {
            inst->setName(getNextName());
        }
        return inst;
    }

    ZExtInst *createZExt(Value *val, Type *ty) {
        auto *inst = new ZExtInst(val, ty, insert_point_);
        inst->setName(getNextName());
        return inst;
    }

    GetElementPtrInst *createGEP(Value *ptr, std::vector<Value *> idxs) {
        auto *inst = new GetElementPtrInst(ptr, idxs, insert_point_);
        inst->setName(getNextName());
        return inst;
    }

private:
    BasicBlock *insert_point_;
    unsigned inst_count_ = 0;  // 指令计数器

    // 生成指令名称
    std::string getNextName() {
        return std::to_string(inst_count_++);
    }
};
