#include <list>
#include <iostream>

#include "string_utils.h"

/**
 * Returns how many times target appears in str.
*/
size_t ocurrencies(std::string str, std::string target) {
    std::string temp {str};
    int quantity {0};
    int occurency = contains(temp, target);

    while(occurency != -1) {
        quantity++;

        temp = temp.substr(occurency+target.size(), temp.size());

        occurency = contains(temp, target);
    }

    return quantity;
}


int contains(std::string str, std::string target) {
    size_t str_size = str.size();
    size_t target_size = target.size();

    // Checking if entry is valid
    if(!str_size || !target_size || str_size < target_size) {
        return -1;
    }

    for(size_t i {0}, j {0}; i < str_size; i++) {
        // If a char from str is in target
        if(str[i] == target[j]) {
            j++;
        }
        else {
            j = 0;
        }

        // If target is found in str
        if(j == target_size) {
            return i - j + 1;
        }
    }

    return -1;
}


std::string **split(std::string str, std::string splitter) {
    int substrings = ocurrencies(str, splitter);

    std::string **splt = new std::string *[substrings+2];

    std::string temp {str};
    int next = contains(str, splitter);
    int pos {0};

    while(next != -1) {
        splt[pos] = new std::string(temp.substr(0, next));
        pos++;

        temp = temp.substr(next+splitter.size(), temp.size());

        next = contains(temp, splitter);
    }

    splt[pos] = new std::string(temp);
    splt[pos+1] = nullptr;

    return splt;
}


bool is_in_interval(char letter, std::string interval) {
    std::string **splt = split(interval, "-");
    char min {splt[0][0][0]};
    char max {splt[1][0][0]};

    bool is_in = (letter >= min && letter <= max);
    
    for(size_t i {0}; splt[i]; i++) delete[] splt[i];
    delete[] splt;
    
    return is_in;
}
