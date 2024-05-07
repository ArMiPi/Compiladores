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

bool isSpill(virtualRegister vr1, virtualRegister vr2);
int getSpillPosition(std::vector<virtualRegister> vrs, std::vector<int> allocations);

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

    // Inicializar registers
    std::vector<int> registers;
    for(virtualRegister vr: vrs) {
        registers.push_back(-1);
    }

    std::vector<std::vector<int>> spills;
    for(int i = number_of_registers; i > 1; i--) {
        spills.push_back({});
    }

    std::vector<int> allocations;
    std::vector<int> regs;
    int time, free_location, spill_pos, interation;
    for(int i = number_of_registers; i > 1; i--) {
        std::cout << "K = " << i << std::endl;
        std::cout << std::endl;

        regs = registers;
        allocations = {};
        for(int j = 0; j < i; j++) {
            allocations.push_back(-1);
        }

        time = 1;
        interation = 0;
        free_location = 0;
        for(virtualRegister vr : vrs) {
            while(vr.start != time) {
                // "Acertar" o tempo
                time++;
            }

            // Remover não mais utilizáveis
            free_location = i;
            for(int j = allocations.size() - 1; j >= 0; j--) {
                if(allocations[j] == -1) {
                    free_location = j;
                    continue;
                }

                if(vrs[allocations[j]].end <= time) {
                    allocations[j] = -1;
                    free_location = j;
                }
            }

            // Tentar alocar registrador
            // SPILL
            if(free_location == i) {
                spill_pos = getSpillPosition(vrs, allocations);

                if(isSpill(vr, vrs[allocations[spill_pos]])) {
                    regs[vr.id] = -1;
                } else {
                    regs[allocations[spill_pos]] = -1;
                    regs[vr.id] = spill_pos;
                    allocations[spill_pos] = vr.id;
                }

                spills[number_of_registers - i].push_back(interation);
            } else {
                allocations[free_location] = vr.id;
                regs[vr.id] = free_location;
            }

            interation++;
        }

        for(int j = 0; j < regs.size(); j++) {
            std::cout << vrs[j].name << ": ";
            
            if(regs[j] == -1) {
                std::cout << "SPILL" << std::endl;
            } else {
                std::cout << regs[j] << std::endl;
            }
        }

        std::cout << "----------------------------------------" << std::endl;
    }

    std::cout << "----------------------------------------";
    for(int i = number_of_registers; i > 1; i--) {
        std::cout << std::endl;
        std::cout << "K = " << i << ": ";
        
        if(spills[number_of_registers - i].size()) {
            std::cout << "SPILL on interation(s): " << spills[number_of_registers - i][0];

            for(int j = 1; j < spills[number_of_registers - i].size(); j++) {
                std::cout << ", ";
                std::cout << spills[number_of_registers - i][j];
            }
        } else {
            std::cout << "Successful Allocation";
        }
    }

    return 0;
}

/**
 * Retorna true se vr1 deve ser utilizado como spill,
 * false caso contrário
*/
bool isSpill(virtualRegister vr1, virtualRegister vr2) {
    int interval1, interval2;
    
    if(vr1.end > vr2.end) return true;
    
    if(vr1.end == vr2.end) {
        interval1 = vr1.end - vr1.start;
        interval2 = vr2.end - vr2.start;

        if(interval1 < interval2) return true;
        
        if(interval1 == interval2) {
            if(vr1.id > vr2.id) return true;
        }
    }

    return false;
}

int getSpillPosition(std::vector<virtualRegister> vrs, std::vector<int> allocations) {
    int pos = 0;
    for(int i = 1; i < allocations.size(); i++) {
        if(isSpill(vrs[allocations[i]], vrs[allocations[pos]])) {
            pos = i;
        }
    }

    return pos;
}
