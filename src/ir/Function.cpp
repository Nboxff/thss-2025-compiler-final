#include "ir/Function.h"
#include "ir/Module.h"
#include <sstream>

Function::Function(FunctionType *ty, const std::string &name, Module *parent)
    : User(ty, name), parent_(parent) {
    if (parent_) {
        parent_->addFunction(this);
    }
    // Create arguments
    for (unsigned i = 0; i < ty->getNumParams(); ++i) {
        Argument *arg = new Argument(ty->getParamType(i), "", this, i);
        arguments_.push_back(arg);
    }
}

Function *Function::create(FunctionType *ty, const std::string &name, Module *parent) {
    return new Function(ty, name, parent);
}

FunctionType *Function::getFunctionType() const {
    return static_cast<FunctionType *>(getType());
}

void Function::addBasicBlock(BasicBlock *bb) {
    basic_blocks_.push_back(bb);
}

std::string Function::print() const {
    std::string s = "define " + getFunctionType()->getReturnType()->print() + " @" + getName() + "(";
    for (size_t i = 0; i < arguments_.size(); ++i) {
        s += arguments_[i]->getType()->print() + " " + arguments_[i]->print();
        if (i < arguments_.size() - 1)
            s += ", ";
    }
    s += ") {\n";
    for (auto bb : basic_blocks_) {
        s += bb->print();
    }
    s += "}\n";
    return s;
}
