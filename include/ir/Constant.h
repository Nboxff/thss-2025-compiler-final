#pragma once

#include "ir/User.h"

class Constant : public User {
public:
    Constant(Type *ty, const std::string &name = "") : User(ty, name) {}
};

class ConstantInt : public Constant {
public:
    ConstantInt(Type *ty, int val) : Constant(ty), val_(val) {}

    static ConstantInt *get(int val) {
        return new ConstantInt(Type::getInt32Ty(), val);
    }
    
    static ConstantInt *get(Type* ty, int val) {
        return new ConstantInt(ty, val);
    }

    int getValue() const { return val_; }

    std::string print() const override {
        return std::to_string(val_);
    }

    std::string getNameStr() const override {
        return print();
    }

private:
    int val_;
};
