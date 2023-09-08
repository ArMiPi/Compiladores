%option noyywrap
%{
    #include <string.h>
    int cont = -1;
%}
%%
(aba)+ {if(++cont) printf("\n"); printf("action 1");}
(a(b*)a) {if(++cont) printf("\n"); printf("action 2");}
(a|b) {if(++cont) printf("\n"); printf("action 3");}
. { }
%%
int main(int argc, char** argv)
{
    yylex();
    return 0;
}