#include <iostream>
#include <string>
#include <list>

#include "Lexico.h"
#include "LexicoException.h"
#include "Sintatico.h"
#include "SintaticoException.h"

int main() {
    std::string line;
    Lexico lex = Lexico();
    Sintatico sin = Sintatico(lex);

    int token {-1};
    // Leitura dos parâmetros
    try {
        while(std::getline(std::cin, line)) {
            if(std::cin.good()) line += '\n';
            sin.setInput(line);
            sin.Programa();
        } 
        std::cout << "PROGRAMA CORRETO.";
    } catch(LexicoException &leex) {
        std::cout << leex.what();
    } catch(SintaticoException siex) {
        std::cout << siex.what();
    }
}
