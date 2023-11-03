#include <iostream>
#include <map>

#include "Sintatico.h"
#include "SintaticoException.h"

const int 
    IDENTIFICADOR = 1,
    NUMERO_INTEIRO = 2,
    NUMERO_REAL = 3,
    STRING = 4,
    ALGORITMO = 7,
    INICIO = 8,
    FIM = 9,
    VARIAVEIS = 10,
    INTEIRO = 11,
    REAL = 12,
    CARACTERE = 13,
    LOGICO = 14,
    VETOR = 15,
    MATRIZ = 16,
    TIPO = 17,
    FUNCAO = 18,
    PROCEDIMENTO = 19,
    SE = 20,
    ENTAO = 21,
    SENAO = 22,
    ENQUANTO = 23,
    FACA = 24,
    PARA = 25,
    DE = 26,
    ATE = 27,
    PASSO = 28,
    REPITA = 29,
    LEIA = 30,
    IMPRIMA = 31,
    VERDADEIRO = 32,
    FALSO = 33,
    E = 34,
    OU = 35,
    NAO = 36,
    DIV = 37,
    PONTOVIRGULA = 38,
    VIRGULA = 39,
    DOISPONTOS = 40,
    PONTO = 41,
    LCOLCHETE = 42,
    RCOLCHETE = 43,
    LPAREN = 44,
    RPAREN = 45,
    IGUAL = 46,
    DIFERENTE = 47,
    MAIOR = 48,
    MAIORIGUAL = 49,
    MENOR = 50,
    MENORIGUAL = 51,
    MAIS = 52,
    MENOS = 53,
    VEZES = 54,
    DIVISAO = 55,
    ATRIBUICAO = 56,
    DELIMITADOR = 57;

const std::map<int, std::string> tokens {
	{1, "identificador"},
	{2, "numero_inteiro"},
	{3, "numero_real"},
	{4, "string"},
	{7, "algoritmo"},
	{8, "inicio"},
	{9, "fim"},
	{10, "variaveis"},
	{11, "inteiro"},
	{12, "real"},
	{13, "caractere"},
	{14, "logico"},
	{15, "vetor"},
	{16, "matriz"},
	{17, "tipo"},
	{18, "funcao"},
	{19, "procedimento"},
	{20, "se"},
	{21, "entao"},
	{22, "senao"},
	{23, "enquanto"},
	{24, "faca"},
	{25, "para"},
	{26, "de"},
	{27, "ate"},
	{28, "passo"},
	{29, "repita"},
	{30, "leia"},
	{31, "imprima"},
	{32, "verdadeiro"},
	{33, "falso"},
	{34, "e"},
	{35, "ou"},
	{36, "nao"},
	{37, "div"},
	{38, ";"},
	{39, ","},
	{40, ":"},
	{41, "."},
	{42, "["},
	{43, "]"},
	{44, "("},
	{45, ")"},
	{46, "="},
	{47, "<>"},
	{48, ">"},
	{49, ">="},
	{50, "<"},
	{51, "<="},
	{52, "+"},
	{53, "-"},
	{54, "*"},
	{55, "/"},
	{56, "<-"},
	{57, "delimitador"}
};


Sintatico::Sintatico(Lexico lex) {
    this->lex = lex;
    this->token = lex.gerarToken();
}


void Sintatico::advance() {
    token = lex.gerarToken();
    std::string temp;
    
    if(token == 0) {
        while(std::getline(std::cin, temp)) {
            if(std::cin.good()) temp += "\n";
            lex.setInput(temp);
            token = lex.gerarToken();
            if(token) return;
        }
    }
}


void Sintatico::eat(int t) {
    if(token == t) advance();
    else error();
}


void Sintatico::setInput(std::string input) {
    lex.setInput(input);
    advance();
}


void Sintatico::error() {
    throw SintaticoException(lex.getLinha(), lex.getColuna(), lex.getText());
}


std::string getTokenStringValue(int tk) {
    std::map<int, std::string>::const_iterator it = tokens.find(tk);

    return it->second;
}


