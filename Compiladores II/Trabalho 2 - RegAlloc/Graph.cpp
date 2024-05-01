#include <iostream>

#include "Graph.h"

bool comparator_min(const GraphNode& node1, const GraphNode& node2) {
    if(node1.getConnections() == node2.getConnections()) {
        return node1.getIdentifier() < node2.getIdentifier();
    }

    return node1.getConnections() < node2.getConnections();
}

bool comparator_max(const GraphNode& node1, const GraphNode& node2) {
    if(node1.getConnections() == node2.getConnections()) {
        return node1.getIdentifier() > node2.getIdentifier();
    }

    return node1.getConnections() < node2.getConnections();
}

Graph::Graph(int identifier) {
    this->identifier = identifier;
    this->nodes = std::vector<GraphNode>();
}

int Graph::getIdentifier() {
    return this->identifier;
}

void Graph::insertNode(int nodeId, std::string neighbors) {
    this->nodes.push_back(GraphNode(nodeId, neighbors));
}

int Graph::getMinNode() {
    auto minimo = std::min_element(this->nodes.begin(), this->nodes.end(), comparator_min);
    
    return std::distance(this->nodes.begin(), minimo);
}

int Graph::getMaxNode() {
    auto maximo = std::min_element(this->nodes.begin(), this->nodes.end(), comparator_max);
    
    return std::distance(this->nodes.begin(), maximo);
}

std::vector<GraphNode> Graph::getNodes() {
    return this->nodes;
}
