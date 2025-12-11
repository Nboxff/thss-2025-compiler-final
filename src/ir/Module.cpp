#include "ir/Module.h"
#include "ir/Function.h"
#include "ir/Constant.h"

GlobalVariable::GlobalVariable(std::string name, Module *m, Type *ty, bool is_const, Constant *init)
    : User(PointerType::get(ty), name), is_const_(is_const), init_val_(init) {
    m->addGlobalVariable(this);
}

std::string GlobalVariable::print() const {
    // getType()返回PointerType，需要获取被指向的类型
    Type *element_ty = static_cast<PointerType*>(getType())->getElementType();
    std::string s = "@" + getName() + " = " + (is_const_ ? "constant " : "global ") + element_ty->print() + " ";
    if (init_val_) {
        s += init_val_->print();
    } else {
        s += "zeroinitializer";
    }
    return s;
}

void Module::addFunction(Function *f) {
    functions_.push_back(f);
}

void Module::addGlobalVariable(GlobalVariable *g) {
    global_list_.push_back(g);
}

std::string Module::print() const {
    std::string s;
    for (auto g : global_list_) {
        s += g->print() + "\n";
    }
    for (auto f : functions_) {
        s += f->print() + "\n";
    }
    return s;
}
