#include "ir/User.h"

void User::setOperand(unsigned i, Value *v) {
    if (i < operands_.size()) {
        operands_[i] = v;
        if (v) v->addUse(this);
    }
}

void User::addOperand(Value *v) {
    operands_.push_back(v);
    if (v) v->addUse(this);
}
