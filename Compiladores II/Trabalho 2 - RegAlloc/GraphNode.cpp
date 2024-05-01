#include <iostream>

#include "GraphNode.h"
#include "string_utils.h"

GraphNode::GraphNode(int identifier, std::string neighbors) {
    this->identifier = identifier;
    this->neighbors = defineNeighbors(neighbors);
    this->connections = this->neighbors.size();
}

int GraphNode::getIdentifier() const {
    return this->identifier;
}

int GraphNode::getConnections() const {
    return this->connections;
}

std::vector<int> GraphNode::defineNeighbors(std::string neighbors) {
    std::vector neighbors_name = split(neighbors, " ");
    std::vector<int> neighbors_ids;

    for(std::string neighbor : neighbors_name) {
        neighbors_ids.push_back(std::atoi(neighbor.c_str()));
    }

    return neighbors_ids;
}

