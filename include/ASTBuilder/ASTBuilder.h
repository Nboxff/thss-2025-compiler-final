#pragma once

#include "AST/Nodes.h"
#include <memory>
#include <string>

// 前向声明ANTLR类型
namespace antlr4 {
    class tree::ParseTree;
}

// 前向声明生成的ANTLR类
namespace antlrcpp {
    class SysYParser;
    class SysYParserBaseVisitor;
}

namespace sysy {

/**
 * AST构建器
 * 从ANTLR ParseTree构建AST
 */
class ASTBuilder {
private:
    // 辅助方法：从ParseTree节点构建AST节点
    std::unique_ptr<CompUnitNode> buildCompUnit(antlr4::tree::ParseTree* tree);
    std::unique_ptr<DeclNode> buildDecl(antlr4::tree::ParseTree* tree);
    std::unique_ptr<ConstDeclNode> buildConstDecl(antlr4::tree::ParseTree* tree);
    std::unique_ptr<VarDeclNode> buildVarDecl(antlr4::tree::ParseTree* tree);
    std::unique_ptr<ConstDefNode> buildConstDef(antlr4::tree::ParseTree* tree);
    std::unique_ptr<VarDefNode> buildVarDef(antlr4::tree::ParseTree* tree);
    std::unique_ptr<ConstInitValNode> buildConstInitVal(antlr4::tree::ParseTree* tree);
    std::unique_ptr<InitValNode> buildInitVal(antlr4::tree::ParseTree* tree);
    std::unique_ptr<FuncDefNode> buildFuncDef(antlr4::tree::ParseTree* tree);
    std::unique_ptr<FuncFParamNode> buildFuncFParam(antlr4::tree::ParseTree* tree);
    std::unique_ptr<BlockStmtNode> buildBlock(antlr4::tree::ParseTree* tree);
    std::unique_ptr<BlockItemNode> buildBlockItem(antlr4::tree::ParseTree* tree);
    std::unique_ptr<StmtNode> buildStmt(antlr4::tree::ParseTree* tree);
    std::unique_ptr<AssignStmtNode> buildAssignStmt(antlr4::tree::ParseTree* tree);
    std::unique_ptr<ExpStmtNode> buildExpStmt(antlr4::tree::ParseTree* tree);
    std::unique_ptr<IfStmtNode> buildIfStmt(antlr4::tree::ParseTree* tree);
    std::unique_ptr<WhileStmtNode> buildWhileStmt(antlr4::tree::ParseTree* tree);
    std::unique_ptr<BreakStmtNode> buildBreakStmt(antlr4::tree::ParseTree* tree);
    std::unique_ptr<ContinueStmtNode> buildContinueStmt(antlr4::tree::ParseTree* tree);
    std::unique_ptr<ReturnStmtNode> buildReturnStmt(antlr4::tree::ParseTree* tree);
    std::unique_ptr<ExpNode> buildExp(antlr4::tree::ParseTree* tree);
    std::unique_ptr<AddExpNode> buildAddExp(antlr4::tree::ParseTree* tree);
    std::unique_ptr<MulExpNode> buildMulExp(antlr4::tree::ParseTree* tree);
    std::unique_ptr<UnaryExpNode> buildUnaryExp(antlr4::tree::ParseTree* tree);
    std::unique_ptr<PrimaryExpNode> buildPrimaryExp(antlr4::tree::ParseTree* tree);
    std::unique_ptr<LValNode> buildLVal(antlr4::tree::ParseTree* tree);
    std::unique_ptr<NumberNode> buildNumber(antlr4::tree::ParseTree* tree);
    std::unique_ptr<FuncCallNode> buildFuncCall(antlr4::tree::ParseTree* tree);
    std::unique_ptr<RelExpNode> buildRelExp(antlr4::tree::ParseTree* tree);
    std::unique_ptr<EqExpNode> buildEqExp(antlr4::tree::ParseTree* tree);
    std::unique_ptr<LAndExpNode> buildLAndExp(antlr4::tree::ParseTree* tree);
    std::unique_ptr<LOrExpNode> buildLOrExp(antlr4::tree::ParseTree* tree);
    std::unique_ptr<CondNode> buildCond(antlr4::tree::ParseTree* tree);
    std::unique_ptr<ConstExpNode> buildConstExp(antlr4::tree::ParseTree* tree);
    
    // 辅助方法：获取子节点
    antlr4::tree::ParseTree* getChild(antlr4::tree::ParseTree* tree, size_t index);
    std::string getText(antlr4::tree::ParseTree* tree);
    int getIntValue(antlr4::tree::ParseTree* tree);
    
public:
    ASTBuilder() = default;
    ~ASTBuilder() = default;
    
    /**
     * 从ParseTree构建AST
     * @param tree ANTLR ParseTree根节点
     * @return AST根节点
     */
    std::unique_ptr<CompUnitNode> build(antlr4::tree::ParseTree* tree);
};

} // namespace sysy

