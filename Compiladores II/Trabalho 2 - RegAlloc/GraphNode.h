#ifndef GRAPHNODE_H
#define GRAPHNODE_H

#include <string>
#include <vector>

class GraphNode
{
    public:
        GraphNode() = default;
        
        GraphNode(int identifier, std::string neighbors);

        int getIdentifier() const;

        int getConnections() const;

        void setConnections(int connections);

        std::vector<int> getNeighbors();

    private:
        int identifier, connections;
        std::vector<int> neighbors;

        std::vector<int> defineNeighbors(std::string neighbors);
};

#endif
