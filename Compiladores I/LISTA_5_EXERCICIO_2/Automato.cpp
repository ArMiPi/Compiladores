#include "Automato.h"
#include "string_utils.h"


// Definição do Autômato
const std::string alfabeto [] {"a-e", "f", "g-h", "i", "j-z", "0-9", ".", "-", "\n", " "};

const std::string estados [] {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13"};

const std::map<std::string, std::string> estados_finais {
	{"2", "ID"},
	{"3", "IF"},
	{"4", "ID"},
	{"5", "error"},
	{"6", "REAL"},
	{"7", "NUM"},
	{"8", "REAL"},
	{"9", "error"},
	{"11", "comment"},
	{"12", "white space"},
	{"13", "error"},
};

const std::string transicoes [][10] {
//           a-e        f        g-h        i        j-z       0-9        .         -         \n      blank   
/*  1  */{   "4",      "4",      "4",      "2",      "4",      "7",      "5",      "9",     "13",      "12"   },
/*  2  */{   "4",      "3",      "4",      "4",      "4",      "4",      "0",      "0",      "0",      "0"    },
/*  3  */{   "4",      "4",      "4",      "4",      "4",      "4",      "0",      "0",      "0",      "0"    },
/*  4  */{   "4",      "4",      "4",      "4",      "4",      "4",      "0",      "0",      "0",      "0"    },
/*  5  */{   "0",      "0",      "0",      "0",      "0",      "6",      "0",      "0",      "0",      "0"    },
/*  6  */{   "0",      "0",      "0",      "0",      "0",      "6",      "0",      "0",      "0",      "0"    },
/*  7  */{   "0",      "0",      "0",      "0",      "0",      "7",      "8",      "0",      "0",      "0"    },
/*  8  */{   "0",      "0",      "0",      "0",      "0",      "8",      "0",      "0",      "0",      "0"    },
/*  9  */{   "0",      "0",      "0",      "0",      "0",      "0",      "0",     "10",      "0",      "0"    },
/* 10  */{  "10",     "10",     "10",     "10",     "10",      "0",      "0",      "0",     "11",      "0"    },
/* 11  */{   "0",      "0",      "0",      "0",      "0",      "0",      "0",      "0",      "0",      "0"    },
/* 12  */{   "0",      "0",      "0",      "0",      "0",      "0",      "0",      "0",      "0",      "12"   },
/* 13  */{   "0",      "0",      "0",      "0",      "0",      "0",      "0",      "0",      "0",      "0"    },
};


const int tam_alfabeto = sizeof(alfabeto) / sizeof(alfabeto[0]);
const int tam_estados = sizeof(estados) / sizeof(estados[0]);


int get_index_estado(std::string estado) {
    for(int i {0}; i < tam_estados; i++) {
        if(estados[i] == estado) return i;
    }

    return -1;
}

        
int get_index_palavra(char palavra) {
    for(int i {0}; i < tam_alfabeto; i++) {
        // Verificar se está dentro de um intervalo
        if(alfabeto[i].size() > 1 && contains(alfabeto[i], "-") != -1) {
            if(is_in_interval(palavra, alfabeto[i])) return i; 
        }
        else if(palavra == alfabeto[i][0]) {
            return i;
        }
    }

    return -1;
}


bool is_final(int index_estado) {
    std::map<std::string, std::string>::const_iterator it = estados_finais.find(estados[index_estado]);

    return it != estados_finais.end();
}


std::string get_classificacao_token(int index_estado) {
    if(index_estado == -1) return "";

    std::map<std::string, std::string>::const_iterator it = estados_finais.find(estados[index_estado]);

    return it->second;
}


std::string get_transicao(int index_estado, int index_palavra) {
    return transicoes[index_estado][index_palavra];
}
