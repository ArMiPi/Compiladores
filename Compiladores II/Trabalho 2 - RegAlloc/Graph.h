#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>

#include "GraphNode.h"

class Graph {
    public:
        Graph() = default;

        Graph(int identifier);

        int getIdentifier();

        /**
         *  Adiciona no grafo o nó com id `nodeId` e vizinhos `neighbors`.
         * 
         * Os vizinhos devem ser identificados por seus respectivos ids separados
         * por um espaço em branco.
        */
        void insertNode(int nodeId, std::string neighbors);

        /**
         * Retorna a posição do nó com o menor número de conexões, 
         * caso ocorra um empate, será retornado, dentre esses nós, 
         * o com o menor id
        */
        int getMinNode();

        /**
         * Retorna a posição do nó com o maior número de conexões, 
         * caso ocorra um empate, será retornado, dentre esses nós, 
         * o com o menor id
        */
        int getMaxNode();

        std::vector<GraphNode> getNodes();

    private:
        int identifier;
        std::vector<GraphNode> nodes;
};

#endif
