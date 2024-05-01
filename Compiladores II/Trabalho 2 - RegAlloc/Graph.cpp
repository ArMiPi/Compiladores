#include <iostream>

#include "Graph.h"

Graph::Graph(int identifier) {
    this->identifier = identifier;
    this->nodes = std::vector<GraphNode>();
}

int Graph::getIdentifier() {
    return this->identifier;
}

GraphNode Graph::getNodeById(int id) {
    for(GraphNode node: nodes) {
        if(node.getIdentifier() == id) {
            return node;
        }
    }
    return {};
}

void Graph::insertNode(int nodeId, std::string neighbors) {
    this->nodes.push_back(GraphNode(nodeId, neighbors));
}

std::vector<GraphNode> Graph::getNodes() {
    return this->nodes;
}
