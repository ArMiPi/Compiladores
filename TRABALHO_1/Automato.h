#ifndef AUTOMATO_H
#define AUTOMATO_H

#include <string>

class Automato {
    public:
        /**
         *   Retorna o index de estado.
         *   
         *   Caso estado não exista em estados, será retornado -1.
        */
        int get_index_estado(std::string estado);


        /**
         *   Retorna o index de palavra.
         * 
         *   Caso palavra não exista em alfabeto, será retornado -1.
        */
        int get_index_palavra(char palavra);


        /**
         *  Indica se o estado é final.
        */
        bool is_final(int index_estado);


        /**
         *  Retorna a string que classifica o estado final.
        */
        std::string get_classificacao_token(int index_estado);


        /**
         *  Retorna o estado para qual o autômato transiociona partindo
         *  do estado indicado por index_estado após ler a palavra indicada
         *  por index_palavra.
        */
        std::string get_transicao(int index_estado, int index_palavra);

};

#endif