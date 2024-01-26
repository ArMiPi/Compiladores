%option noyywrap
%{
    int cont = -1;
%}
%%
[a-z]+[a-z0-9]* {if(++cont) printf("\n"); printf("%s", yytext);}
(0-9)+"e"((0-9)+|[+-](0-9)+) {if(++cont) printf("\n"); printf("%s", yytext);}
[0-9]+ {if(++cont) printf("\n"); printf("%s", yytext);}
[+] {if(++cont) printf("\n"); printf("+");}
[-] {if(++cont) printf("\n"); printf("-");}
[\n] { }
. {if(++cont) printf("\n"); printf("ERRO");}
%%
int main(int argc, char** argv)
{
    yylex();
    return 0;
}