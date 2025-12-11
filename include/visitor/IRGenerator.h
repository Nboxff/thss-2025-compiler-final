#pragma once
#include "SysYParserBaseVisitor.h"
#include "ir/Module.h"
#include "ir/IRBuilder.h"
#include "symbol/SymbolTable.h"
#include <any>
#include <map>
#include <string>

class IRGenerator : public SysYParserBaseVisitor {
public:
    IRGenerator(Module *module) : module_(module) {}

    std::any visitCompUnit(SysYParser::CompUnitContext *ctx) override;
    std::any visitFuncDef(SysYParser::FuncDefContext *ctx) override;
    std::any visitConstDecl(SysYParser::ConstDeclContext *ctx) override;
    std::any visitExp(SysYParser::ExpContext *ctx) override;
    std::any visitConstExp(SysYParser::ConstExpContext *ctx) override;
    std::any visitPrimaryExp(SysYParser::PrimaryExpContext *ctx) override;
    std::any visitUnaryExp(SysYParser::UnaryExpContext *ctx) override;
    std::any visitMulExp(SysYParser::MulExpContext *ctx) override;
    std::any visitAddExp(SysYParser::AddExpContext *ctx) override;
    std::any visitDecl(SysYParser::DeclContext *ctx) override;
    std::any visitBlock(SysYParser::BlockContext *ctx) override;
    std::any visitBlockItem(SysYParser::BlockItemContext *ctx) override;
    std::any visitAssignStmt(SysYParser::AssignStmtContext *ctx) override;
    std::any visitBlockStmt(SysYParser::BlockStmtContext *ctx) override;
    std::any visitReturnStmt(SysYParser::ReturnStmtContext *ctx) override;
    std::any visitExpStmt(SysYParser::ExpStmtContext *ctx) override;

private:
    Module *module_;
    Function *current_func_ = nullptr;
    IRBuilder builder_;
    SymbolTable symbol_table_;
};