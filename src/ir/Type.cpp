#include "ir/Type.h"

class VoidType : public Type {
public:
    VoidType() : Type(VoidTyID) {}
    std::string print() override { return "void"; }
};

class LabelType : public Type {
public:
    LabelType() : Type(LabelTyID) {}
    std::string print() override { return "label"; }
};

Type *Type::getVoidTy() {
    static VoidType *void_ty = new VoidType();
    return void_ty;
}

Type *Type::getLabelTy() {
    static LabelType *label_ty = new LabelType();
    return label_ty;
}

Type *Type::getInt1Ty() {
    static IntegerType *int1_ty = new IntegerType(1);
    return int1_ty;
}

Type *Type::getInt32Ty() {
    static IntegerType *int32_ty = new IntegerType(32);
    return int32_ty;
}

Type *Type::getInt32PtrTy() {
    static PointerType *int32_ptr_ty = new PointerType(getInt32Ty());
    return int32_ptr_ty;
}

std::string IntegerType::print() {
    return "i" + std::to_string(width_);
}

FunctionType *FunctionType::get(Type *result, std::vector<Type *> params) {
    return new FunctionType(result, params);
}

std::string FunctionType::print() {
    std::string s = result_->print() + " (";
    for (size_t i = 0; i < params_.size(); ++i) {
        s += params_[i]->print();
        if (i < params_.size() - 1)
            s += ", ";
    }
    s += ")";
    return s;
}

ArrayType *ArrayType::get(Type *contained, unsigned num_elements) {
    return new ArrayType(contained, num_elements);
}

std::string ArrayType::print() {
    return "[" + std::to_string(num_elements_) + " x " + contained_->print() + "]";
}

PointerType *PointerType::get(Type *contained) {
    return new PointerType(contained);
}

std::string PointerType::print() {
    return contained_->print() + "*";
}
