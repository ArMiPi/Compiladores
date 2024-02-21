%option noyywrap

%%

"+"                     {printf("PLUS");}
"-"                     {printf("MINUS");}
"*"                     {printf("MUL");}
"/"                     {printf("DIV");}
"^"                     {printf("EXP");}
"%"                     {printf("MOD");}
"("                     {printf("L_PAREN");}
")"                     {printf("R_PAREN");}
":="                    {printf("ATTRIB");}
":"                     {printf("COLON");}
"="                     {printf("EQUALS");}
"["                     {printf("L_SQUARE_BRACKET");}
"]"                     {printf("R_SQUARE_BRACKET");}
";"                     {printf("SEMICOLON");}
","                     {printf("COMMA");}
[0-9]+                  {printf("INT");}
[0-9]+"."[0-9]+         {printf("REAL");}
about                   {printf("ABOUT");}
abs                     {printf("ABS");}
axis                    {printf("AXIS");}
connect_dots            {printf("CONNECT_DOTS");}
cos                     {printf("COS");}
determinant             {printf("DETERMINANT");}
[eE]                    {printf("EULER");}
erase                   {printf("ERASE");}
float                   {printf("FLOAT");}
h_view                  {printf("H_VIEW");}
integral_steps          {printf("INTEGRAL_STEPS");}
integrate               {printf("INTEGRATE");}
linear_system           {printf("LINEAR_SYSTEM");}
matrix                  {printf("MATRIX");}
off                     {printf("OFF");}
on                      {printf("ON");}
[pP][iI]                {printf("PI");}
plot                    {printf("PLOT");}
precision               {printf("PRECISION");}
quit                    {printf("QUIT");}
reset                   {printf("RESET");}
rpn                     {printf("RPN");}
sen                     {printf("SIN");}
set                     {printf("SET");}
settings                {printf("SETTINGS");}
show                    {printf("SHOW");}
solve                   {printf("SOLVE");}
sum                     {printf("SUM");}
symbols                 {printf("SYMBOLS");}
tan                     {printf("TAN");}
v_view                  {printf("V_VIEW");}
[xX]                    {printf("X");}
[a-zA-Z]+[_0-9a-zA-Z]*  {printf("IDENTIFIER");}
" "                     {}
.                       {printf("Invalid Symbol: %s", yytext);}

%%

int main() {
    yylex();

    return 0;
}
