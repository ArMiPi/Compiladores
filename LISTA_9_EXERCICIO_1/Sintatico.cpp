#include <iostream> // TODO  --REMOVER--
#include "Sintatico.h"

const int IF = 1, THEN = 2, ELSE = 3, BEGIN = 4, END = 5, PRINT = 6, NUM = 7, EQ = 8, SEMI = 9;
std::string erro_msg {};


Sintatico::Sintatico(Lexico lex) {
    this->lex = lex;
    token = lex.gerarToken();
}


void Sintatico::advance() {
    token = lex.gerarToken();
}


void Sintatico::eat(int t) {
    if(token == t) advance();
    else {
        
        error();
    }
}


void Sintatico::setInput(std::string input) {
    lex.setInput(input);
    advance();
}


void Sintatico::error() {
    std::cout << "erro" << std::endl;
}


void Sintatico::S() {
    switch (token) {
        case IF:
            // S -> if E then S else S
            eat(IF); E(); eat(THEN); S(); eat(ELSE); S();
            break;
        case BEGIN:
            // S -> begin S L
            eat(BEGIN); S(); L();
            break;
        case PRINT:
            // S -> print E
            eat(PRINT); E();
            break;
        default:
            error();
            break;
    }
}


void Sintatico::L() {
    switch (token)
    {
        case END:
            // L -> end
            eat(END);
            break;
        case SEMI:
            // L -> ; S L
            eat(SEMI); S(); L();
            break;
        default:
            error();
            break;
    }
}


void Sintatico::E() {
    switch (token)
    {
        case NUM:
            // E -> num = num
            eat(NUM); eat(EQ); eat(NUM);
            break;
        default:
            error();
            break;
    }
}
