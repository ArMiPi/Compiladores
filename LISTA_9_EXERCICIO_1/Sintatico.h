#ifndef SINTATICO_H
#define SINTATICO_H

#include <string>

class Sintatico {
    public:
        Sintatico();

        void advance();

        void eat(int t);

        std::string error();

        // FUNÇÕES ESPECÍFICAS PARA ESSE PROBLEMA
        void S();

        void L();

        void E();
};

#endif