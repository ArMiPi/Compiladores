%option noyywrap
%{
    #include <string.h>
    int cont = -1;
%}
%%
"if" {if(++cont) printf("\n"); printf("if IF");}
[ ]+ {if(++cont) printf("\n"); printf("white space");}
[a-z]+[a-z0-9]* {if(++cont) printf("\n"); printf("%s ID", yytext);}
[0-9]+"."[0-9]* {if(++cont) printf("\n"); printf("%s REAL", yytext);}
[0-9]+ {if(++cont) printf("\n"); printf("%s NUM", yytext);}
"--"[a-z]+"\n" {if(++cont) printf("\n"); yytext[strlen(yytext)-1] = '\0'; printf("%s comment", yytext);}
[\n] { }
. {if(++cont) printf("\n"); printf("%s error", yytext);}
%%
int main(int argc, char** argv)
{
    yylex();
    return 0;
}