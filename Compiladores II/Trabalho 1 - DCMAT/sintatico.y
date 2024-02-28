%{
    #include "HashTable.h"
    #include "Matrix.h"
    #include "Settings.h"
    #include "SettingsOptionsManager.h"

    #include <iostream>
    #include <list>
    #include <cstring>

    extern int yylex();
    extern char* yytext;

    void yyerror(char *s);

    HashTable *hashTable = new HashTable();

    Settings *settings = new Settings();
    SettingsOptionsManager *optionsManager = new SettingsOptionsManager();
%}

%union {
    char *str;
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
%token <str> INT
%token <str> REAL
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
%token <str> OFF
%token <str> ON
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
%token <str> IDENTIFIER
%token NEW_LINE

%start Programa

%type<str>  ShowOptions Expr Number Value 
            Term Factor BoolOptions MathConstants
            AttribIdentifier DimensionsList
            NumbersList Dimensions AttribMatrix

%%

Programa: 
    Statement NEW_LINE { return 0; }
;

Statement: 
    ABOUT SEMICOLON {
        std::cout << "\n+----------------------------------------------+";
        std::cout << "\n|                                              |";
        std::cout << "\n|     202000560023 - Arthur Miasato Pimont     |";
        std::cout << "\n|                                              |";
        std::cout << "\n+----------------------------------------------+\n\n";
    }
    | IDENTIFIER AttribIdentifier SEMICOLON {}
    | INTEGRATE L_PAREN Number COLON Number COMMA Expr R_PAREN SEMICOLON {}
    | MATRIX EQUALS AttribMatrix SEMICOLON {
        Matrix *matrix =  new Matrix($3);
        
        std::cout << "'" << $3 << "'" << std::endl;   

        free($3);
    }
    | PLOT AsFunc SEMICOLON {}
    | QUIT { return 1; }
    | RESET SETTINGS SEMICOLON { settings->resetSettings(); }
    | RPN L_PAREN Expr R_PAREN SEMICOLON {}
    | SET SettingOptions SEMICOLON { optionsManager->applyOptionChanges(settings); }
    | SHOW ShowOptions SEMICOLON { std::cout << $2; free($2); }
    | SOLVE SolveOptions SEMICOLON {}
    | SUM L_PAREN IDENTIFIER COMMA INT COLON INT COMMA Expr R_PAREN SEMICOLON {}
    | Expr {}
;

ShowOptions: 
    SETTINGS { $$ = settings->printSettings(); }
    | MATRIX {}
    | SYMBOLS {}
;

SettingOptions: 
    H_VIEW Expr COLON Expr {
        char temp[] = "h_view";
        char *option = (char *) malloc((strlen(temp) + 1) * sizeof(char));

        char **values = (char **) malloc(3 * sizeof(char *));
        values[0] = (char *) malloc((strlen($2) + 1) * sizeof(char));
        values[1] = (char *) malloc((strlen($4) + 1) * sizeof(char));
        values[2] = nullptr;

        sprintf(option, "%s", temp);
        sprintf(values[0], "%s", $2);
        sprintf(values[1], "%s", $4);

        free($2);
        free($4);

        optionsManager->setOption(option);
        optionsManager->setValues(values);
    }
    | V_VIEW Expr COLON Expr {
        char temp[] = "v_view";
        char *option = (char *) malloc((strlen(temp) + 1) * sizeof(char));

        char **values = (char **) malloc(3 * sizeof(char *));
        values[0] = (char *) malloc((strlen($2) + 1) * sizeof(char));
        values[1] = (char *) malloc((strlen($4) + 1) * sizeof(char));
        values[2] = nullptr;

        sprintf(option, "%s", temp);
        sprintf(values[0], "%s", $2);
        sprintf(values[1], "%s", $4);

        free($2);
        free($4);

        optionsManager->setOption(option);
        optionsManager->setValues(values);
    }
    | AXIS BoolOptions { 
        char temp[] = "axis";
        char *option = (char *) malloc((strlen(temp) + 1) * sizeof(char));

        char **values = (char **) malloc(2 * sizeof(char *));
        values[0] = (char *) malloc((strlen($2) + 1) * sizeof(char));
        values[1] = nullptr;

        sprintf(option, "%s", temp);
        sprintf(values[0], "%s", $2);

        free($2);

        optionsManager->setOption(option);
        optionsManager->setValues(values);
    }
    | ERASE PLOT BoolOptions {
        char temp[] = "erase_plot";
        char *option = (char *) malloc((strlen(temp) + 1) * sizeof(char));

        char **values = (char **) malloc(2 * sizeof(char *));
        values[0] = (char *) malloc((strlen($3) + 1) * sizeof(char));
        values[1] = nullptr;

        sprintf(option, "%s", temp);
        sprintf(values[0], "%s", $3);

        free($3);

        optionsManager->setOption(option);
        optionsManager->setValues(values);
    }
    | INTEGRAL_STEPS INT {
        char temp[] = "integral_steps";
        char *option = (char *) malloc((strlen(temp) + 1) * sizeof(char));

        char **values = (char **) malloc(2 * sizeof(char *));
        values[0] = (char *) malloc((strlen($2) + 1) * sizeof(char));
        values[1] = nullptr;

        sprintf(option, "%s", temp);
        sprintf(values[0], "%s", $2);

        free($2);

        optionsManager->setOption(option);
        optionsManager->setValues(values);
    }
    | FLOAT PRECISION INT {
        char temp[] = "float_precision";
        char *option = (char *) malloc((strlen(temp) + 1) * sizeof(char));

        char **values = (char **) malloc(2 * sizeof(char *));
        values[0] = (char *) malloc((strlen($3) + 1) * sizeof(char));
        values[1] = nullptr;

        sprintf(option, "%s", temp);
        sprintf(values[0], "%s", $3);

        free($3);

        optionsManager->setOption(option);
        optionsManager->setValues(values);
    }
    | CONNECT_DOTS BoolOptions {
        char temp[] = "connect_dots";
        char *option = (char *) malloc((strlen(temp) + 1) * sizeof(char));

        char **values = (char **) malloc(2 * sizeof(char *));
        values[0] = (char *) malloc((strlen($2) + 1) * sizeof(char));
        values[1] = nullptr;

        sprintf(option, "%s", temp);
        sprintf(values[0], "%s", $2);

        free($2);

        optionsManager->setOption(option);
        optionsManager->setValues(values);
    }
;

BoolOptions: 
    ON { $$ = $1; }
    | OFF { $$ = $1; }
;

AsFunc: 
    L_PAREN Expr R_PAREN {}
    | {}
;

AttribMatrix: 
    L_SQUARE_BRACKET DimensionsList R_SQUARE_BRACKET { $$ = $2; }
;

Dimensions: 
    L_SQUARE_BRACKET NumbersList R_SQUARE_BRACKET { $$ = $2; }
;

NumbersList:
    Number { $$ = $1; }
    | MINUS Number { 
        char *numb = (char *) malloc((sizeof($2) + 1) * sizeof(char));

        sprintf(numb, "-%s", $2);

        free($2);

        $$ = numb;
    }
    | NumbersList COMMA Number {
        char *numbers = (char *) malloc((strlen($1) + strlen($3) + 2) * sizeof(char));

        sprintf(numbers, "%s %s", $1, $3);

        free($1);
        free($3);

        $$ = numbers;
    }
    | NumbersList COMMA MINUS Number {
        char *numbers = (char *) malloc((strlen($1) + strlen($4) + 3) * sizeof(char));

        sprintf(numbers, "%s -%s", $1, $4);

        free($1);
        free($4);

        $$ = numbers;
    }
;

DimensionsList: 
    Dimensions {}
    | DimensionsList COMMA Dimensions {
        char *dims = (char *) malloc((strlen($1) + strlen($3) + 4) * sizeof(char));

        sprintf(dims, "%s | %s", $1, $3);

        free($1);
        free($3);

        $$ = dims;
    }
;

Number: 
    INT { $$ = $1; }
    | REAL { $$ = $1; }
    | MathConstants { $$ = $1; }
;

MathConstants: 
    PI { 
        char temp[] = "3.14159265";

        char *pi = (char *) malloc((strlen(temp) + 1) * sizeof(char));

        sprintf(pi, "%s", temp);

        $$ = pi; 
    }
    | EULER { 
        char temp[] = "2.71828182";

        char *euler = (char *) malloc((strlen(temp) + 1) * sizeof(char));

        sprintf(euler, "%s", temp);

        $$ = euler;
    }
;

SolveOptions: 
    DETERMINANT {}
    | LINEAR_SYSTEM {}
;

AttribIdentifier: 
    ATTRIB Expr { $$ = $2; }
    | ATTRIB AttribMatrix {}
    | {}
;

Function: 
    ABS L_PAREN Expr R_PAREN {}
    | COS L_PAREN Expr R_PAREN {}
    | SIN L_PAREN Expr R_PAREN {}
    | TAN L_PAREN Expr R_PAREN {}
;

Expr: 
    Factor { $$ = $1; }
    | Expr PLUS Factor {}
    | Expr MINUS Factor {}
    | L_PAREN Expr R_PAREN {}
;

Factor:
    Term { $$ = $1; }
    | Factor MUL Term {}
    | Factor DIV Term {}
;

Term:
    Value { $$ = $1; }
    | Term EXP Value {}
    | Term MOD Value {}
;

Value:
    Number { $$ = $1; }
    | Function {}
    | IDENTIFIER { $$ = $1; }
    | X {}
    | MINUS Value { 
        char *c = (char *) malloc((strlen($2) + 1) * sizeof(char));

        sprintf(c, "-%s", $2);

        free($2);

        $$ = c;
    }
    | PLUS Value { $$ = $2; }
;

%%

void yyerror(char *s) {
    std::cout << "\n" << s << "\nERROR\n";
}

int main(int argc, char **argv) {
    std::cout << ">";
    
    while(!yyparse()) {
        std::cout << ">";
    }

    return 0;
}
