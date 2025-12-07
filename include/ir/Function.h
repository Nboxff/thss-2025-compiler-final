#pragma once

#include "ir/User.h"
#include "ir/BasicBlock.h"
#include "ir/Type.h"
#include <list>
#include <vector>

class Module;
class Argument;

class Function : public User {
public:
    Function(FunctionType *ty, const std::string &name, Module *parent);

    static Function *create(FunctionType *ty, const std::string &name, Module *parent);

    FunctionType *getFunctionType() const;
    
    void addBasicBlock(BasicBlock *bb);
    std::list<BasicBlock *> &getBasicBlocks() { return basic_blocks_; }

    std::vector<Argument *> &getArgs() { return arguments_; }

    std::string print() const override;
    std::string getNameStr() const override {
        return "@" + name_;
    }

private:
    Module *parent_;
    std::list<BasicBlock *> basic_blocks_;
    std::vector<Argument *> arguments_;
};

class Argument : public Value {
public:
    Argument(Type *ty, const std::string &name = "", Function *parent = nullptr, unsigned arg_no = 0)
        : Value(ty, name), parent_(parent), arg_no_(arg_no) {}

    std::string print() const override {
        return "%" + name_;
    }

private:
    Function *parent_;
    unsigned arg_no_;
};
