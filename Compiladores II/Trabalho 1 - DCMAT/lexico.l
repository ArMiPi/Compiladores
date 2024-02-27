%option noyywrap
%{
    #include <sintatico.tab.h>
    extern YYSTYPE ylval;
%}


%%

"+"                     { return PLUS; }
"-"                     { return MINUS; }
"*"                     { return MUL; }
"/"                     { return DIV; }
"^"                     { return EXP; }
"%"                     { return MOD; }
"("                     { return L_PAREN; }
")"                     { return R_PAREN; }
":="                    { return ATTRIB; }
":"                     { return COLON; }
"="                     { return EQUALS; }
"["                     { return L_SQUARE_BRACKET; }
"]"                     { return R_SQUARE_BRACKET; }
";"                     { return SEMICOLON; }
","                     { return COMMA; }
[0-9]+                  { yylval.str = strdup(yytext); return INT; }
[0-9]+"."[0-9]+         { yylval.str = strdup(yytext); return REAL; }
about                   { return ABOUT; }
abs                     { return ABS; }
axis                    { return AXIS; }
connect_dots            { return CONNECT_DOTS; }
cos                     { return COS; }
determinant             { return DETERMINANT; }
[eE]                    { return EULER; }
erase                   { return ERASE; }
float                   { return FLOAT; }
h_view                  { return H_VIEW; }
integral_steps          { return INTEGRAL_STEPS; }
integrate               { return INTEGRATE; }
linear_system           { return LINEAR_SYSTEM; }
matrix                  { return MATRIX; }
off                     { yylval.str = strdup(yytext); return OFF; }
on                      { yylval.str = strdup(yytext); return ON; }
[pP][iI]                { return PI; }
plot                    { return PLOT; }
precision               { return PRECISION; }
quit                    { return QUIT; }
reset                   { return RESET; }
rpn                     { return RPN; }
sen                     { return SIN; }
set                     { return SET; }
settings                { return SETTINGS; }
show                    { return SHOW; }
solve                   { return SOLVE; }
sum                     { return SUM; }
symbols                 { return SYMBOLS; }
tan                     { return TAN; }
v_view                  { return V_VIEW; }
[xX]                    { return X; }
[a-zA-Z]+[_0-9a-zA-Z]*  { yylval.str = strdup(yytext); return IDENTIFIER; }
" "                     { }
"\n"                    { return NEW_LINE; }
.                       {printf("Invalid Symbol: %s", yytext);}

%%
