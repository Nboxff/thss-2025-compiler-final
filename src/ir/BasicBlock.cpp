#include "ir/BasicBlock.h"
#include "ir/Function.h"
#include "ir/Instruction.h"
#include <sstream>

BasicBlock::BasicBlock(const std::string &name, Function *parent)
    : Value(Type::getLabelTy(), name), parent_(parent) {
    if (parent_) {
        parent_->addBasicBlock(this);
    }
}

BasicBlock *BasicBlock::create(const std::string &name, Function *parent) {
    return new BasicBlock(name, parent);
}

Instruction *BasicBlock::getTerminator() const {
    if (inst_list_.empty()) {
        return nullptr;
    }
    auto *last = inst_list_.back();
    return last->isTerminator() ? last : nullptr;
}

void BasicBlock::addInstruction(Instruction *inst) {
    inst_list_.push_back(inst);
    inst->setParent(this);
}

std::string BasicBlock::print() const {
    std::string s;
    if (!getName().empty()) {
        s += getName() + ":\n";
    }
    for (auto inst : inst_list_) {
        s += "  " + inst->print() + "\n";
    }
    return s;
}