void Sintatico::Programa() {
    switch (token) {
        // Programa -> algoritmo identificador ; BlocoVariaveis ProcedimentoFuncao BlocoComandos .
        case ALGORITMO:
            eat(ALGORITMO);
            eat(IDENTIFICADOR);
            eat(PONTOVIRGULA);
            BlocoVariaveis();
            ProcedimentoFuncao();
            BlocoComandos();
            eat(PONTO);
            break;
        default:
            error();
            break;
    }
}

void Sintatico::ProcedimentoFuncao() {
    switch (token) {
        // ProcedimentoFuncao -> DeclaraProcedimento ProcedimentoFuncao
        case PROCEDIMENTO:
            DeclaraProcedimento(); ProcedimentoFuncao();
            break;
        // ProcedimentoFuncao -> DeclaraFuncao ProcedimentoFuncao
        case FUNCAO:
            DeclaraFuncao(); ProcedimentoFuncao();
            break;
        // ProcedimentoFuncao ->
        case INICIO:
            break;
        default:
            error();
            break;
    }
}


void Sintatico::DeclaraProcedimento() {
    switch (token) {
        // DeclaraProcedimento -> procedimento identificador Parametros ; DeclaraParametros BlocoVariaveis BlocoComandos ;
        case PROCEDIMENTO:
            eat(PROCEDIMENTO);
            eat(IDENTIFICADOR);
            Parametros();
            eat(PONTOVIRGULA);
            DeclaraParametros();
            BlocoVariaveis();
            BlocoComandos();
            eat(PONTOVIRGULA);
            break;
        default:
            error();
            break;
    }
}


void Sintatico::DeclaraFuncao() {
    switch (token) {
        // DeclaraFuncao -> funcao identificador Parametros : TipoBasico ; DeclaraParametros BlocoVariaveis BlocoComandos ;
        case FUNCAO:
            eat(FUNCAO);
            eat(IDENTIFICADOR);
            Parametros();
            eat(DOISPONTOS);
            TipoBasico();
            eat(PONTOVIRGULA);
            DeclaraParametros();
            BlocoVariaveis();
            BlocoComandos();
            eat(PONTOVIRGULA);
            break;
        default:
            error();
            break;
    }
}


void Sintatico::Parametros() {
    switch (token) {
        // Parametros ->
        case PONTOVIRGULA:
        case DOISPONTOS:
            break;
        // Parametros -> ( DeclaraIdentificador )
        case LPAREN:
            eat(LPAREN); DeclaraIdentificador(); eat(RPAREN);
            break;
        default:
            error();
            break;
    }
}


void Sintatico::DeclaraParametros() {
    switch (token) {
        // DeclaraParametros -> Declaracoes
        case IDENTIFICADOR:
        case TIPO:
        case INTEIRO:
        case REAL:
        case CARACTERE:
        case LOGICO:
            Declaracoes();
            break;
        // DeclaraParametros ->
        case VARIAVEIS:
        case INICIO:
            break;
        default:
            error();
            break;
    }
}


void Sintatico::BlocoVariaveis() {
    switch (token) {
        // BlocoVariaveis -> 
        case PROCEDIMENTO:
        case FUNCAO:
        case INICIO:
            break;
        // BlocoVariaveis -> variaveis Declaracoes
        case VARIAVEIS:
            eat(VARIAVEIS); Declaracoes();
            break;
        default:
            error();
            break;
    }
}


void Sintatico::Declaracoes() {
    switch (token) {
        // Declaracoes -> DeclaraVariaveis DeclaracoesL
        case IDENTIFICADOR:
        case INTEIRO:
        case REAL:
        case CARACTERE:
        case LOGICO:
            DeclaraVariaveis(); DeclaracoesL();
            break;
        // Declaracoes -> DeclaraTipo DeclaracoesL
        case TIPO:
            DeclaraTipo(); DeclaracoesL();
            break;
        default:
            error();
            break;
    }
}


