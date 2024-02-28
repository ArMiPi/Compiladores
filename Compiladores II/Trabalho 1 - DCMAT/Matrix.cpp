#include "Matrix.h"
#include "StringUtils.h"

#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <cstring>

Matrix::Matrix(char *matrix) {
    std::string str = std::string(matrix);

    std::vector<std::string> lins = split(str, " | ");

    int max = 0, temp_size = 0;
    for(int i = 0; i < lins.size(); i++) {
        temp_size = std::ranges::count(lins[i], ' ');
        
        if(temp_size > max) max = temp_size;
    }

    this->lines = lins.size();
    this->cols = max + 1;
    this->matrix = createMatrix(matrix);
}

char *Matrix::asString(int float_precision) {
    std::string retorno;
    std::stringstream str_matrix;


}

char ***Matrix::createMatrix(char *matrix) {
    char ***new_matrix = (char ***) malloc(this->lines * sizeof(char **));

    /* Alocando a matriz */
    for(int i = 0; i < this->lines; i++) {
        new_matrix[i] = (char **) malloc(this->cols * sizeof(char *));

        for(int j = 0; j < this->cols; j++) {
            new_matrix[i][j] = nullptr;
        }
    }

    std::vector<std::string> mtx = split(matrix, " | ");
    std::vector<std::string> temp;
    std::string default_value = "0.0";
    for(int i = 0; i < this->lines; i++) {
        temp = split(mtx[i], " ");
        int j;
        for(j = 0; j < temp.size(); j++) {
            char *c = (char *) malloc((temp.size() + 1) * sizeof(char));

            sprintf(c, "%s", temp[j].data());

            new_matrix[i][j] = c;
        }

        while(j < this->cols) {
            char *c = (char *) malloc((default_value.size() + 1) * sizeof(char));

            sprintf(c, "%s" , default_value.data());

            new_matrix[i][j] = c;

            j++;
        }
    }

    return new_matrix;
}

int *Matrix::defineColSizes(int float_precision) {
    int *sizes = (int *) malloc(this->cols * sizeof(int));

    int max;
    for(int j = 0; j < this->cols; j++) {
        max = 0;
        for(int i = 0; i < this->lines; i++) {
            int val_size = strlen(this->matrix[i][j]);

            if(val_size > max) max = val_size;
        }

        sizes[j] = max;
    }

    return sizes;
}

Matrix::~Matrix() {
    for(int i = 0; i < this->lines; i++) {
        for(int j = 0; j < this->cols; j++) {
            free(this->matrix[i][j]);
        }

        free(this->matrix[i]);
    }

    free(this->matrix);
}
