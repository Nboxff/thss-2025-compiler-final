#pragma once

#include "ir/Value.h"
#include <list>
#include <string>

class Function;
class Instruction;

class BasicBlock : public Value {
public:
    explicit BasicBlock(const std::string &name = "", Function *parent = nullptr);

    static BasicBlock *create(const std::string &name = "", Function *parent = nullptr);

    Function *getParent() const { return parent_; }
    std::list<Instruction *> &getInstructions() { return inst_list_; }
    
    void addInstruction(Instruction *inst);

    std::string print() const override;

private:
    Function *parent_;
    std::list<Instruction *> inst_list_;
};
