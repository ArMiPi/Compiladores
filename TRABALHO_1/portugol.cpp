#include <iostream>
#include <string>
#include <list>

#include "Lexico.h"

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
                
            }
            std::cout << token << " -> '" << lex.getText() << "'" << std::endl;
        }
        std::cout << std::endl;
        std::cout << std::endl;
        token = -1;
    }
}
