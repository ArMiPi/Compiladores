#include "Math.h"
#include "StringUtils.h"

#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <cstring>
#include <stack>

bool isFloat(std::string str) {
    std::istringstream iss(str);
    
    float f;
    iss >> std::noskipws >> f;

    return iss.eof() && !iss.fail(); 
}

char *solveRpn(char *rpn, HashTable *hashTable, int float_precision) {
    std::vector<std::string> elems = split(rpn, " ");
    std::stack<float> stck;

    for(int i = 0; i < elems.size(); i++) {
        if(elems[i].compare("+") == 0) {
            float num2 = stck.top();
            stck.pop();
            float num1 = stck.top();
            stck.pop();

            stck.push(num1 + num2);
        } else if(elems[i].compare("-") == 0) {
            float num2 = stck.top();
            stck.pop();
            float num1 = stck.top();
            stck.pop();

            stck.push(num1 - num2);
        } else if(elems[i].compare("/") == 0) {
            float num2 = stck.top();
            stck.pop();
            float num1 = stck.top();
            stck.pop();

            if(num2 == 0) {
                char *c = (char *) malloc((strlen("inf") + 1) * sizeof(char));
                sprintf(c, "inf");

                return c;
            }

            stck.push(num1 / num2);
        } else if(elems[i].compare("*") == 0) {
            float num2 = stck.top();
            stck.pop();
            float num1 = stck.top();
            stck.pop();

            stck.push(num1 * num2);
        } else if(elems[i].compare("%") == 0) {
            float num2 = stck.top();
            stck.pop();
            float num1 = stck.top();
            stck.pop();

            stck.push(fmod(num1, num2));
        } else if(elems[i].compare("^") == 0) {
            float num2 = stck.top();
            stck.pop();
            float num1 = stck.top();
            stck.pop();

            stck.push(pow(num1, num2));
        } else if(elems[i].compare("SEN") == 0) {
            float num = stck.top();
            stck.pop();

            stck.push(sin(num));
        } else if(elems[i].compare("COS") == 0) {
            float num = stck.top();
            stck.pop();

            stck.push(cos(num));
        } else if(elems[i].compare("TAN") == 0) {
            float num = stck.top();
            stck.pop();

            stck.push(tan(num));
        } else if(elems[i].compare("ABS") == 0) {
            float num = stck.top();
            stck.pop();
            num = (num < 0) ? num * -1 : num;
            
            stck.push(num);
        } else if(isFloat(elems[i])) {
            stck.push(atof(elems[i].data()));
        } else {
            /* Procurar por variável na hash table */
            HashItem *it = hashTable->get(elems[i].data());

            /* Variável não declarada */
            if(!it) {
                return "";
            }

            /* Variável encontrada mas é uma matriz */
            std::string type = hashTable->getHItemType(it);
            if(type.compare("matrix") == 0) {
                return "";
            }

            float f = atof((char *)hashTable->getHItemValue(it));

            stck.push(f);
        }
    }
    
    float res = stck.top();
    std::stringstream ss;
    ss.precision(float_precision);
    ss << std::fixed << res;

    char *c = (char *) malloc((ss.str().size() + 1) * sizeof(char));
    sprintf(c, "%s", ss.str().data());

    return c;
}

char *abs(std::string valor) {
    float result = atof(valor.data());

    result = (result < 0) ? -1.0 * result : result;

    std::stringstream ss;

    ss << result;

    char *c = (char *) malloc((ss.str().size() + 1) * sizeof(char));
    sprintf(c, "%s", ss.str().data());

    return c;
}

char *sen(std::string valor) {
    float result = atof(valor.data());

    result = sin(result);

    std::stringstream ss;

    ss << result;

    char *c = (char *) malloc((ss.str().size() + 1) * sizeof(char));
    sprintf(c, "%s", ss.str().data());

    return c;
}

char *con(std::string valor) {
    float result = atof(valor.data());

    result = cos(result);

    std::stringstream ss;

    ss << result;

    char *c = (char *) malloc((ss.str().size() + 1) * sizeof(char));
    sprintf(c, "%s", ss.str().data());

    return c;
}

char *tan(std::string valor) {
    float result = atof(valor.data());

    result = tan(result);

    std::stringstream ss;

    ss << result;

    char *c = (char *) malloc((ss.str().size() + 1) * sizeof(char));
    sprintf(c, "%s", ss.str().data());

    return c;
}
