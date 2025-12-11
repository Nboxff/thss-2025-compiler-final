#pragma once
#include "ir/Type.h"
#include "ir/Value.h"
#include <unordered_map>
#include <vector>
#include <string>

// 符号信息
struct Symbol {
    std::string name;
    Type *type;
    Value *value; // 对应 IR 值
    bool is_global;

    Symbol(std::string n, Type *t, Value *v, bool global)
        : name(std::move(n)), type(t), value(v), is_global(global) {}
};

// 符号表
class SymbolTable {
public:
    SymbolTable() {
        // 初始化全局作用域
        scopes_.emplace_back();
    }

    // 进入新作用域
    void enterScope() {
        scopes_.emplace_back();
    }

    // 退出当前作用域
    void exitScope() {
        if (scopes_.size() > 1) { // 保留全局作用域
            scopes_.pop_back();
        }
    }

    // 插入符号
    bool insert(const std::string &name, Symbol symbol) {
        auto &current = scopes_.back();
        auto [it, inserted] = current.emplace(name, std::move(symbol));
        return inserted; // false 表示同一作用域内重定义
    }

    // 查找符号
    Symbol *lookup(const std::string &name) {
        for (auto it = scopes_.rbegin(); it != scopes_.rend(); ++it) {
            auto &scope = *it;
            auto found = scope.find(name);
            if (found != scope.end()) {
                return &found->second;
            }
        }
        return nullptr;
    }

private:
    std::vector<std::unordered_map<std::string, Symbol>> scopes_;
};