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
        return BinaryInst::createAdd(lhs, rhs, insert_point_);
    }

    BinaryInst *createSub(Value *lhs, Value *rhs) {
        return BinaryInst::createSub(lhs, rhs, insert_point_);
    }

    BinaryInst *createMul(Value *lhs, Value *rhs) {
        return BinaryInst::createMul(lhs, rhs, insert_point_);
    }

    BinaryInst *createSDiv(Value *lhs, Value *rhs) {
        return BinaryInst::createSDiv(lhs, rhs, insert_point_);
    }

    BinaryInst *createSRem(Value *lhs, Value *rhs) {
        return BinaryInst::createSRem(lhs, rhs, insert_point_);
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
        return new AllocaInst(ty, insert_point_);
    }

    LoadInst *createLoad(Type *ty, Value *ptr) {
        return new LoadInst(ty, ptr, insert_point_);
    }

    StoreInst *createStore(Value *val, Value *ptr) {
        return new StoreInst(val, ptr, insert_point_);
    }

    ICmpInst *createICmpEQ(Value *lhs, Value *rhs) {
        return new ICmpInst(ICmpInst::EQ, lhs, rhs, insert_point_);
    }
    
    ICmpInst *createICmpNE(Value *lhs, Value *rhs) {
        return new ICmpInst(ICmpInst::NE, lhs, rhs, insert_point_);
    }

    ICmpInst *createICmpGT(Value *lhs, Value *rhs) {
        return new ICmpInst(ICmpInst::GT, lhs, rhs, insert_point_);
    }

    ICmpInst *createICmpGE(Value *lhs, Value *rhs) {
        return new ICmpInst(ICmpInst::GE, lhs, rhs, insert_point_);
    }

    ICmpInst *createICmpLT(Value *lhs, Value *rhs) {
        return new ICmpInst(ICmpInst::LT, lhs, rhs, insert_point_);
    }

    ICmpInst *createICmpLE(Value *lhs, Value *rhs) {
        return new ICmpInst(ICmpInst::LE, lhs, rhs, insert_point_);
    }

    CallInst *createCall(Function *func, std::vector<Value *> args) {
        return new CallInst(func, args, insert_point_);
    }

    ZExtInst *createZExt(Value *val, Type *ty) {
        return new ZExtInst(val, ty, insert_point_);
    }

    GetElementPtrInst *createGEP(Value *ptr, std::vector<Value *> idxs) {
        return new GetElementPtrInst(ptr, idxs, insert_point_);
    }

private:
    BasicBlock *insert_point_;
};
