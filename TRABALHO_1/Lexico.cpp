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

int start_token {};
int last_final_pos {};


Lexico::Lexico() {
    int start_token {};
    int last_final_pos{};
	std::string input {};
}


void setInput(std::string input) {

}


int Lexico::gerar_token() {
	int current_state {START_STATE};
	int last_final {INVALID_STATE};

	int palavra_index;

	for(int i {start_token}; i <= input.size(); ) {
		try {
			palavra_index = Automato::get_index_palavra(input[i]);
			if(palavra_index == 1) throw -1;

			current_state = Automato::get_index_estado(Automato::get_transicao(current_state, palavra_index));
			if(current_state == -1) throw 0;

			if(Automato::is_final(current_state)) {
				last_final = current_state;
				last_final_pos = i;
			}

			i++;
		} catch(int erro) {
			// Se um estado final não foi atingido
			if(last_final == -1) {
				if(i == start_token && (input[i] == ' ' || input[i] == '\n' || input[i] == '\0')) { }
				else {
					return -1;
				}
			}
			else {
				std::string token = input.substr(start_token, last_final_pos - start_token + 1);
				
				std::string classificacao_token = Automato::get_classificacao_token(last_final);

				std::map<std::string, int>::const_iterator it = tokens.find(classificacao_token);

    			return it->second;
			}

			// Resetar parâmetros
			current_state = START_STATE;
			last_final = INVALID_STATE;
			last_final_pos++;
			i = last_final_pos;
			start_token = last_final_pos;
		}
	}
}
