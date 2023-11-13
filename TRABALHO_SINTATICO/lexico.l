%option noyywrap
%{
    #include <sintatico.tab.h>
    extern YYSTYPE yylval;

    int cont = -1;
    int linha = 1;
    int coluna = 1;
    int max_size = 255;
%}

%%

void    { coluna += yyleng; return VOID; }
int     { coluna += yyleng; return INT; }
char    { coluna += yyleng; return CHAR; }
return  { coluna += yyleng; return RETURN; }
break   { coluna += yyleng; return BREAK; }
switch  { coluna += yyleng; return SWITCH; }
case    { coluna += yyleng; return CASE; }
default { coluna += yyleng; return DEFAULT; }
do      { coluna += yyleng; return DO; }
while   { coluna += yyleng; return WHILE; }
for     { coluna += yyleng; return FOR; }
if      { coluna += yyleng; return IF; }
else    { coluna += yyleng; return ELSE; }
typedef { coluna += yyleng; return TYPEDEF; }
struct  { coluna += yyleng; return STRUCT; }
"+"     { coluna += yyleng; return PLUS; }
"-"     { coluna += yyleng; return MINUS; }
"*"     { coluna += yyleng; return MULTIPLY; }
("//".*\n) { linha++; coluna = 1; }
"/*" {
    int lin = linha;
    int col = coluna;

    coluna += 2;

    int asterisk = 0;
    int slash = 0;

    char c;

    while(1) {
        c = input();
        coluna++;

        if(c == '/') {
            // Checar se */
            if(asterisk) break;

            slash = 1;
        } else if(c == '*') {
            asterisk = 1;
        } else if(c == '\0') {
            if(++cont) printf("\n");
            printf("error:lexical:%d:%d: unterminated comment", lin, col);
            exit(0);
        } else {
            if(asterisk && slash) {
                if(++cont) printf("\n");
                printf("warning:%d:%d: '/*' within block comment", linha, coluna-3);
            }

            if(c == '\n') {
                linha++;
                coluna = 1;
            }

            asterisk = 0;
            slash = 0;
        }
    }
}
"/"         { coluna += yyleng; return DIV; }
%           { coluna += yyleng; return REMAINDER; }
"++"        { coluna += yyleng; return INC; }
"--"        { coluna += yyleng; return DEC; }
"&"         { coluna += yyleng; return BITWISE_AND; }
"|"         { coluna += yyleng; return BITWISE_OR; }
"~"         { coluna += yyleng; return BITWISE_NOT; }
"^"         { coluna += yyleng; return BITWISE_XOR; }
"!"         { coluna += yyleng; return NOT; }
"&&"        { coluna += yyleng; return LOGICAL_AND; }
"||"        { coluna += yyleng; return LOGICAL_OR; }
"=="        { coluna += yyleng; return EQUAL; }
"!="        { coluna += yyleng; return NOT_EQUAL; }
"<"         { coluna += yyleng; return LESS_THAN; }
">"         { coluna += yyleng; return GREATER_THAN; }
"<="        { coluna += yyleng; return LESS_EQUAL; }
">="        { coluna += yyleng; return GREATER_EQUAL; }
">>"        { coluna += yyleng; return R_SHIFT; }
"<<"        { coluna += yyleng; return L_SHIFT; }
"="         { coluna += yyleng; return ASSIGN; }
"+="        { coluna += yyleng; return ADD_ASSIGN; }
"-="        { coluna += yyleng; return MINUS_ASSIGN; }
";"         { coluna += yyleng; return SEMICOLON; }
","         { coluna += yyleng; return COMMA; }
":"         { coluna += yyleng; return COLON; }
"("         { coluna += yyleng; return L_PAREN; }
")"         { coluna += yyleng; return R_PAREN; }
"{"         { coluna += yyleng; return L_CURLY_BRACKET; }
"}"         { coluna += yyleng; return R_CURLY_BRACKET; }
"["         { coluna += yyleng; return L_SQUARE_BRACKET; }
"]"         { coluna += yyleng; return R_SQUARE_BRACKET; }
"?"         { coluna += yyleng; return TERNARY_CONDITIONAL; }
"#"         { coluna += yyleng; return NUMBER_SIGN; }
->          { coluna += yyleng; return POINTER; }
printf      { coluna += yyleng; return PRINTF; }
scanf       { coluna += yyleng; return SCANF; }
define      { coluna += yyleng; return DEFINE; }
exit        { coluna += yyleng; return EXIT; }
0[1-7][0-7]*        { coluna += yyleng; return NUM_OCTAL; }
0[xX][0-9A-Fa-f]+   { coluna += yyleng; return NUM_HEXA; }
[0-9]+              { coluna += yyleng; return NUM_INTEGER; }
\'(\\.|.)\' {
    int size = yyleng;
    char *str = yytext + 1;
    str[size-2] = '\0';

    coluna += yyleng;

    return CHARACTER;
}
\"(\\.|[^\"])*\" {
    int size = yyleng;
    char *str = yytext + 1;
    str[size-2] = '\0';

    coluna += yyleng;

    return STRING;
}
[_a-zA-Z][a-zA-Z0-9_]* {
    if(yyleng > max_size) {
        if(++cont) printf("\n");
        printf("error:lexical:%d:%d: identifier too long", linha, coluna);
        exit(0);
    }
    
    coluna += yyleng;
    
    return IDENTIFIER;
}
[ ]+ { coluna+= yyleng; }
\n { linha++; coluna = 1; }
. {
    if(++cont) printf("\n");
    printf("error:lexical:%d:%d: %s", linha, coluna, yytext);
    exit(0);
}

%%
