#ifndef MATH_H
#define MATH_H

#include "HashTable.h"

bool isFloat(std::string str);

char *solveRpn(char *rpn, HashTable *hashTable, int float_precision);

char *solveSum(char *variavel, char *inf_lim, char *sup_lim, char *rpn, HashTable *hashTable, int float_precision);

char *abs(std::string valor);

char *sen(std::string valor);

char *con(std::string valor);

char *tan(std::string valor);

#endif