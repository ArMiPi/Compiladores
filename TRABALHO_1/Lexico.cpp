#include <iostream>
#include <algorithm>
#include <map>

#include "Lexico.h"
#include "LexicoException.h"


const int INVALID_STATE {-1};
const int START_STATE {0};
const std::map<std::string, int> tokens {
	{"identificador", 1},
	{"numero_inteiro", 2},
	{"numero_real", 3},
	{"string", 4},
	{"single_line_comment", 5},
	{"multi_line_comment", 6},
	{"algoritmo", 7},
	{"inicio", 8},
	{"fim", 9},
	{"variaveis", 10},
	{"inteiro", 11},
	{"real", 12},
	{"caractere", 13},
	{"logico", 14},
	{"vetor", 15},
	{"matriz", 16},
	{"tipo", 17},
	{"funcao", 18},
	{"procedimento", 19},
	{"se", 20},
	{"entao", 21},
	{"senao", 22},
	{"enquanto", 23},
	{"faca", 24},
	{"para", 25},
	{"de", 26},
	{"ate", 27},
	{"passo", 28},
	{"repita", 29},
	{"leia", 30},
	{"imprima", 31},
	{"verdadeiro", 32},
	{"falso", 33},
	{"e", 34},
	{"ou", 35},
	{"nao", 36},
	{"div", 37},
	{";", 38},
	{",", 39},
	{":", 40},
	{".", 41},
	{"[", 42},
	{"]", 43},
	{"(", 44},
	{")", 45},
	{"=", 46},
	{"<>", 47},
	{">", 48},
	{">=", 49},
	{"<", 50},
	{"<=", 51},
	{"+", 52},
	{"-", 53},
	{"*", 54},
	{"/", 55},
	{"<-", 56},
	{"delimitador", 57}
};


int linha {1};
int coluna {1};


Lexico::Lexico() { 
	this->start_token = 0;
	this->last_final_pos = 0;
}


void::Lexico::setInput(std::string input_str) {
	input = input_str;
	start_token = 0;
	last_final_pos = 0;
}


void Lexico::getInput() {
	std::getline(std::cin, input);
	if(std::cin.good()) input += '\n';

	start_token = 0;
	last_final_pos = 0;
	linha++;
	coluna = 1;
}


std::string Lexico::getText() {
	return text;
}


int Lexico::getLinha() {
	return linha;
}


int Lexico::getColuna() {
	return coluna;
}


void Lexico::readMultiLineComment(int start) {
	start_token = 0;
	last_final_pos = 0;
	while(true) {
		for(int i {start}; i < input.size(); i++) {
			if(input[i] == '}') {
				input = input.substr(i, input.size());

				coluna = i + 2;

				return;
			}
		}

		getInput();
		start = 0;
	}
}


void Lexico::consumeString(int start) {
	start_token = 0;
	last_final_pos = 0;

	for(int i {start + 1}; i < input.size(); i++) {
		if(input[i] == '"') {
			text = input.substr(start, i);
			input = input.substr(i, input.size());

			coluna += i - start + 1;

			return;
		}
	}
}


int Lexico::gerarToken() {
	int current_state {START_STATE};
	int last_final {INVALID_STATE};

	int palavra_index;

	for(int i {start_token}; i <= input.size(); ) {
		try {
			palavra_index = Automato::get_index_palavra(input[i]);
			if(palavra_index == -1) throw -1;

			current_state = Automato::get_index_estado(Automato::get_transicao(current_state, palavra_index));
			if(current_state == -1) throw 0;

			if(Automato::is_final(current_state)) {
				last_final = current_state;
				last_final_pos = i;
			}

			i++;
		} catch(int erro) {
			int cod_token;
			text = input.substr(start_token, last_final_pos - start_token + 1);
			// Se um estado final não foi atingido
			if(last_final == -1) {
				if(i == start_token) {
					if(input[i] == ' ') {
						cod_token = -1;
						coluna++;
					} else if(input[i] == '\n') {
						cod_token = -1;
						linha++;
						coluna = 1;
					} else if(input[i] == 0) { 
						cod_token = 0;
					} else {
						cod_token = -2;
					}
				}
				else {
					if(input[i-1] == '{') {
						readMultiLineComment(i);
						cod_token = -1;
					} else if(input[i-1] == '"'){
						consumeString(i);
						cod_token = 4;
					} else {
						cod_token = -2;
					}
				}
			}
			else {
				std::string classificacao_token = Automato::get_classificacao_token(last_final);

				std::map<std::string, int>::const_iterator it = tokens.find(classificacao_token);

    			cod_token = it->second;
	
				coluna += text.length();
			}

			// Resetar parâmetros
			current_state = START_STATE;
			last_final = INVALID_STATE;
			last_final_pos++;
			i = last_final_pos;
			start_token = last_final_pos;

			switch (cod_token) {
			// identificadores ou palavras reservadas
				case 1:
				case 57:
					{
						std::string temp = text;
						std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
						std::map<std::string, int>::const_iterator it = tokens.find(temp);

    					if(it->second) cod_token = it->second;
						break;
					}
				case 5:
					getInput();
					i = last_final_pos;

					cod_token = -1;

					break;
				default:
					break;
			}

			if(cod_token == -2) error();
			if(cod_token != -1) return cod_token;
		}
	}
	return 0;
}


void Lexico::error() {
	LexicoException leex = LexicoException(text, linha, coluna);

	coluna += text.length();

	throw leex;
}
