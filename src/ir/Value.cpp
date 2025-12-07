#include "ir/Value.h"
#include "ir/User.h"

void Value::addUse(User *user) {
    use_list_.emplace_back(this, user);
}

void Value::replaceAllUsesWith(Value *new_val) {
    for (auto &use : use_list_) {
        use.user_->setOperand(use.user_->getOperandNumber(this), new_val);
    }
}
