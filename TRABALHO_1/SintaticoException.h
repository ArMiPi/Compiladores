#ifndef SINTATICOEXCEPTION_H
#define SINTATICOEXCEPTION_H

#include <exception>
#include <string>

class SintaticoException : std::exception {
    public:
        SintaticoException(int linha, int coluna, std::string texto_incorreto);

        std::string what();

    private:
        std::string texto_incorreto;
        int linha, coluna;
};


#endif