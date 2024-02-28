#include "Matrix.h"
#include "StringUtils.h"

#include <vector>
#include <string>

Matrix::Matrix(char *matrix) {
    std::string str = std::string(matrix);

    std::vector<str> lins = split(str, " | ");

    size_t max = 0;
    for(int i = 0; i < lins.size(); i++) {

    }

    this->lines = lins.size() + 1;
}

Matrix::~Matrix() {

}