void Sintatico::DeclaracoesL() {
    switch (token) {
        // DeclaracoesL -> Declaracoes
        case IDENTIFICADOR:
        case TIPO:
        case INTEIRO:
        case REAL:
        case CARACTERE:
        case LOGICO:
            Declaracoes();
            break;
        // DeclaracoesL ->
        case PROCEDIMENTO:
        case FUNCAO:
        case VARIAVEIS:
        case INICIO:
            break;
        default:
            error();
            break;
    }
}


void Sintatico::DeclaraTipo() {
    switch (token) {
        // DeclaraTipo -> tipo identificador = VetorMatriz [ Dimensao ] TipoBasico ;
        case TIPO:
            eat(TIPO);
            eat(IDENTIFICADOR);
            eat(IGUAL);
            VetorMatriz();
            eat(LCOLCHETE);
            Dimensao();
            eat(RCOLCHETE);
            TipoBasico();
            eat(PONTOVIRGULA);
            break;
        default:
            error();
            break;
    }
}


void Sintatico::DeclaraVariaveis() {
    switch (token) {
        // DeclaraVariaveis -> TipoBasico : DeclaraIdentificador ;
        case IDENTIFICADOR:
        case INTEIRO:
        case REAL:
        case CARACTERE:
        case LOGICO:
            TipoBasico();
            eat(DOISPONTOS);
            DeclaraIdentificador();
            eat(PONTOVIRGULA);
            break;
        default:
            error();
            break;
    }
}


void Sintatico::DeclaraIdentificador() {
    switch (token) {
        // DeclaraIdentificador -> identificador DeclaraIdentificadorL
        case IDENTIFICADOR:
            eat(IDENTIFICADOR); DeclaraIdentificadorL();
            break;
        default:
            error();
            break;
    }
}


void Sintatico::DeclaraIdentificadorL() {
    switch (token) {
        // DeclaraIdentificadorL -> 
        case PONTOVIRGULA:
        case RPAREN:
            break;
        // DeclaraIdentificadorL -> , DeclaraIdentificador
        case VIRGULA:
            eat(VIRGULA); DeclaraIdentificador();
            break;
        default:
            error();
            break;
    }
}


void Sintatico::VetorMatriz() {
    switch (token) {
        // VetorMatriz -> vetor
        case VETOR:
            eat(VETOR);
            break;
        // VetorMatriz -> matriz
        case MATRIZ:
            eat(MATRIZ);
            break;
        default:
            error();
            break;
    }
}


void Sintatico::Dimensao() {
    switch (token) {
        // Dimensao -> numero_inteiro : numero_inteiro DimensaoL
        case NUMERO_INTEIRO:
            eat(NUMERO_INTEIRO); eat(DOISPONTOS); eat(NUMERO_INTEIRO); DimensaoL();
            break;
        default:
            error();
            break;
    }
}


void Sintatico::DimensaoL() {
    switch (token) {
        // DimensaoL -> 
        case RCOLCHETE:
            break;
        // DimensaoL -> , Dimensao
        case VIRGULA:
            eat(VIRGULA); Dimensao();
            break;
        default:
            error();
            break;
    }
}


void Sintatico::TipoBasico() {
    switch (token) {
        // TipoBasico -> identificador
        case IDENTIFICADOR:
            eat(IDENTIFICADOR);
            break;
        // TipoBasico -> inteiro
        case INTEIRO:
            eat(INTEIRO);
            break;
        // TipoBasico -> real
        case REAL:
            eat(REAL);
            break;
        // TipoBasico -> caractere
        case CARACTERE:
            eat(CARACTERE);
            break;
        // TipoBasico -> logico
        case LOGICO:
            eat(LOGICO);
            break;
        default:
            error();
            break;
    }
}


void Sintatico::BlocoComandos() {
    switch (token) {
        // BlocoComandos -> inicio ListaComandos fim
        case INICIO:
            eat(INICIO); ListaComandos(); eat(FIM);
            break;
        default:
            error();
            break;
    }
}


