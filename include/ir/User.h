#pragma once

#include "ir/Value.h"
#include <vector>

class User : public Value {
public:
    User(Type *ty, const std::string &name = "", unsigned num_ops = 0)
        : Value(ty, name), operands_(num_ops) {}

    Value *getOperand(unsigned i) const { return operands_[i]; }
    void setOperand(unsigned i, Value *v);
    unsigned getNumOperands() const { return operands_.size(); }

    void addOperand(Value *v);
    
    // Helper to find operand index (simplified)
    int getOperandNumber(Value *v) {
        for (size_t i = 0; i < operands_.size(); ++i) {
            if (operands_[i] == v) return i;
        }
        return -1;
    }

protected:
    std::vector<Value *> operands_;
};
