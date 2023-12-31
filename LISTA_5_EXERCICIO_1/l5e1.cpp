#include <iostream>
#include <string>
#include <list>

#include "Automato.h"

const int INVALID_STATE {-1};
const int START_STATE {0};
int cont {0};

/**
 *  Gera os tokens do autômato
*/
void gerar_tokens(const std::string &input);

int main() {
    std::string line;
    
    // Leitura dos parâmetros
    while (std::getline(std::cin, line)) {
        if(std::cin.good()) line += '\n';
        gerar_tokens(line);
    }
}


void gerar_tokens(const std::string &input) {
    // Inicializar parâmetros de controle
    int current_state {START_STATE};
    int last_final {INVALID_STATE};

    int start_token {};
    int last_final_pos {-1};

    int palavra_index;
    for(int i {0}; i < input.size(); ) {
        try {
            palavra_index = get_index_palavra(input[i]);
            
            if(palavra_index == -1) 
                throw -1;

            current_state = get_index_estado(get_transicao(current_state, palavra_index));
            if(current_state == -1) 
                throw 0;

            if(is_final(current_state)) {
                last_final = current_state;
                last_final_pos = i;
            }

            i++;
        } catch(int erro) {
            if(last_final == -1) {
                if(start_token == last_final_pos && input[i] == '\n') { }
                else {
                    if(cont) std::cout << "\n";
                    std::cout << "ERRO";
                }
            }
            else {
                std::string token = input.substr(start_token, last_final_pos - start_token + 1);

                std::string classificacao_token = get_classificacao_token(last_final);

                if(classificacao_token.size()) token += " " + classificacao_token;

                if(cont) std::cout << "\n";
                std::cout << token;
            }

            // Resetar parâmetros
            current_state = START_STATE;
            last_final = INVALID_STATE;
            last_final_pos++;
            i = last_final_pos;
            start_token = last_final_pos;
            cont = 1;
        }
    }
}
