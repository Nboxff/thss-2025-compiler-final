#pragma once

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include "ir/Type.h"

class Value;
class User;

struct Use {
    Value *val_;
    User *user_;
    Use(Value *val, User *user) : val_(val), user_(user) {}
};

class Value {
public:
    explicit Value(Type *ty, const std::string &name = "") : type_(ty), name_(name) {}
    virtual ~Value() = default;

    Type *getType() const { return type_; }
    std::string getName() const { return name_; }
    virtual std::string getNameStr() const { return "%" + name_; }
    void setName(const std::string &name) { name_ = name; }

    void addUse(User *user);
    void replaceAllUsesWith(Value *new_val);

    virtual std::string print() const = 0;

protected:
    Type *type_;
    std::string name_;
    std::list<Use> use_list_;
};
