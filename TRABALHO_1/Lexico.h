#ifndef LEXICO_H
#define LEXICO_H

#include <string>

#include "Automato.h"

class Lexico {
    public:
        Lexico(std::string input, Automato automato);

        int gerar_token();
    
    private:
        std::string input;
        Automato automato;
};

#endif