void Sintatico::ListaComandos() {
    switch (token) {
        // ListaComandos -> Comandos ; ListaComandosL
        case IDENTIFICADOR:
        case SE:
        case ENQUANTO:
        case PARA:
        case REPITA:
        case LEIA:
        case IMPRIMA:
            Comandos(); eat(PONTOVIRGULA); ListaComandosL();
            break;
        default:
            error();
            break;
    }
}


void Sintatico::ListaComandosL() {
    switch (token) {
        // ListaComandosL -> ListaComandos
        case IDENTIFICADOR:
        case SE:
        case ENQUANTO:
        case PARA:
        case REPITA:
        case LEIA:
        case IMPRIMA:
            ListaComandos();
            break;
        // ListaComandosL ->
        case FIM:
        case SENAO:
        case ATE:
            break;
        default:
            error();
            break;
    }
}


void Sintatico::Comandos() {
    switch (token) {
        // Comandos -> identificador ComandosL
        case IDENTIFICADOR:
            eat(IDENTIFICADOR); ComandosL();
            break;
        // Comandos -> se Expressao entao ListaComandos ComandosS
        case SE:
            eat(SE);
            Expressao();
            eat(ENTAO);
            ListaComandos();
            ComandosS();
            break;
        // Comandos -> enquanto Expressao faca ListaComandos fim enquanto
        case ENQUANTO:
            eat(ENQUANTO); Expressao(); eat(FACA); ListaComandos(); eat(FIM); eat(ENQUANTO);
            break;
        // Comandos -> para identificador de Expressao ate Expressao ComandosP faca ListaComandos fim para
        case PARA:
            eat(PARA);
            eat(IDENTIFICADOR);
            eat(DE);
            Expressao();
            eat(ATE);
            Expressao();
            ComandosP();
            eat(FACA);
            ListaComandos();
            eat(FIM);
            eat(PARA);
            break;
        // Comandos -> repita ListaComandos ate Expressao
        case REPITA:
            eat(REPITA); ListaComandos(); eat(ATE); Expressao();
            break;
        // Comandos -> leia ( Variavel )
        case LEIA:
            eat(LEIA);
            eat(LPAREN);
            Variavel();
            eat(RPAREN);
            break;
        // Comandos -> imprima ( ExprIter )
        case IMPRIMA:
            eat(IMPRIMA); eat(LPAREN); ExprIter(); eat(RPAREN);
            break;
        default:
            error();
            break;
    }
}


void Sintatico::ComandosL() {
    switch (token) {
        // ComandosL -> 
        case PONTOVIRGULA:
            break;
        // ComandosL -> ( ExprIter )
        case LPAREN:
            eat(LPAREN); ExprIter(); eat(RPAREN);
            break;
        // ComandosL -> VariavelL <- Expressao
        case LCOLCHETE:
        case ATRIBUICAO:
            VariavelL(); eat(ATRIBUICAO); Expressao();
            break;
        default:
            error();
            break;
    }
}


void Sintatico::ComandosS() {
    switch (token) {
        // ComandosS -> fim se
        case FIM:
            eat(FIM); eat(SE);
            break;
        // ComandosS -> senao ListaComandos fim se
        case SENAO:
            eat(SENAO); ListaComandos(); eat(FIM); eat(SE);
            break;
        default:
            error();
            break;
    }
}


void Sintatico::ComandosP() {
    switch (token) {
        // ComandosP -> 
        case FACA:
            break;
        // ComandosP -> passo Expressao
        case PASSO:
            eat(PASSO); Expressao();
            break;
        default:
            error();
            break;
    }
}


void Sintatico::Expressao() {
    switch (token) {
        // Expressao -> ExpressaSimples ExpressaoL
        case IDENTIFICADOR:
        case LPAREN:
        case NUMERO_INTEIRO:
        case MENOS:
        case MAIS:
        case NAO:
        case NUMERO_REAL:
        case VERDADEIRO:
        case FALSO:
        case STRING:
            ExpressaoSimples(); ExpressaoL();
            break;
        default:
            error();
            break;
    }
}


