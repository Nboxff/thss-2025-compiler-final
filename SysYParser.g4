parser grammar SysYParser;

options {
    tokenVocab = SysYLexer;
}

compUnit
    : (decl | funcDef)+ EOF
    ;

decl
    : constDecl
    | varDecl
    ;

constDecl
    : CONST bType constDef (COMMA constDef)* SEMICOLON
    ;

bType
    : INT
    ;

constDef
    : IDENT (LBRACK constExp RBRACK)* ASSIGN constInitVal
    ;

constInitVal
    : constExp
    | LBRACE (constInitVal (COMMA constInitVal)*)? RBRACE
    ;

varDecl
    : bType varDef (COMMA varDef)* SEMICOLON
    ;

varDef
    : IDENT (LBRACK constExp RBRACK)* (ASSIGN initVal)?
    ;

initVal
    : exp
    | LBRACE (initVal (COMMA initVal)*)? RBRACE
    ;

funcDef
    : funcType IDENT LPAREN (funcFParams)? RPAREN block
    ;

funcType
    : VOID
    | INT
    ;

funcFParams
    : funcFParam (COMMA funcFParam)*
    ;

funcFParam
    : bType IDENT (LBRACK RBRACK (LBRACK constExp RBRACK)*)?
    ;

block
    : LBRACE (blockItem)* RBRACE
    ;

blockItem
    : decl
    | stmt
    ;

stmt
    : lVal ASSIGN exp SEMICOLON                    # assignStmt
    | (exp)? SEMICOLON                             # expStmt
    | block                                        # blockStmt
    | IF LPAREN cond RPAREN stmt (ELSE stmt)?      # ifStmt
    | WHILE LPAREN cond RPAREN stmt                # whileStmt
    | BREAK SEMICOLON                              # breakStmt
    | CONTINUE SEMICOLON                           # continueStmt
    | RETURN (exp)? SEMICOLON                      # returnStmt
    ;

exp
    : addExp
    ;

cond
    : lOrExp
    ;

lVal
    : IDENT (LBRACK exp RBRACK)*
    ;

primaryExp
    : LPAREN exp RPAREN
    | lVal
    | number
    ;

number
    : DEC_INT_CONST
    | OCT_INT_CONST
    | HEX_INT_CONST
    ;

unaryExp
    : primaryExp
    | IDENT LPAREN (funcRParams)? RPAREN
    | unaryOp unaryExp
    ;

unaryOp
    : PLUS
    | MINUS
    | NOT
    ;

funcRParams
    : exp (COMMA exp)*
    ;

mulExp
    : unaryExp
    | mulExp (MUL | DIV | MOD) unaryExp
    ;

addExp
    : mulExp
    | addExp (PLUS | MINUS) mulExp
    ;

relExp
    : addExp
    | relExp (LT | GT | LE | GE) addExp
    ;

eqExp
    : relExp
    | eqExp (EQ | NEQ) relExp
    ;

lAndExp
    : eqExp
    | lAndExp AND eqExp
    ;

lOrExp
    : lAndExp
    | lOrExp OR lAndExp
    ;

constExp
    : addExp
    ;