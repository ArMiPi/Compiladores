%{
    #include "Settings.h"
    #include "SettingsOptionsManager.h"

    extern int yylex();
    extern char* yytext;

    void yyerror(char *s);

    Settings settings = Settings();
    SettingsOptionsManager optionsManager = SettingsOptionsManager();
%}

%code requires {
    #include <iostream>
    #include <cstring>
    #include <cstdlib>
}

%union {
    char *str;
    float f;
    int i;
    void *set_opt_man;
}

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
%token <i> INT
%token <f> REAL
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
%token NEW_LINE

%left PLUS MINUS
%left MUL DIV MOD
%left EXP

%start Programa

%type<str> ShowOptions Expr Number 
%type <f> MathConstants
%type<set_opt_man> SettingOptions

%%

Programa: Statement NEW_LINE { return 0; }
;

Statement: ABOUT SEMICOLON {
    std::cout << "\n+----------------------------------------------+";
    std::cout << "\n|                                              |";
    std::cout << "\n|     202000560023 - Arthur Miasato Pimont     |";
    std::cout << "\n|                                              |";
    std::cout << "\n+----------------------------------------------+\n\n";
}
    | IDENTIFIER AttribIdentifier SEMICOLON {}
    | INTEGRATE L_PAREN Number COLON Number COMMA Expr R_PAREN SEMICOLON {}
    | MATRIX EQUALS AttribMatrix SEMICOLON {}
    | PLOT AsFunc SEMICOLON {}
    | QUIT { return 1; }
    | RESET SETTINGS SEMICOLON {}
    | RPN L_PAREN Expr R_PAREN SEMICOLON {}
    | SET SettingOptions SEMICOLON { optionsManager.applyOptionChanges(settings); }
    | SHOW ShowOptions SEMICOLON {
        std::cout << $2;
        free($2);
    }
    | SOLVE SolveOptions SEMICOLON {}
    | SUM L_PAREN IDENTIFIER COMMA INT COLON INT COMMA Expr R_PAREN SEMICOLON {}
    | Expr {}
;

ShowOptions: SETTINGS { $$ = settings.printSettings(); }
    | MATRIX {}
    | SYMBOLS {}
;

SettingOptions: H_VIEW Expr COLON Expr {
        char option[7] = "h_view";

        char **values = (char **) malloc(2 * sizeof(char *));
        values[0] = (char *) malloc((30) * sizeof(char));
        values[1] = (char *) malloc((30) * sizeof(char));

        sprintf(values[0], "%s", $2);
        sprintf(values[1], "%s", $4);

        optionsManager.setOption(option);
        optionsManager.setValues(values);
    }
    | V_VIEW Expr COLON Expr {}
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

Number: INT { 
        char *c = (char *) malloc(100 * sizeof(char));

        sprintf(c, "%d", $1);
        $$ = c;
    }
    | REAL { 
        char *c = (char *) malloc(100 * sizeof(char));

        sprintf(c, "%f", $1);
        $$ = c; 
    }
    | MathConstants { 
        char *c = (char *) malloc(100 * sizeof(char));

        sprintf(c, "%f", $1);
        $$ = c;  
    }
;

MathConstants: PI { $$ = 3.14159265; }
    | EULER { $$ = 2.71828182; }
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

Expr: Number { $$ = $1; }
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
    | PLUS Expr {}
;

%%

void yyerror(char *s) {
    std::cout << "\n" << s << "\nERROR\n";
}

int main(int argc, char **argv) {
    std::cout << "> ";
    
    while(!yyparse()) {
        std::cout << "> ";
    }

    return 0;
}
