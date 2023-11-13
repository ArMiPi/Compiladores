%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
extern int yylex();
extern char* yytext;
extern int linha;
extern int coluna;
extern int cont;
extern char* currentLine;
void yyerror(char *s);

%}

/* declare tokens */
%token VOID
%token INT
%token CHAR
%token RETURN
%token BREAK
%token SWITCH
%token CASE
%token DEFAULT
%token DO
%token WHILE
%token FOR
%token IF
%token ELSE
%token TYPEDEF
%token STRUCT
%token PLUS
%token MINUS
%token MULTIPLY
%token DIV
%token REMAINDER
%token INC
%token DEC
%token BITWISE_AND
%token BITWISE_OR
%token BITWISE_NOT
%token BITWISE_XOR
%token NOT
%token LOGICAL_AND
%token LOGICAL_OR
%token EQUAL
%token NOT_EQUAL
%token LESS_THAN
%token GREATER_THAN
%token LESS_EQUAL
%token GREATER_EQUAL
%token R_SHIFT
%token L_SHIFT
%token ASSIGN
%token ADD_ASSIGN
%token MINUS_ASSIGN
%token SEMICOLON
%token COMMA
%token COLON
%token L_PAREN
%token R_PAREN
%token L_CURLY_BRACKET
%token R_CURLY_BRACKET
%token L_SQUARE_BRACKET
%token R_SQUARE_BRACKET
%token TERNARY_CONDITIONAL
%token NUMBER_SIGN
%token POINTER
%token PRINTF
%token SCANF
%token DEFINE
%token EXIT
%token NUM_OCTAL
%token NUM_HEXA
%token NUM_INTEGER
%token CHARACTER
%token STRING
%token IDENTIFIER
%token OTHER

%start Programa

%%

Programa: DeclaracoesFuncao DeclaracoesFuncaoPrime {}
;

DeclaracoesFuncao: Declaracoes {}
	| Funcao {}
;

DeclaracoesFuncaoPrime: DeclaracoesFuncao DeclaracoesFuncaoPrime {}
	| {}
;

Declaracoes: NUMBER_SIGN DEFINE IDENTIFIER Expressao {}
	| DeclaracaoVariaveis {}
	| DeclaracaoPrototipo {}
;

Funcao: Tipo PointerIter IDENTIFIER Parametros L_CURLY_BRACKET FuncaoIter Comandos R_CURLY_BRACKET {}
;

PointerIter: MULTIPLY PointerIter {}
	| {}
;

FuncaoIter: DeclaracaoVariaveis FuncaoIter {}
	| {}
;

DeclaracaoVariaveis: Tipo DeclaracaoVariaveisIter SEMICOLON {}
;

DeclaracaoVariaveisIter: PointerIter IDENTIFIER ExpressaoIter DeclaracaoVariaveisAtribuicao DeclaracaoVariaveisIterPrime {}
;

ExpressaoIter: L_SQUARE_BRACKET Expressao R_SQUARE_BRACKET ExpressaoIter {}
	| {}
;

DeclaracaoVariaveisAtribuicao: ASSIGN ExpressaoAtribuicao {}
	| {}
;

DeclaracaoVariaveisIterPrime: COMMA DeclaracaoVariaveisIter {}
	| {}
;

DeclaracaoPrototipo: Tipo PointerIter IDENTIFIER Parametros SEMICOLON {}
;

Parametros: L_PAREN ParametrosOpIter R_PAREN {}
;

ParametrosOpIter: ParametrosIter {}
	| {}
;

ParametrosIter: Tipo PointerIter IDENTIFIER ExpressaoIter ParametrosIterPrime {}
;

ParametrosIterPrime: COMMA ParametrosIter {}
	| {}
;

Tipo: INT {}
	| CHAR {}
	| VOID {}
;

Bloco: L_CURLY_BRACKET Comandos R_CURLY_BRACKET {}
;

Comandos: ListaComandos ComandosPrime {}
;

ComandosPrime: ListaComandos ComandosPrime {}
	| {}
;

ListaComandos: DO Bloco WHILE L_PAREN Expressao R_PAREN SEMICOLON {}
	| IF L_PAREN Expressao R_PAREN Bloco OpElse {}
	| WHILE L_PAREN Expressao R_PAREN Bloco {}
	| FOR L_PAREN OpExpressao SEMICOLON OpExpressao SEMICOLON OpExpressao R_PAREN Bloco {}
	| PRINTF L_PAREN STRING OpVirgulaExpressao R_PAREN SEMICOLON {}
	| SCANF L_PAREN STRING COMMA BITWISE_AND IDENTIFIER R_PAREN SEMICOLON {}
	| EXIT L_PAREN Expressao R_PAREN SEMICOLON {}
	| RETURN OpExpressao SEMICOLON {}
	| Expressao SEMICOLON {}
	| SEMICOLON {}
	| Bloco {}
;

OpElse: ELSE Bloco {}
	| {}
;

OpExpressao: Expressao {}
	| {}
;

OpVirgulaExpressao: COMMA Expressao {}
	| {}
;

Expressao: ExpressaoAtribuicao ExpressaoPrime {}
;

