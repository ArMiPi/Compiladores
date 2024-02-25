%{
    #include <stdio.h>

    extern int yylex();
    extern char* yytext;

    void yyerror(char *s);
%}

%token PLUS
%token MINUS
%token MUL
%token DIV
%token EXP
%token MOD
%token L_PAREN
%token R_PAREN
%token ATTRIB
%token COLON
%token EQUALS
%token L_SQUARE_BRACKET
%token R_SQUARE_BRACKET
%token SEMICOLON
%token COMMA
%token INT
%token REAL
%token ABOUT
%token ABS
%token AXIS
%token CONNECT_DOTS
%token COS
%token DETERMINANT
%token EULER
%token ERASE
%token FLOAT
%token H_VIEW
%token INTEGRAL_STEPS
%token INTEGRATE
%token LINEAR_SYSTEM
%token MATRIX
%token OFF
%token ON
%token PI
%token PLOT
%token PRECISION
%token QUIT
%token RESET
%token RPN
%token SIN
%token SET
%token SETTINGS
%token SHOW
%token SOLVE
%token SUM
%token SYMBOLS
%token TAN
%token V_VIEW
%token X
%token IDENTIFIER
%token LEXICAL_ERROR
%token NEW_LINE

%left PLUS MINUS
%left MUL DIV MOD
%left EXP

%start Programa

%%

Programa: Statement NEW_LINE { return 0; }
;

Statement: ABOUT SEMICOLON {}
    | IDENTIFIER AttribIdentifier SEMICOLON {}
    | INTEGRATE L_PAREN Number COLON Number COMMA Expr R_PAREN SEMICOLON {}
    | MATRIX EQUALS AttribMatrix SEMICOLON {}
    | PLOT AsFunc SEMICOLON {}
    | QUIT { return 1; }
    | RESET SETTINGS SEMICOLON {}
    | RPN L_PAREN Expr R_PAREN SEMICOLON {}
    | SET SettingOptions SEMICOLON {}
    | SHOW ShowOptions SEMICOLON {}
    | SOLVE SolveOptions SEMICOLON {}
    | SUM L_PAREN IDENTIFIER COMMA INT COLON INT COMMA Expr R_PAREN SEMICOLON {}
    | Expr {}
;

ShowOptions: SETTINGS {}
    | MATRIX {}
    | SYMBOLS {}
;

SettingOptions: H_VIEW REAL COLON REAL {}
    | V_VIEW REAL COLON REAL {}
    | AXIS BoolOptions {}
    | ERASE PLOT BoolOptions {}
    | INTEGRAL_STEPS INT {}
    | FLOAT PRECISION INT {}
    | CONNECT_DOTS BoolOptions {}
;

BoolOptions: ON {}
    | OFF {}
;

AsFunc: L_PAREN Expr R_PAREN {}
    | {}
;

AttribMatrix: L_SQUARE_BRACKET Dimensions DimensionsList R_SQUARE_BRACKET {}
;

Dimensions: L_SQUARE_BRACKET Number NumbersList R_SQUARE_BRACKET {}
;

NumbersList: COMMA Number NumbersList
    | {}
;

DimensionsList: COMMA Dimensions DimensionsList {}
    | {}
;

Number: INT {}
    | REAL {}
    | MathConstants {}
;

MathConstants: PI {}
    | EULER {}
;

SolveOptions: DETERMINANT {}
    | LINEAR_SYSTEM {}
;

AttribIdentifier: ATTRIB Expr {}
    | ATTRIB AttribMatrix {}
    | {}
;

Function: ABS L_PAREN Expr R_PAREN {}
    | COS L_PAREN Expr R_PAREN {}
    | SIN L_PAREN Expr R_PAREN {}
    | TAN L_PAREN Expr R_PAREN {}
;

Expr: Number {}
    | Function {}
    | IDENTIFIER {}
    | X {}
    | L_PAREN Expr R_PAREN {}
    | Expr PLUS Expr {}
    | Expr MINUS Expr {}
    | Expr MUL Expr {}
    | Expr DIV Expr {}
    | Expr EXP Expr {}
    | Expr MOD Expr {}
    | MINUS Expr {}
;

%%

void yyerror(char *s) {
    printf("\n%s\nERROR\n", s);
}

int main(int argc, char **argv) {
    printf("> ");
    
    while(!yyparse()) {
        printf("\n> ");
    }

    return 0;
}
