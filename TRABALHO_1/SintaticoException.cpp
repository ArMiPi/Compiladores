#include "SintaticoException.h"

SintaticoException::SintaticoException(int linha, int coluna, std::string texto_incorreto) {
    this->linha = linha;
    this->coluna = coluna;
    this->texto_incorreto = texto_incorreto;
}


std::string SintaticoException::what() {
    return ("ERRO DE SINTAXE. Linha: " + std::to_string(linha) + 
            " Coluna: " + std::to_string(coluna) + 
            " -> '" + texto_incorreto + "'");
}