ExpressaoPrime: COMMA Expressao {}
	| {}
;

ExpressaoAtribuicao: ExpressaoCondicional {}
	| ExpressaoUnaria AtribuicaoOperador ExpressaoAtribuicao {}
;

AtribuicaoOperador: ASSIGN {}
	| ADD_ASSIGN {}
	| MINUS_ASSIGN {}
;

ExpressaoCondicional: ExpressaoOrLogico ExpressaoCondicionalPrime {}
;

ExpressaoCondicionalPrime: TERNARY_CONDITIONAL Expressao COLON ExpressaoCondicional {}
	| {}
;

ExpressaoOrLogico: ExpressaoAndLogico ExpressaoOrLogicoPrime {}
;

ExpressaoOrLogicoPrime: LOGICAL_OR ExpressaoOrLogico {}
	| {}
;

ExpressaoAndLogico: ExpressaoOr ExpressaoAndLogicoPrime {}
;

ExpressaoAndLogicoPrime: LOGICAL_AND ExpressaoAndLogico {}
	| {}
;

ExpressaoOr: ExpressaoXor ExpressaoOrPrime {}
;

ExpressaoOrPrime: BITWISE_OR ExpressaoOr {}
	| {}
;

ExpressaoXor: ExpressaoAnd ExpressaoXorPrime {}
;

ExpressaoXorPrime: BITWISE_XOR ExpressaoXor {}
	| {}
;

ExpressaoAnd: ExpressaoIgualdade ExpressaoAndPrime {}
;

ExpressaoAndPrime: BITWISE_AND ExpressaoAnd {}
	| {}
;

ExpressaoIgualdade: ExpressaoRelacional ExpressaoIgualdadePrime {}
;

ExpressaoIgualdadePrime: IgualdadeOperador ExpressaoIgualdade {}
	| {}
;

IgualdadeOperador: EQUAL {}
	| NOT_EQUAL {}
;

ExpressaoRelacional: ExpressaoShift ExpressaoRelacionalPrime {}
;

ExpressaoRelacionalPrime: OperadorRelacional ExpressaoRelacional {}
	| {}
;

OperadorRelacional: LESS_THAN {}
	| LESS_EQUAL {}
	| GREATER_THAN {}
	| GREATER_EQUAL {}
;

ExpressaoShift: ExpressaoAditiva ExpressaoShiftPrime {}
;

ExpressaoShiftPrime: Shift ExpressaoShift {}
	| {}
;

Shift:  L_SHIFT {}
	| R_SHIFT {}
;

ExpressaoAditiva: ExpressaoMultiplicativa ExpressaoAditivaPrime {}
;

ExpressaoAditivaPrime: MaisMenos ExpressaoAditiva {}
	| {}
;

MaisMenos: PLUS {}
	| MINUS {}
;

ExpressaoMultiplicativa: ExpressaoCast ExpressaoMultiplicativaPrime {}
;

ExpressaoMultiplicativaPrime: Multiplicadores ExpressaoMultiplicativa {}
	| {}
;

Multiplicadores: MULTIPLY {}
	| DIV {}
	| REMAINDER {}
;

ExpressaoCast: ExpressaoUnaria {}
	| L_PAREN Tipo PointerIter R_PAREN ExpressaoCast {}
;

ExpressaoUnaria: ExpressaoPosFixa {}
	| INC ExpressaoUnaria {}
	| DEC ExpressaoUnaria {}
	| OperadorUnario ExpressaoCast {}
;

OperadorUnario: BITWISE_AND {}
	| MULTIPLY {}
	| PLUS {}
	| MINUS {}
	| BITWISE_NOT {}
	| NOT {}
;

ExpressaoPosFixa: ExpressaoPrimaria {}
	| ExpressaoPosFixa ExpressaoPosFixaPrime {}
;

ExpressaoPosFixaPrime: L_SQUARE_BRACKET Expressao R_SQUARE_BRACKET {}
	| INC {}
	| DEC {}
	| L_PAREN OpExpressaoAtribuicaoIter R_PAREN {}
;

OpExpressaoAtribuicaoIter: ExpressaoAtribuicaoIter {}
	| {}
;

ExpressaoAtribuicaoIter: ExpressaoAtribuicao ExpressaoAtribuicaoIterPrime {}
;

ExpressaoAtribuicaoIterPrime: COMMA ExpressaoAtribuicaoIter {}
	| {}
;

ExpressaoPrimaria: IDENTIFIER {}
	| Numero {}
	| CHARACTER {}
	| STRING {}
	| L_PAREN Expressao R_PAREN {}
;

Numero: NUM_INTEGER {}
	| NUM_HEXA {}
	| NUM_OCTAL {}
;

%%

void yyerror(char *s){
	int columnError = coluna-((int)strlen(yytext));
	printf("error:syntax:%d:%d: %s\n", linha, columnError, yytext);
	printf("%s", currentLine);
	int i;
	for(i = 0; i < columnError-1; i++)
		printf(" ");
	printf("^");
	exit(0);
}

int main(int argc, char **argv){
    yyparse();

	if(++cont) printf("\n");
	printf("SUCCESSFUL COMPILATION.");
    
	return 0;
}