#include <iostream>
#include <fstream>
#include "antlr4-runtime.h"
#include "SysYLexer.h"
#include "SysYParser.h"
#include "SysYParserBaseVisitor.h"
#include "ir/Module.h"
#include "ir/Function.h"
#include "ir/BasicBlock.h"
#include "ir/Instruction.h"
#include "ir/Type.h"
#include "ir/Constant.h"
#include "ir/IRBuilder.h"

using namespace antlr4;

void testIR() {
    // 创建一个 Module
    Module *module = new Module("test_module");

    // 创建 main 函数类型: int main()
    std::vector<Type *> params;
    FunctionType *funcType = FunctionType::get(Type::getInt32Ty(), params);

    // 创建 main 函数
    Function *mainFunc = Function::create(funcType, "main", module);

    // 创建基本块 entry
    BasicBlock *entryBB = BasicBlock::create("entry", mainFunc);

    // 使用 IRBuilder
    IRBuilder builder(entryBB);

    // 在 entry 中添加指令
    // %1 = alloca i32
    AllocaInst *alloca = builder.createAlloca(Type::getInt32Ty());
    alloca->setName("1");

    // store i32 10, i32* %1
    ConstantInt *const10 = ConstantInt::get(10);
    builder.createStore(const10, alloca);

    // %2 = load i32, i32* %1
    LoadInst *load = builder.createLoad(Type::getInt32Ty(), alloca);
    load->setName("2");

    // %3 = add i32 %2, 20
    ConstantInt *const20 = ConstantInt::get(20);
    BinaryInst *add = builder.createAdd(load, const20);
    add->setName("3");

    // ret i32 %3
    builder.createRet(add);

    // 打印生成的 IR
    std::cout << "=== Generated IR Verification ===" << std::endl;
    std::cout << module->print();
    std::cout << "===============================" << std::endl;
}

int main(int argc, const char *argv[]) {
  // 如果没有参数，运行 IR 测试
  if (argc < 2) {
      testIR();
      return 0;
  }

  if (argc < 3) {
    std::cerr << "Usage: ./compiler <input-file> <output-file>"
              << std::endl;
    return 1;
  }

  std::ifstream stream;
  stream.open(argv[1]);
  if (!stream.is_open()) {
      std::cerr << "Failed to open input file: " << argv[1] << std::endl;
      return 1;
  }

  ANTLRInputStream input(stream);
  SysYLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  SysYParser parser(&tokens);

  tree::ParseTree *tree = parser.compUnit();

  if (parser.getNumberOfSyntaxErrors() > 0) {
      std::cerr << "Syntax error detected." << std::endl;
      return 1;
  }

  std::cout << "Parsed successfully!" << std::endl;

  // TODO: IR Generation

  return 0;
}