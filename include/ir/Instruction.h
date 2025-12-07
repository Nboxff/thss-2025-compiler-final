#pragma once

#include "ir/User.h"
#include "ir/BasicBlock.h"

class Instruction : public User {
public:
    enum OpID {
        // Terminator
        Ret,
        Br,
        // Standard binary operators
        Add,
        Sub,
        Mul,
        SDiv,
        SRem,
        // Memory operators
        Alloca,
        Load,
        Store,
        // Other operators
        ICmp,
        Call,
        GetElementPtr,
        ZExt
    };

    Instruction(Type *ty, OpID id, unsigned num_ops, BasicBlock *parent = nullptr);

    OpID getOpID() const { return op_id_; }
    bool isBinary() const;
    bool isTerminator() const;

    BasicBlock *getParent() const { return parent_; }
    void setParent(BasicBlock *bb) { parent_ = bb; }

    std::string print() const override = 0;

protected:
    OpID op_id_;
    BasicBlock *parent_;
};

class BinaryInst : public Instruction {
public:
    BinaryInst(Type *ty, OpID id, Value *v1, Value *v2, BasicBlock *parent = nullptr);
    static BinaryInst *createAdd(Value *v1, Value *v2, BasicBlock *parent = nullptr);
    static BinaryInst *createSub(Value *v1, Value *v2, BasicBlock *parent = nullptr);
    static BinaryInst *createMul(Value *v1, Value *v2, BasicBlock *parent = nullptr);
    static BinaryInst *createSDiv(Value *v1, Value *v2, BasicBlock *parent = nullptr);
    static BinaryInst *createSRem(Value *v1, Value *v2, BasicBlock *parent = nullptr);

    std::string print() const override;
private:
    std::string getOpName() const;
};

class AllocaInst : public Instruction {
public:
    AllocaInst(Type *ty, BasicBlock *parent = nullptr);
    Type *getAllocatedType() const;
    std::string print() const override;
};

class LoadInst : public Instruction {
public:
    LoadInst(Type *ty, Value *ptr, BasicBlock *parent = nullptr);
    std::string print() const override;
};

class StoreInst : public Instruction {
public:
    StoreInst(Value *val, Value *ptr, BasicBlock *parent = nullptr);
    std::string print() const override;
};

class ReturnInst : public Instruction {
public:
    ReturnInst(Value *val = nullptr, BasicBlock *parent = nullptr);
    static ReturnInst *createVoid(BasicBlock *parent = nullptr);
    static ReturnInst *create(Value *val, BasicBlock *parent = nullptr);
    
    bool isVoidRet() const;
    std::string print() const override;
};

class BranchInst : public Instruction {
public:
    // Unconditional branch
    BranchInst(BasicBlock *if_true, BasicBlock *parent = nullptr);
    // Conditional branch
    BranchInst(Value *cond, BasicBlock *if_true, BasicBlock *if_false, BasicBlock *parent = nullptr);

    static BranchInst *create(BasicBlock *if_true, BasicBlock *parent = nullptr);
    static BranchInst *create(Value *cond, BasicBlock *if_true, BasicBlock *if_false, BasicBlock *parent = nullptr);

    bool isCond() const;
    std::string print() const override;
};

class ICmpInst : public Instruction {
public:
    enum ICmpOp {
        EQ, NE, GT, GE, LT, LE
    };
    ICmpInst(ICmpOp op, Value *lhs, Value *rhs, BasicBlock *parent = nullptr);
    std::string print() const override;
private:
    ICmpOp cmp_op_;
    std::string getOpName() const;
};

class CallInst : public Instruction {
public:
    CallInst(Function *func, std::vector<Value *> args, BasicBlock *parent = nullptr);
    std::string print() const override;
};

class ZExtInst : public Instruction {
public:
    ZExtInst(Value *val, Type *ty, BasicBlock *parent = nullptr);
    std::string print() const override;
};

class GetElementPtrInst : public Instruction {
public:
    GetElementPtrInst(Value *ptr, std::vector<Value *> idxs, BasicBlock *parent = nullptr);
    Type *getElementType() const;
    std::string print() const override;
};
