%{
    #include "HashTable.h"
    #include "Matrix.h"
    #include "Settings.h"
    #include "SettingsOptionsManager.h"
    #include "StringUtils.h"
    #include "Math.h"

    #include <iostream>
    #include <cstring>
    #include <sstream>
    #include <vector>
    #include <string>

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
%token <str> X
%token <str> IDENTIFIER
%token NEW_LINE

%start Programa

%type<str>  ShowOptions Expr Number Value 
            Term Factor BoolOptions MathConstants
            AttribIdentifier DimensionsList
            NumbersList Dimensions AttribMatrix
            SolveOptions Function

%%

Programa: 
    Statement NEW_LINE { return 0; }
    | NEW_LINE { return 0; }
;

Statement: 
    ABOUT SEMICOLON {
        std::cout << "\n+----------------------------------------------+";
        std::cout << "\n|                                              |";
        std::cout << "\n|     202000560023 - Arthur Miasato Pimont     |";
        std::cout << "\n|                                              |";
        std::cout << "\n+----------------------------------------------+\n\n";
    }
    | IDENTIFIER AttribIdentifier SEMICOLON {
        if(!$2) {
            /* Obter identificador da hashTable */
            HashItem *it = hashTable->get($1);

            if(!it) {
                std::cout << std::endl;
                std::cout << "Undefined symbol" << std::endl;
                std::cout << std::endl;
            } else {
                if(std::string(hashTable->getHItemType(it)).compare("matrix") == 0) {
                    Matrix *m = (Matrix *) hashTable->getHItemValue(it);
                    char *mat = m->asString(settings->getFloatPrecision());

                    std::cout << mat;

                    free(mat);
                } else {
                    char *value = (char *) hashTable->getHItemValue(it);

                    std::cout << std::endl;
                    std::cout << $1 << " = " << value << std::endl;
                    std::cout << std::endl;
                }
            }
            free($1);
        } else {
            std::string str($2);
            std::vector<std::string> input = split(str, "->");

            if(input[0].compare("FLOAT") == 0) {
                std::string tp = "float";
                char *type = (char *) malloc((tp.size() + 1) * sizeof(char));
                sprintf(type, "%s", tp.data());

                char *value = solveRpn(input[1].data(), hashTable, settings->getFloatPrecision());

                hashTable->insert($1, type, value);

                std::cout << std::endl;
                std::cout << value << std::endl;
                std::cout << std::endl;
            } else {
                Matrix *m = new Matrix(input[1].data());
                std::string tp = "matrix";
                char *type = (char *) malloc((tp.size() + 1) * sizeof(char));
                sprintf(type, "%s", tp.data());

                hashTable->insert($1, type, m);

                char *mstr = m->asString(settings->getFloatPrecision());

                std::cout << mstr;

                free(mstr);
            }

            free($2);
        }
    }
    | INTEGRATE L_PAREN Number COLON Number COMMA Expr R_PAREN SEMICOLON {}
    | MATRIX EQUALS AttribMatrix SEMICOLON {
        Matrix *matrix =  new Matrix($3);
        
        char *key = (char *) malloc((strlen("matrix") + 1) * sizeof(char));
        sprintf(key, "matrix");

        hashTable->insert(key, key, matrix);  

        free($3);
    }
    | PLOT AsFunc SEMICOLON {}
    | QUIT { return 1; }
    | RESET SETTINGS SEMICOLON { settings->resetSettings(); }
    | RPN L_PAREN Expr R_PAREN SEMICOLON { 
        std::cout << std::endl;
        std::cout << "Expression in RPN format:" << std::endl;
        std::cout << std::endl;
        std::cout << $3 << std::endl;
        std::cout << std::endl;

        free($3);
    }
    | SET SettingOptions SEMICOLON { optionsManager->applyOptionChanges(settings); }
    | SHOW ShowOptions SEMICOLON { std::cout << $2; free($2); }
    | SOLVE SolveOptions SEMICOLON { std::cout << std::endl << $2; free($2); }
    | SUM L_PAREN IDENTIFIER COMMA INT COLON INT COMMA Expr R_PAREN SEMICOLON {}
    | Expr {
        char *value = solveRpn($1, hashTable, settings->getFloatPrecision());

        std::cout << std::endl;
        std::cout << value << std::endl;
        std::cout << std::endl;

        free(value);
        free($1);
    }
;

ShowOptions: 
    SETTINGS { $$ = settings->printSettings(); }
    | MATRIX { 
        char *key = (char *) malloc((strlen("matrix") + 1) * sizeof(char));
        sprintf(key, "matrix");

        Matrix *m = (Matrix *) hashTable->getHItemValue(hashTable->get(key));

        free(key);

        if(!m) {
            char *err = (char *) malloc((strlen("\nNo Matrix defined!\n\n") + 1) * sizeof(char));

            sprintf(err, "\nNo Matrix defined!\n\n");

            $$ = err;
        } else {
            $$ = m->asString(settings->getFloatPrecision());
        }
    }
    | SYMBOLS {
        std::stringstream ss;
        
        ss << std::endl;

        std::vector<std::string> keys = hashTable->getKeys();

        char *type;
        HashItem *it;
        for(int i = 0; i < keys.size(); i++) {
            it = hashTable->get(keys[i].data());

            if(std::string(hashTable->getHItemType(it)).compare("matrix") == 0) {
                Matrix *m = (Matrix *) hashTable->getHItemValue(it);

                ss << keys[i] << " - MATRIX [" << m->getNLines() << "] [" << m->getNCols() << "]" << std::endl;
            } else {
                ss << keys[i] << " - FLOAT" << std::endl;
            }
        }

        ss << std::endl;

        char *c = (char *) malloc((ss.str().size() + 1) * sizeof(char));
        sprintf(c, "%s", ss.str().data());

        $$ = c;
    }
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
    INT { 
        std::stringstream ss;
        ss.precision(settings->getFloatPrecision());

        ss << std::fixed << atof($1);

        char *c = (char *) malloc((ss.str().size() + 1) * sizeof(char));
        sprintf(c, "%s", ss.str().data());

        free($1);

        $$ = c; 
    }
    | REAL { 
        std::stringstream ss;
        ss.precision(settings->getFloatPrecision());

        ss << std::fixed << atof($1);

        char *c = (char *) malloc((ss.str().size() + 1) * sizeof(char));
        sprintf(c, "%s", ss.str().data());

        free($1);

        $$ = c; 
    }
    | MathConstants { 
        $$ = $1; 
    }
;

MathConstants: 
    PI { 
        std::stringstream ss;
        ss.precision(settings->getFloatPrecision());

        ss << std::fixed << 3.14159265;

        char *pi = (char *) malloc((ss.str().size() + 1) * sizeof(char));

        sprintf(pi, "%s", ss.str().data());

        $$ = pi; 
    }
    | EULER { 
        std::stringstream ss;
        ss.precision(settings->getFloatPrecision());

        ss << std::fixed << 2.71828182;

        char *euler = (char *) malloc((ss.str().size() + 1) * sizeof(char));

        sprintf(euler, "%s", ss.str().data());

        $$ = euler; 
    }
;

SolveOptions: 
    DETERMINANT {
        char *key = (char *) malloc((strlen("matrix") + 1) * sizeof(char));
        sprintf(key, "matrix");

        Matrix *m = (Matrix *) hashTable->getHItemValue(hashTable->get(key));

        free(key);

        $$ = m->determinant(settings->getFloatPrecision());
    }
    | LINEAR_SYSTEM {}
;

AttribIdentifier: 
    ATTRIB Expr { 
        std::stringstream ss;

        ss << "FLOAT->" << $2;

        char *c = (char *) malloc((ss.str().size() + 1) * sizeof(char));
        sprintf(c, "%s", ss.str().data());

        free($2);

        $$ = c; 
    }
    | ATTRIB AttribMatrix { 
        std::stringstream ss;

        ss << "MATRIX->" << $2;

        char *c = (char *) malloc((ss.str().size() + 1) * sizeof(char));
        sprintf(c, "%s", ss.str().data());

        free($2);

        $$ = c; 
    }
    | { $$ = nullptr; }
;

Function: 
    ABS L_PAREN Expr R_PAREN {
        char func[] = "ABS";
        char *c = (char *) malloc((sizeof($3) + strlen(func) + 2) * sizeof(char));

        sprintf(c, "%s %s", $3, func);

        free($3);

        $$ = c;
    }
    | COS L_PAREN Expr R_PAREN {
        char func[] = "COS";
        char *c = (char *) malloc((sizeof($3) + strlen(func) + 2) * sizeof(char));

        sprintf(c, "%s %s", $3, func);

        free($3);

        $$ = c;
    }
    | SIN L_PAREN Expr R_PAREN {
        char func[] = "SEN";
        char *c = (char *) malloc((sizeof($3) + strlen(func) + 2) * sizeof(char));

        sprintf(c, "%s %s", $3, func);

        free($3);

        $$ = c;
    }
    | TAN L_PAREN Expr R_PAREN {
        char func[] = "TAN";
        char *c = (char *) malloc((sizeof($3) + strlen(func) + 2) * sizeof(char));

        sprintf(c, "%s %s", $3, func);

        free($3);

        $$ = c;
    }
;

Expr: 
    Factor { $$ = $1; }
    | Expr PLUS Factor {
        char *c = (char *) malloc((strlen($1) + strlen($3) + 4) * sizeof(char));
        sprintf(c, "%s %s +", $1, $3);

        free($1);
        free($3);

        $$ = c;
    }
    | Expr MINUS Factor {
        char *c = (char *) malloc((strlen($1) + strlen($3) + 4) * sizeof(char));
        sprintf(c, "%s %s -", $1, $3);

        free($1);
        free($3);

        $$ = c;
    }
;

Factor:
    Term { $$ = $1; }
    | Factor MUL Term {
        char *c = (char *) malloc((strlen($1) + strlen($3) + 4) * sizeof(char));
        sprintf(c, "%s %s *", $1, $3);

        free($1);
        free($3);

        $$ = c;
    }
    | Factor DIV Term {
        char *c = (char *) malloc((strlen($1) + strlen($3) + 4) * sizeof(char));
        sprintf(c, "%s %s /", $1, $3);

        free($1);
        free($3);

        $$ = c;
    }
    | Factor MOD Term {
        char *c = (char *) malloc((strlen($1) + strlen($3) + 4) * sizeof(char));
        sprintf(c, "%s %s %%", $1, $3);

        free($1);
        free($3);

        $$ = c;
    }
;

Term:
    Value { $$ = $1; }
    | Term EXP Value {
        char *c = (char *) malloc((strlen($1) + strlen($3) + 4) * sizeof(char));
        sprintf(c, "%s %s ^", $1, $3);

        free($1);
        free($3);

        $$ = c;
    }
;

Value:
    Number { $$ = $1; }
    | Function { $$ = $1; }
    | IDENTIFIER { $$ = $1; }
    | X { $$ = $1; }
    | MINUS Value { 
        char *c = (char *) malloc((strlen($2) + 1) * sizeof(char));

        sprintf(c, "-%s", $2);

        free($2);

        $$ = c;
    }
    | PLUS Value { $$ = $2; }
    | L_PAREN Expr R_PAREN { $$ = $2; }
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
