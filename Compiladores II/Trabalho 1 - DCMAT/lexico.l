%option noyywrap
%{
    #include <sintatico.tab.h>
    extern YYSTYPE ylval;
%}


%%

"+"                     { /* printf("PLUS "); */ return PLUS; }
"-"                     { /* printf("MINUS "); */ return MINUS; }
"*"                     { /* printf("MUL "); */ return MUL; }
"/"                     { /* printf("DIV "); */ return DIV; }
"^"                     { /* printf("EXP "); */ return EXP; }
"%"                     { /* printf("MOD "); */ return MOD; }
"("                     { /* printf("L_PAREN "); */ return L_PAREN; }
")"                     { /* printf("R_PAREN "); */ return R_PAREN; }
":="                    { /* printf("ATTRIB "); */ return ATTRIB; }
":"                     { /* printf("COLON "); */ return COLON; }
"="                     { /* printf("EQUALS "); */ return EQUALS; }
"["                     { /* printf("L_SQUARE_BRACKET "); */ return L_SQUARE_BRACKET; }
"]"                     { /* printf("R_SQUARE_BRACKET "); */ return R_SQUARE_BRACKET; }
";"                     { /* printf("SEMICOLON "); */ return SEMICOLON; }
","                     { /* printf("COMMA "); */ return COMMA; }
[0-9]+                  { /* printf("INT "); */ return INT; }
[0-9]+"."[0-9]+         { /* printf("REAL "); */ return REAL; }
about                   { /* printf("ABOUT "); */ return ABOUT; }
abs                     { /* printf("ABS "); */ return ABS; }
axis                    { /* printf("AXIS "); */ return AXIS; }
connect_dots            { /* printf("CONNECT_DOTS "); */ return CONNECT_DOTS; }
cos                     { /* printf("COS "); */ return COS; }
determinant             { /* printf("DETERMINANT "); */ return DETERMINANT; }
[eE]                    { /* printf("EULER "); */ return EULER; }
erase                   { /* printf("ERASE "); */ return ERASE; }
float                   { /* printf("FLOAT "); */ return FLOAT; }
h_view                  { /* printf("H_VIEW "); */ return H_VIEW; }
integral_steps          { /* printf("INTEGRAL_STEPS "); */ return INTEGRAL_STEPS; }
integrate               { /* printf("INTEGRATE "); */ return INTEGRATE; }
linear_system           { /* printf("LINEAR_SYSTEM "); */ return LINEAR_SYSTEM; }
matrix                  { /* printf("MATRIX "); */ return MATRIX; }
off                     { /* printf("OFF "); */ return OFF; }
on                      { /* printf("ON "); */ return ON; }
[pP][iI]                { /* printf("PI "); */ return PI; }
plot                    { /* printf("PLOT "); */ return PLOT; }
precision               { /* printf("PRECISION "); */ return PRECISION; }
quit                    { /* printf("QUIT "); */ return QUIT; }
reset                   { /* printf("RESET "); */ return RESET; }
rpn                     { /* printf("RPN "); */ return RPN; }
sen                     { /* printf("SIN "); */ return SIN; }
set                     { /* printf("SET "); */ return SET; }
settings                { /* printf("SETTINGS "); */ return SETTINGS; }
show                    { /* printf("SHOW "); */ return SHOW; }
solve                   { /* printf("SOLVE "); */ return SOLVE; }
sum                     { /* printf("SUM "); */ return SUM; }
symbols                 { /* printf("SYMBOLS "); */ return SYMBOLS; }
tan                     { /* printf("TAN "); */ return TAN; }
v_view                  { /* printf("V_VIEW "); */ return V_VIEW; }
[xX]                    { /* printf("X "); */ return X; }
[a-zA-Z]+[_0-9a-zA-Z]*  { /* printf("IDENTIFIER "); */ return IDENTIFIER; }
" "                     { /* Ignorar espaços */ }
"\n"                    { return NEW_LINE; }
.                       {printf("Invalid Symbol: %s", yytext);}

%%
