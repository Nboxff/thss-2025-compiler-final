#include "ir/Module.h"
#include "ir/Function.h"
#include "ir/BasicBlock.h"
#include "ir/Instruction.h"
#include "ir/Type.h"
#include "ir/Constant.h"
#include <iostream>
#include <vector>

int main() {
    // Create a module
    Module *m = new Module("test_module");

    // Create a function type: i32 main()
    std::vector<Type *> params;
    FunctionType *ft = FunctionType::get(Type::getInt32Ty(), params);

    // Create the main function
    Function *f = Function::create(ft, "main", m);

    // Create a basic block
    BasicBlock *bb = BasicBlock::create("entry", f);

    // Create some instructions
    // %1 = add i32 10, 20
    Value *v1 = ConstantInt::get(10);
    Value *v2 = ConstantInt::get(20);
    BinaryInst *add = BinaryInst::createAdd(v1, v2, bb);
    add->setName("1");

    // %2 = sub i32 %1, 5
    Value *v3 = ConstantInt::get(5);
    BinaryInst *sub = BinaryInst::createSub(add, v3, bb);
    sub->setName("2");

    // ret i32 %2
    ReturnInst::create(sub, bb);

    // Print the module
    std::cout << m->print() << std::endl;

    return 0;
}
