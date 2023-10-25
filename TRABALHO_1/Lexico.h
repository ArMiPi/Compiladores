#ifndef LEXICO_H
#define LEXICO_H

#include <string>

#include "Automato.h"

class Lexico {
    public:
        Lexico();

        void setInput(std::string input);

        int gerar_token();
    
    private:
        std::string input;
};

#endif