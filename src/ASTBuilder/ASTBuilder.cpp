#include "ASTBuilder/ASTBuilder.h"
#include "AST/Nodes.h"
#include <antlr4-runtime.h>

namespace sysy {

std::unique_ptr<CompUnitNode> ASTBuilder::build(antlr4::tree::ParseTree* tree) {
    return buildCompUnit(tree);
}

std::unique_ptr<CompUnitNode> ASTBuilder::buildCompUnit(antlr4::tree::ParseTree* tree) {
    // TODO: 实现从ParseTree构建CompUnitNode
    auto node = std::make_unique<CompUnitNode>();
    return node;
}

std::unique_ptr<DeclNode> ASTBuilder::buildDecl(antlr4::tree::ParseTree* tree) {
    // TODO: 实现从ParseTree构建DeclNode
    return nullptr;
}

std::unique_ptr<ConstDeclNode> ASTBuilder::buildConstDecl(antlr4::tree::ParseTree* tree) {
    // TODO: 实现从ParseTree构建ConstDeclNode
    return nullptr;
}

std::unique_ptr<VarDeclNode> ASTBuilder::buildVarDecl(antlr4::tree::ParseTree* tree) {
    // TODO: 实现从ParseTree构建VarDeclNode
    return nullptr;
}

std::unique_ptr<ConstDefNode> ASTBuilder::buildConstDef(antlr4::tree::ParseTree* tree) {
    // TODO: 实现从ParseTree构建ConstDefNode
    return nullptr;
}

std::unique_ptr<VarDefNode> ASTBuilder::buildVarDef(antlr4::tree::ParseTree* tree) {
    // TODO: 实现从ParseTree构建VarDefNode
    return nullptr;
}

std::unique_ptr<ConstInitValNode> ASTBuilder::buildConstInitVal(antlr4::tree::ParseTree* tree) {
    // TODO: 实现从ParseTree构建ConstInitValNode
    return nullptr;
}

std::unique_ptr<InitValNode> ASTBuilder::buildInitVal(antlr4::tree::ParseTree* tree) {
    // TODO: 实现从ParseTree构建InitValNode
    return nullptr;
}

std::unique_ptr<FuncDefNode> ASTBuilder::buildFuncDef(antlr4::tree::ParseTree* tree) {
    // TODO: 实现从ParseTree构建FuncDefNode
    return nullptr;
}

std::unique_ptr<FuncFParamNode> ASTBuilder::buildFuncFParam(antlr4::tree::ParseTree* tree) {
    // TODO: 实现从ParseTree构建FuncFParamNode
    return nullptr;
}

std::unique_ptr<BlockStmtNode> ASTBuilder::buildBlock(antlr4::tree::ParseTree* tree) {
    // TODO: 实现从ParseTree构建BlockStmtNode
    return nullptr;
}

std::unique_ptr<BlockItemNode> ASTBuilder::buildBlockItem(antlr4::tree::ParseTree* tree) {
    // TODO: 实现从ParseTree构建BlockItemNode
    return nullptr;
}

std::unique_ptr<StmtNode> ASTBuilder::buildStmt(antlr4::tree::ParseTree* tree) {
    // TODO: 实现从ParseTree构建StmtNode
    return nullptr;
}

std::unique_ptr<AssignStmtNode> ASTBuilder::buildAssignStmt(antlr4::tree::ParseTree* tree) {
    // TODO: 实现从ParseTree构建AssignStmtNode
    return nullptr;
}

std::unique_ptr<ExpStmtNode> ASTBuilder::buildExpStmt(antlr4::tree::ParseTree* tree) {
    // TODO: 实现从ParseTree构建ExpStmtNode
    return nullptr;
}

std::unique_ptr<IfStmtNode> ASTBuilder::buildIfStmt(antlr4::tree::ParseTree* tree) {
    // TODO: 实现从ParseTree构建IfStmtNode
    return nullptr;
}

std::unique_ptr<WhileStmtNode> ASTBuilder::buildWhileStmt(antlr4::tree::ParseTree* tree) {
    // TODO: 实现从ParseTree构建WhileStmtNode
    return nullptr;
}

std::unique_ptr<BreakStmtNode> ASTBuilder::buildBreakStmt(antlr4::tree::ParseTree* tree) {
    // TODO: 实现从ParseTree构建BreakStmtNode
    return nullptr;
}

std::unique_ptr<ContinueStmtNode> ASTBuilder::buildContinueStmt(antlr4::tree::ParseTree* tree) {
    // TODO: 实现从ParseTree构建ContinueStmtNode
    return nullptr;
}

std::unique_ptr<ReturnStmtNode> ASTBuilder::buildReturnStmt(antlr4::tree::ParseTree* tree) {
    // TODO: 实现从ParseTree构建ReturnStmtNode
    return nullptr;
}

std::unique_ptr<ExpNode> ASTBuilder::buildExp(antlr4::tree::ParseTree* tree) {
    // TODO: 实现从ParseTree构建ExpNode
    return nullptr;
}

std::unique_ptr<AddExpNode> ASTBuilder::buildAddExp(antlr4::tree::ParseTree* tree) {
    // TODO: 实现从ParseTree构建AddExpNode
    return nullptr;
}

std::unique_ptr<MulExpNode> ASTBuilder::buildMulExp(antlr4::tree::ParseTree* tree) {
    // TODO: 实现从ParseTree构建MulExpNode
    return nullptr;
}

std::unique_ptr<UnaryExpNode> ASTBuilder::buildUnaryExp(antlr4::tree::ParseTree* tree) {
    // TODO: 实现从ParseTree构建UnaryExpNode
    return nullptr;
}

std::unique_ptr<PrimaryExpNode> ASTBuilder::buildPrimaryExp(antlr4::tree::ParseTree* tree) {
    // TODO: 实现从ParseTree构建PrimaryExpNode
    return nullptr;
}

std::unique_ptr<LValNode> ASTBuilder::buildLVal(antlr4::tree::ParseTree* tree) {
    // TODO: 实现从ParseTree构建LValNode
    return nullptr;
}

std::unique_ptr<NumberNode> ASTBuilder::buildNumber(antlr4::tree::ParseTree* tree) {
    // TODO: 实现从ParseTree构建NumberNode
    return nullptr;
}

std::unique_ptr<FuncCallNode> ASTBuilder::buildFuncCall(antlr4::tree::ParseTree* tree) {
    // TODO: 实现从ParseTree构建FuncCallNode
    return nullptr;
}

std::unique_ptr<RelExpNode> ASTBuilder::buildRelExp(antlr4::tree::ParseTree* tree) {
    // TODO: 实现从ParseTree构建RelExpNode
    return nullptr;
}

std::unique_ptr<EqExpNode> ASTBuilder::buildEqExp(antlr4::tree::ParseTree* tree) {
    // TODO: 实现从ParseTree构建EqExpNode
    return nullptr;
}

std::unique_ptr<LAndExpNode> ASTBuilder::buildLAndExp(antlr4::tree::ParseTree* tree) {
    // TODO: 实现从ParseTree构建LAndExpNode
    return nullptr;
}

std::unique_ptr<LOrExpNode> ASTBuilder::buildLOrExp(antlr4::tree::ParseTree* tree) {
    // TODO: 实现从ParseTree构建LOrExpNode
    return nullptr;
}

std::unique_ptr<CondNode> ASTBuilder::buildCond(antlr4::tree::ParseTree* tree) {
    // TODO: 实现从ParseTree构建CondNode
    return nullptr;
}

std::unique_ptr<ConstExpNode> ASTBuilder::buildConstExp(antlr4::tree::ParseTree* tree) {
    // TODO: 实现从ParseTree构建ConstExpNode
    return nullptr;
}

antlr4::tree::ParseTree* ASTBuilder::getChild(antlr4::tree::ParseTree* tree, size_t index) {
    if (tree->children.size() > index) {
        return tree->children[index];
    }
    return nullptr;
}

std::string ASTBuilder::getText(antlr4::tree::ParseTree* tree) {
    return tree->getText();
}

int ASTBuilder::getIntValue(antlr4::tree::ParseTree* tree) {
    // TODO: 实现从ParseTree节点提取整数值
    return 0;
}

} // namespace sysy

