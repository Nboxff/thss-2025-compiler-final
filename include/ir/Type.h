#pragma once

#include <vector>
#include <iostream>
#include <string>

class Type {
public:
    enum TypeID {
        VoidTyID,
        LabelTyID,
        IntegerTyID,
        FunctionTyID,
        PointerTyID,
        ArrayTyID
    };

    explicit Type(TypeID tid) : tid_(tid) {}
    virtual ~Type() = default;

    TypeID getTypeID() const { return tid_; }

    bool isVoidTy() const { return tid_ == VoidTyID; }
    bool isLabelTy() const { return tid_ == LabelTyID; }
    bool isIntegerTy() const { return tid_ == IntegerTyID; }
    bool isFunctionTy() const { return tid_ == FunctionTyID; }
    bool isPointerTy() const { return tid_ == PointerTyID; }
    bool isArrayTy() const { return tid_ == ArrayTyID; }

    static Type *getVoidTy();
    static Type *getLabelTy();
    static Type *getInt1Ty();
    static Type *getInt32Ty();
    static Type *getInt32PtrTy();

    virtual std::string print() = 0;

private:
    TypeID tid_;
};

class IntegerType : public Type {
public:
    explicit IntegerType(unsigned width) : Type(IntegerTyID), width_(width) {}

    unsigned getBitWidth() const { return width_; }

    std::string print() override;

private:
    unsigned width_;
};

class FunctionType : public Type {
public:
    FunctionType(Type *result, std::vector<Type *> params)
        : Type(FunctionTyID), result_(result), params_(std::move(params)) {}

    static FunctionType *get(Type *result, std::vector<Type *> params);

    Type *getReturnType() const { return result_; }
    unsigned getNumParams() const { return params_.size(); }
    Type *getParamType(unsigned i) const { return params_[i]; }

    std::string print() override;

private:
    Type *result_;
    std::vector<Type *> params_;
};

class ArrayType : public Type {
public:
    ArrayType(Type *contained, unsigned num_elements)
        : Type(ArrayTyID), contained_(contained), num_elements_(num_elements) {}

    static ArrayType *get(Type *contained, unsigned num_elements);

    Type *getElementType() const { return contained_; }
    unsigned getNumElements() const { return num_elements_; }

    std::string print() override;

private:
    Type *contained_;
    unsigned num_elements_;
};

class PointerType : public Type {
public:
    explicit PointerType(Type *contained) : Type(PointerTyID), contained_(contained) {}

    static PointerType *get(Type *contained);

    Type *getElementType() const { return contained_; }

    std::string print() override;

private:
    Type *contained_;
};
