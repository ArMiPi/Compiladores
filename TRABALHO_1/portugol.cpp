#include <iostream>
#include <string>
#include <list>

#include "Lexico.h"

int main() {
    std::string line;
    Lexico lex = Lexico("teste");

    // Leitura dos parâmetros
    while(std::getline(std::cin, line)) {
        if(std::cin.good()) line += '\n';
        std::cout << lex.gerar_token();
    }
}
