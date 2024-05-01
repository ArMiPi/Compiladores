#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

#include "string_utils.h"
#include "Graph.h"

std::vector<int> simplify(Graph graph, int k);
bool select(Graph graph, std::vector<int> pilha, int k);
bool comparator_min(const GraphNode& node1, const GraphNode& node2);
bool comparator_max(const GraphNode& node1, const GraphNode& node2);
int getMinNode(std::vector<GraphNode> nodes);
int getMaxNode(std::vector<GraphNode> nodes);
std::vector<GraphNode> updateNodes(std::vector<GraphNode> nodes, int id);

int main() {
    // BUILD
    Graph graph;
    std::string line;
    int controller = 0, number_of_colors = 0;
    std::vector<std::string> splitted_command;
    while(std::getline(std::cin, line)) {
        if(controller == 0) {
            // Nome do grafo
            splitted_command = split(line, " ");
            
            graph = Graph(std::atoi(splitted_command[1].c_str()));
        } else if (controller == 1) {
            splitted_command = split(line, "=");

            number_of_colors = std::atoi(splitted_command[1].c_str());
        } else {
            splitted_command = split(line, " --> ");

            graph.insertNode(std::atoi(splitted_command[0].c_str()), splitted_command[1]);
        }

        controller++;
    }

    // INICIAR RELATÓRIO
    std::string multilines = "----------------------------------------";
    std::cout << "Graph " << graph.getIdentifier();
    std::cout << " -> Physical Registers: " << number_of_colors << std::endl;
    std::cout << multilines << std::endl;
    
    std::vector<int> pilha;
    bool completed;
    std::vector<bool> allocations;
    for(int i = number_of_colors; i > 1; i--) {
        std::cout << multilines << std::endl;
        std::cout << "K = " << i << std::endl;
        std::cout << std::endl;

        // INICIAR SIMPLIFY && POTENTIAL SPILL
        pilha = simplify(graph, i);

        // INICIAR SELECT/ASSIGN && SPILL
        completed = select(graph, pilha, i);
        
        allocations.push_back(completed);
    }

    std::cout << multilines << std::endl;
    std::cout << multilines << std::endl;

    int i = number_of_colors;
    for(bool success: allocations) {
        std::cout << "Graph " << graph.getIdentifier() << " -> K = ";
        std::cout << i << ": ";

        if(success) {
            std::cout << "Successful Allocation";
        } else {
            std::cout << "SPILL";
        }

        std::cout << std::endl;

        i--;
    }
}

std::vector<int> simplify(Graph graph, int k) {
    std::vector<GraphNode> nodes = graph.getNodes();
    std::vector<int> pilha;

    int pos, id;
    while(nodes.size()) {
        pos = getMinNode(nodes);

        std::cout << "Push: ";
        if(nodes[pos].getConnections() >= k) {
            pos = getMaxNode(nodes);
            id = nodes[pos].getIdentifier();

            std::cout << id << " *" << std::endl;
        } else {
            id = nodes[pos].getIdentifier();

            std::cout << id << std::endl;
        }

        pilha.insert(pilha.begin(), id);

        nodes = updateNodes(nodes, id);
    }

    return pilha;
}

bool select(Graph graph, std::vector<int> pilha, int k) {
    std::map<int, int> colors;
    std::vector<bool> cores_possiveis;
    for(int i = 0; i < k; i++) {
        colors.insert(std::make_pair(i, i));
        cores_possiveis.push_back(true);
    }

    GraphNode node;
    int color_picked;
    std::map<int, int>::const_iterator pos;
    std::vector<bool>::iterator it;
    for(int id: pilha) {
        node = graph.getNodeById(id);

        // Verificar quais as cores possíveis de serem utilizadas
        for(int neighbor: node.getNeighbors()) {
            pos = colors.find(neighbor);

            if(pos != colors.end()) {
                cores_possiveis[pos->second] = false;
            }
        }

        // Verificar se todas as opções de cores são false
        std::cout << "Pop: " << id << " -> ";
        it = std::find(begin(cores_possiveis), end(cores_possiveis), true);
        if (it == end(cores_possiveis)) {
            std::cout << "NO COLOR AVAILABLE" << std::endl;
            return false;
        }

        color_picked = it - cores_possiveis.begin();
        colors.insert(std::make_pair(id, color_picked));

        std::cout << color_picked << std::endl;

        for(int i = 0; i < k; i++) {
            cores_possiveis[i] = true;
        }
    }

    return true;
}

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

int getMinNode(std::vector<GraphNode> nodes) {
    auto minimo = std::min_element(nodes.begin(), nodes.end(), comparator_min);
    
    return std::distance(nodes.begin(), minimo);
}

int getMaxNode(std::vector<GraphNode> nodes) {
    auto maximo = std::min_element(nodes.begin(), nodes.end(), comparator_max);
    
    return std::distance(nodes.begin(), maximo);
}

std::vector<GraphNode> updateNodes(std::vector<GraphNode> nodes, int id) {
    std::vector<GraphNode> retorno;
    std::vector<int> vec;

    for(GraphNode node: nodes) {
        vec = node.getNeighbors();
        if (std::find(vec.begin(), vec.end(), id) != vec.end()) {
            node.setConnections(node.getConnections() - 1);
        }

        if(node.getIdentifier() != id) {
            retorno.push_back(node);
        }
    }

    return retorno;
}
