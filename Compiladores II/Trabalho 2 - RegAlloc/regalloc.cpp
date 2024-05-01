#include <iostream>
#include <string>
#include <vector>
#include <stack>

#include "string_utils.h"
#include "Graph.h"

std::stack<int> simplify(Graph graph, int k);

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

    std::stack<int> pilha;
    for(int i = number_of_colors; i > 1; i--) {
        std::cout << multilines << std::endl;
        std::cout << "K = " << number_of_colors << std::endl;
        std::cout << std::endl;

        // INICIAR SIMPLIFY && POTENTIAL SPILL
        pilha = simplify(graph, number_of_colors);
    }

    std::cout << "fim" << std::endl;
}

std::stack<int> simplify(Graph graph, int k) {
    

    return {};
}
