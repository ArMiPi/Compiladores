#include <iostream>
#include <string>
#include <list>

#include "Lexico.h"

int cont {-1};

int main() {
    std::string line;
    Lexico lex = Lexico();

    int token {-1};
    // Leitura dos parâmetros
    while(std::getline(std::cin, line)) {
        if(std::cin.good()) line += '\n';
        lex.setInput(line);
        while(token) {
            token = lex.gerarToken();

            if(token == -2) {
                if(++cont) std::cout << "\n";
                std::cout << lex.error();
            }
        }
        token = -1;
    }
}
