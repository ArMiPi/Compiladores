#ifndef SINTATICO_H
#define SINTATICO_H

#include <string>
#include "Lexico.h"

class Sintatico {
    public:
        Sintatico(Lexico lex);

        void advance();

        void eat(int t);

        void setInput(std::string input);

        void error();

        // FUNÇÕES ESPECÍFICAS PARA ESSE PROBLEMA
        void Programa();

        void ProcedimentoFuncao();

        void DeclaraProcedimento();

        void DeclaraFuncao();

        void Parametros();

        void DeclaraParametros();

        void BlocoVariaveis();

        void Declaracoes();

        void DeclaracoesL();

        void DeclaraTipo();

        void DeclaraVariaveis();

        void DeclaraIdentificador();

        void DeclaraIdentificadorL();

        void VetorMatriz();

        void Dimensao();

        void DimensaoL();

        void TipoBasico();

        void BlocoComandos();

        void ListaComandos();

        void ListaComandosL();

        void Comandos();

        void ComandosL();

        void ComandosS();

        void ComandosP();

        void Expressao();

        void ExpressaoL();

        void ExpressaoSimples();

        void ExpressaoSimplesL();

        void Termo();

        void TermoL();

        void Fator();

        void FatorL();

        void Variavel();

        void VariavelL();

        void ExprIter();

        void ExprIterL();

    private:
        int token {};
        Lexico lex {};
};

#endif