void Sintatico::ExpressaoL() {
    switch (token) {
        // ExpressaoL -> 
        case PONTOVIRGULA:
        case RPAREN:
        case RCOLCHETE:
        case VIRGULA:
        case ENTAO:
        case FACA:
        case ATE:
        case PASSO:
            break;
        // ExpressaoL -> = ExpressaoSimples ExpressaoL
        case IGUAL:
            eat(IGUAL); ExpressaoSimples(); ExpressaoL();
            break;
        // ExpressaoL -> <> ExpressaoSimples ExpressaoL
        case DIFERENTE:
            eat(DIFERENTE); ExpressaoSimples(); ExpressaoL();
            break;
        // ExpressaoL -> < ExpressaoSimples ExpressaoL
        case MENOR:
            eat(MENOR); ExpressaoSimples(); ExpressaoL();
            break;
        // ExpressaoL -> <= ExpressaoSimples ExpressaoL
        case MENORIGUAL:
            eat(MENORIGUAL); ExpressaoSimples(); ExpressaoL();
            break;
        // ExpressaoL -> > ExpressaoSimples ExpressaoL
        case MAIOR:
            eat(MAIOR); ExpressaoSimples(); ExpressaoL();
            break;
        // ExpressaoL -> => ExpressaoSimples ExpressaoL
        case MAIORIGUAL:
            eat(MAIORIGUAL); ExpressaoSimples(); ExpressaoL();
            break;
        default:
            error();
            break;
    }
}


void Sintatico::ExpressaoSimples() {
    switch (token) {
        // ExpressaoSimples -> Termo ExpressaoSimples'
        case IDENTIFICADOR:
        case LPAREN:
        case NUMERO_INTEIRO:
        case NAO:
        case NUMERO_REAL:
        case VERDADEIRO:
        case FALSO:
        case STRING:
            Termo(); ExpressaoSimplesL();
            break;
        // ExpressaoSimples -> - Termo
        case MENOS:
            eat(MENOS); Termo();
            break;
        // ExpressaoSimples -> + Termo
        case MAIS:
            eat(MAIS); Termo();
            break;
        default:
            error();
            break;
    }
}


void Sintatico::ExpressaoSimplesL() {
    switch (token) {
        // ExpressoSimplesL ->
        case PONTOVIRGULA:
        case RPAREN:
        case IGUAL:
        case RCOLCHETE:
        case VIRGULA:
        case ENTAO:
        case FACA:
        case ATE:
        case PASSO:
        case DIFERENTE:
        case MENOR:
        case MENORIGUAL:
        case MAIOR:
        case MAIORIGUAL:
            break;
        // ExpressaoSimplesL -> + Termo ExpressaoSimplesL
        case MAIS:
            eat(MAIS); Termo(); ExpressaoSimplesL();
            break;
        // ExpressaoSimplesL -> - Termo ExpressaoSimplesL
        case MENOS:
            eat(MENOS); Termo(); ExpressaoSimplesL();
            break;
        // ExpressaoSimplesL -> OU Termo ExpressaoSimplesL
        case OU:
            eat(OU); Termo(); ExpressaoSimplesL();
            break;
        default:
            error();
            break;
    }
}


void Sintatico::Termo() {
    switch (token) {
        // Termo -> Fator TermoL
        case IDENTIFICADOR:
        case LPAREN:
        case NUMERO_INTEIRO:
        case NAO:
        case NUMERO_REAL:
        case VERDADEIRO:
        case FALSO:
        case STRING:
            Fator(); TermoL();
            break;
        default:
            error();
            break;
    }
}


