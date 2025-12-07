#pragma once

#include "ir/User.h"
#include "ir/BasicBlock.h"
#include <list>
#include <string>

class Module;
class Constant;

class GlobalVariable : public User {
public:
    GlobalVariable(std::string name, Module *m, Type *ty, bool is_const, Constant *init = nullptr);
    std::string print() const override;
private:
    bool is_const_;
    Constant *init_val_;
};

class Module {
public:
    explicit Module(std::string name) : name_(std::move(name)) {}

    void addFunction(Function *f);
    void addGlobalVariable(GlobalVariable *g);

    std::list<Function *> &getFunctions() { return functions_; }
    std::list<GlobalVariable *> &getGlobalVariables() { return global_list_; }

    std::string print() const;

private:
    std::string name_;
    std::list<Function *> functions_;
    std::list<GlobalVariable *> global_list_;
};
