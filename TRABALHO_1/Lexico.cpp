#include <map>

#include "Lexico.h"


const int INVALID_STATE {-1};
const int START_STATE {0};
const std::map<std::string, int> tokens {
	{"IF", 1},
	{"THEN", 2},
	{"ELSE", 3},
	{"BEGIN", 4},
	{"END", 5},
	{"PRINT", 6},
	{"NUM", 7},
	{"EQ", 8},
	{"SEMI", 9},
};


Lexico::Lexico(std::string input, Automato automato) {
    this->input = input;
    this->automato = automato;
    int start_token {};
    int last_final_pos{};
}


int Lexico::gerar_token() {

}
