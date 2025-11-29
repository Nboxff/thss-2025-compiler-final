#include "Compiler/Compiler.h"
#include <fstream>
#include <sstream>
#include <antlr4-runtime.h>

// 需要包含生成的ANTLR头文件（假设已生成）
// #include "antlr/SysYLexer.h"
// #include "antlr/SysYParser.h"

namespace sysy {

Compiler::Compiler() 
    : astBuilder(std::make_unique<ASTBuilder>()),
      symbolTableManager(std::make_unique<SymbolTableManager>()) {
    
    semanticAnalyzer = std::make_unique<SemanticAnalyzer>(symbolTableManager.get());
    codeGenerator = std::make_unique<CodeGenerator>(symbolTableManager.get());
}

Compiler::~Compiler() = default;

bool Compiler::compile(const std::string& inputFile, const std::string& outputFile) {
    try {
        // 1. 解析：从源代码构建AST
        auto ast = parse(inputFile);
        if (!ast) {
            std::cerr << "Error: Failed to parse input file" << std::endl;
            return false;
        }
        
        // 2. 语义分析：构建符号表，进行类型检查
        semanticAnalysis(ast.get());
        
        // 3. 代码生成：生成LLVM IR文本
        std::string irCode = generateCode(ast.get());
        
        // 4. 输出IR到文件
        outputIR(outputFile, irCode);
        
        return true;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }
}

std::unique_ptr<CompUnitNode> Compiler::parse(const std::string& inputFile) {
    // TODO: 实现解析逻辑
    // 1. 读取输入文件
    // 2. 创建ANTLR输入流
    // 3. 创建词法分析器
    // 4. 创建语法分析器
    // 5. 获取ParseTree
    // 6. 使用ASTBuilder构建AST
    
    std::ifstream file(inputFile);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open input file: " << inputFile << std::endl;
        return nullptr;
    }
    
    // TODO: 实际实现需要：
    // antlr4::ANTLRInputStream input(file);
    // SysYLexer lexer(&input);
    // antlr4::CommonTokenStream tokens(&lexer);
    // SysYParser parser(&tokens);
    // antlr4::tree::ParseTree* tree = parser.compUnit();
    // return astBuilder->build(tree);
    
    return nullptr;
}

void Compiler::semanticAnalysis(CompUnitNode* ast) {
    // 执行语义分析
    semanticAnalyzer->analyze(ast);
}

std::string Compiler::generateCode(CompUnitNode* ast) {
    // 生成LLVM IR代码文本
    return codeGenerator->generate(ast);
}

void Compiler::outputIR(const std::string& outputFile, const std::string& irCode) {
    // 输出LLVM IR文本到文件
    std::ofstream file(outputFile);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open output file: " << outputFile << std::endl;
        return;
    }
    file << irCode;
    file.close();
}

} // namespace sysy

