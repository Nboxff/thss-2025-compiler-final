lexer grammar SysYLexer;

// Keywords
CONST : 'const';
INT : 'int';
VOID : 'void';
IF : 'if';
ELSE : 'else';
WHILE : 'while';
BREAK : 'break';
CONTINUE : 'continue';
RETURN : 'return';

// Operators
PLUS : '+';
MINUS : '-';
MUL : '*';
DIV : '/';
MOD : '%';
ASSIGN : '=';
EQ : '==';
NEQ : '!=';
LT : '<';
GT : '>';
LE : '<=';
GE : '>=';
NOT : '!';
AND : '&&';
OR : '||';

LPAREN : '(';
RPAREN : ')';
LBRACK : '[';
RBRACK : ']';
LBRACE : '{';
RBRACE : '}';
COMMA : ',';
SEMICOLON : ';';

// Literals
IDENT : [a-zA-Z_] [a-zA-Z0-9_]*;
DEC_INT_CONST : [1-9] [0-9]* | '0';
OCT_INT_CONST : '0' [0-7]+;
HEX_INT_CONST : '0' [xX] [0-9a-fA-F]+;

// Comments and Whitespace
WS : [ \t\r\n]+ -> skip;
LINE_COMMENT : '//' .*? '\r'? '\n' -> skip;
BLOCK_COMMENT : '/*' .*? '*/' -> skip;