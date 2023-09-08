#include "Automato.h"
#include "string_utils.h"


// Definição do Autômato
const std::string alfabeto [] {"a", "c", "e", "h", "i", "r", "s", "t", "0-9", "+", "-"};

const std::string estados [] {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22"};

const std::map<std::string, std::string> estados_finais {
	{"3", "ELE"},
	{"6", "ELA"},
	{"8", "DELE"},
	{"10", "DELA"},
	{"13", "GATO"},
	{"14", "CARRO"},
	{"15", "GATOS"},
	{"16", "CARROS"},
	{"17", "MAIS"},
	{"18", "MENOS"},
	{"19", "INTEIRO"},
	{"22", "REAL"},
};

const std::string transicoes [][11] {
//            a         c         e         h         i         r         s         t        0-9        +         -     
/*  1  */{   "0",     "11",      "0",      "2",      "0",      "0",      "4",      "0",     "19",     "17",      "18"   },
/*  2  */{   "0",      "0",      "3",      "0",      "7",      "0",      "0",      "0",      "0",      "0",      "0"    },
/*  3  */{   "0",      "0",      "0",      "0",      "0",      "9",      "0",      "0",      "0",      "0",      "0"    },
/*  4  */{   "0",      "0",      "0",      "5",      "0",      "0",      "0",      "0",      "0",      "0",      "0"    },
/*  5  */{   "0",      "0",      "6",      "0",      "0",      "0",      "0",      "0",      "0",      "0",      "0"    },
/*  6  */{   "0",      "0",      "0",      "0",      "0",      "0",      "0",      "0",      "0",      "0",      "0"    },
/*  7  */{   "0",      "0",      "0",      "0",      "0",      "0",      "8",      "0",      "0",      "0",      "0"    },
/*  8  */{   "0",      "0",      "0",      "0",      "0",      "0",      "0",      "0",      "0",      "0",      "0"    },
/*  9  */{   "0",      "0",      "0",      "0",      "0",      "0",     "10",      "0",      "0",      "0",      "0"    },
/* 10  */{   "0",      "0",      "0",      "0",      "0",      "0",      "0",      "0",      "0",      "0",      "0"    },
/* 11  */{  "12",      "0",      "0",      "0",      "0",      "0",      "0",      "0",      "0",      "0",      "0"    },
/* 12  */{   "0",      "0",      "0",      "0",      "0",     "14",      "0",     "13",      "0",      "0",      "0"    },
/* 13  */{   "0",      "0",      "0",      "0",      "0",      "0",     "15",      "0",      "0",      "0",      "0"    },
/* 14  */{   "0",      "0",      "0",      "0",      "0",      "0",     "16",      "0",      "0",      "0",      "0"    },
/* 15  */{   "0",      "0",      "0",      "0",      "0",      "0",      "0",      "0",      "0",      "0",      "0"    },
/* 16  */{   "0",      "0",      "0",      "0",      "0",      "0",      "0",      "0",      "0",      "0",      "0"    },
/* 17  */{   "0",      "0",      "0",      "0",      "0",      "0",      "0",      "0",      "0",      "0",      "0"    },
/* 18  */{   "0",      "0",      "0",      "0",      "0",      "0",      "0",      "0",      "0",      "0",      "0"    },
/* 19  */{   "0",      "0",     "20",      "0",      "0",      "0",      "0",      "0",     "19",      "0",      "0"    },
/* 20  */{   "0",      "0",      "0",      "0",      "0",      "0",      "0",      "0",     "22",     "21",      "21"   },
/* 21  */{   "0",      "0",      "0",      "0",      "0",      "0",      "0",      "0",     "22",      "0",      "0"    },
/* 22  */{   "0",      "0",      "0",      "0",      "0",      "0",      "0",      "0",     "22",      "0",      "0"    },
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