void Sintatico::TermoL() {
    switch (token) {
        // TermoL ->
        case PONTOVIRGULA:
        case RPAREN:
        case IGUAL:
        case RCOLCHETE:
        case VIRGULA:
        case ENTAO:
        case FACA:
        case ATE:
        case PASSO:
        case DIFERENTE:
        case MENOR:
        case MENORIGUAL:
        case MAIOR:
        case MAIORIGUAL:
        case MAIS:
        case MENOS:
        case OU:
            break;
        // TermoL -> * Fator Termo'
        case VEZES:
            eat(VEZES); Fator(); TermoL();
            break;
        // TermoL -> / Fator Termo'
        case DIVISAO:
            eat(DIVISAO); Fator(); TermoL();
            break;
        // TermoL -> DIV Fator Termo'
        case DIV:
            eat(DIV); Fator(); TermoL();
            break;
        // TermoL -> E Fator Termo'
        case E:
            eat(E); Fator(); TermoL();
            break;
        default:
            error();
            break;
    }
}


void Sintatico::Fator() {
    switch (token) {
        // Fator -> identificador FatorL
        case IDENTIFICADOR:
            eat(IDENTIFICADOR); FatorL();
            break;
        // Fator -> ( Expressao )
        case LPAREN:
            eat(LPAREN); Expressao(); eat(RPAREN);
            break;
        // Fator -> numero_inteiro
        case NUMERO_INTEIRO:
            eat(NUMERO_INTEIRO);
            break;
        // Fator -> NAO Fator
        case NAO:
            eat(NAO); Fator();
            break;
        // Fator -> numero_real
        case NUMERO_REAL:
            eat(NUMERO_REAL);
            break;
        // Fator -> verdadeiro
        case VERDADEIRO:
            eat(VERDADEIRO);
            break;
        // Fator -> falso
        case FALSO:
            eat(FALSO);
            break;
        // Fator -> string
        case STRING:
            eat(STRING);
            break;
        default:
            error();
            break;
    }
}


void Sintatico::FatorL() {
    switch (token) {
        // FatorL ->
        case PONTOVIRGULA:
        case RPAREN:
        case IGUAL:
        case RCOLCHETE:
        case VIRGULA:
        case ENTAO:
        case FACA:
        case ATE:
        case PASSO:
        case DIFERENTE:
        case MENOR:
        case MENORIGUAL:
        case MAIOR:
        case MAIORIGUAL:
        case MAIS:
        case MENOS:
        case VEZES:
        case DIVISAO:
        case OU:
        case DIV:
        case E:
            break;
        // FatorL -> ( ExprIter )
        case LPAREN:
            eat(LPAREN); ExprIter(); eat(RPAREN);
            break;
        // FatorL -> [ ExprIter ]
        case LCOLCHETE:
            eat(LCOLCHETE); ExprIter(); eat(RCOLCHETE);
            break;
        default:
            error();
            break;
    }
}


void Sintatico::Variavel() {
    switch (token) {
        // Variavel -> identificador Variavel'
        case IDENTIFICADOR:
            eat(IDENTIFICADOR); VariavelL();
            break;
        default:
            error();
            break;
    }
}


void Sintatico::VariavelL() {
    switch (token) {
        // VariavelL -> 
        case RPAREN:
        case ATRIBUICAO:
            break;
        // VariavelL -> [ ExprIter ]
        case LCOLCHETE:
            eat(LCOLCHETE); ExprIter(); eat(RCOLCHETE);
            break;
        default:
            error();
            break;
    }
}


void Sintatico::ExprIter() {
    switch (token) {
        // ExprIter -> Expressao ExprIterL
        case IDENTIFICADOR:
        case LPAREN:
        case NUMERO_INTEIRO:
        case MENOS:
        case MAIS:
        case NAO:
        case NUMERO_REAL:
        case VERDADEIRO:
        case FALSO:
        case STRING:
            Expressao(); ExprIterL();
            break;
        default:
            error();
            break;
    }
}


void Sintatico::ExprIterL() {
    switch (token) {
        // ExprIterL ->
        case RPAREN:
        case RCOLCHETE:
            break;
        // ExprIterL -> , ExprIter
        case VIRGULA:
            eat(VIRGULA); ExprIter();
            break;
        default:
            error();
            break;
    }
}
