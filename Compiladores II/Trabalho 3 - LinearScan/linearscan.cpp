#include <iostream>
#include <string>
#include <vector>

#include "string_utils.h"

struct virtualRegister
{
    int id;
    std::string name;
    int start, end;
};


int main() {
    int pos;
    std::string line;
    std::vector<virtualRegister> vrs;
    std::vector<std::string> splitted_command;
    std::vector<std::string> splitted_interval;
    int controller = 0, number_of_registers = 0;
    while(std::getline(std::cin, line)) {
        if(controller == 0) {
            splitted_command = split(line, "=");

            number_of_registers = std::atoi(splitted_command[1].c_str());
        } else {
            splitted_command = split(line, " --> ");
            splitted_interval = split(splitted_command[1], " ");

            vrs.push_back(virtualRegister());

            pos = controller - 1;
            vrs[pos].id = pos;
            vrs[pos].name = splitted_command[0];
            vrs[pos].start = std::atoi(splitted_interval[0].c_str());
            vrs[pos].end = std::atoi(splitted_interval[1].c_str());
        }

        controller++;
    }

    std::cout << "fim" << std::endl;
}
