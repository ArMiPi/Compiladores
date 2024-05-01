#ifndef GRAPHNODE_H
#define GRAPHNODE_H

#include <string>
#include <vector>

class GraphNode
{
    public:
        GraphNode(int identifier, std::string neighbors);

        int getIdentifier() const;

        int getConnections() const;
        
    private:
        int identifier, connections;
        std::vector<int> neighbors;

        std::vector<int> defineNeighbors(std::string neighbors);
};

#endif
