#include <iostream>
#include <string>
#include <list>

#include "Automato.h"

int main() {
    std::list<std::string> input;
    std::string line;
    
    // Leitura dos parâmetros
    while (std::getline(std::cin, line)) {
        input.push_back(line);
    }

    for(std::string str : input) {
        std::cout << str << std::endl;
    }
}
