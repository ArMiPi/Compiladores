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

void Matrix::formatMatrix(int float_precision) {
    std::stringstream str_floats;
    str_floats.precision(float_precision);

    bool *negatives = (bool *) malloc(this->cols * sizeof(bool));
    for(int j = 0; j < this->cols; j++) {
        negatives[j] = false;
        for(int i = 0; i < this->lines; i++) {
            if(std::string(this->matrix[i][j]).find("-") != std::string::npos)
                negatives[j] = true;
        }
    }

    float f;
    for(int j = 0; j < this->cols; j++) {
        for(int i = 0; i < this->lines; i++) {
            /* Pegar valor float e formatar corretamente */
            f = atof(this->matrix[i][j]);
            str_floats << std::fixed << f;

            /* Salvar valor formatado na matriz */
            char *c = (char *) malloc((str_floats.str().size() + 2) * sizeof(char));
            if(negatives[j] && std::string(this->matrix[i][j]).find("-") == std::string::npos) {
                sprintf(c, " %s", str_floats.str().data());
            } else {
                sprintf(c, "%s", str_floats.str().data());
            }

            free(this->matrix[i][j]);
            this->matrix[i][j] = c;

            /* Limpar a stringstream */
            str_floats.str(std::string());
        }
    }

    free(negatives);
}

char *Matrix::asString(int float_precision) {
    this->formatMatrix(float_precision);

    std::stringstream str_matrix;
    
    int size = 0;
    for(int j = 0; j < this->cols; j++) size += strlen(this->matrix[0][j]);
    size += this->cols - 1;

    str_matrix << "\n+-";
    for(int i = 0; i < size; i++) str_matrix << " ";
    str_matrix << "-+\n";
    for(int i = 0; i < this->lines; i++) {
        str_matrix << "| ";
        for(int j = 0; j < this->cols; j++) {
            str_matrix << this->matrix[i][j] << " ";
        }
        str_matrix << "|\n";
    }
    str_matrix << "+-";
    for(int i = 0; i < size; i++) str_matrix << " ";
    str_matrix << "-+\n\n";

    char *retorno = (char *) malloc((str_matrix.str().size() + 1) * sizeof(char));
    sprintf(retorno, "%s", str_matrix.str().data());

    return retorno;
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

Matrix::~Matrix() {
    for(int i = 0; i < this->lines; i++) {
        for(int j = 0; j < this->cols; j++) {
            free(this->matrix[i][j]);
        }

        free(this->matrix[i]);
    }

    free(this->matrix);
}
