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

float calc2x2determinant(char ***matrix, std::vector<int> validLins, std::vector<int> validCols) {
    /**
     * | a b | = (a*d) - (b*c)
     * | c d |
    */
    float a = atof(matrix[validLins[0]][validCols[0]]);
    float b = atof(matrix[validLins[0]][validCols[1]]);
    float c = atof(matrix[validLins[1]][validCols[0]]);
    float d = atof(matrix[validLins[1]][validCols[1]]);

    return (a*d) - (b*c);
}

float calc_determinant(char ***matrix, int size, std::vector<int> validLins, std::vector<int> validCols) {
    if(size == 1) {
        return atof(matrix[validLins[0]][validCols[0]]);
    } else if(size == 2) {
        return calc2x2determinant(matrix, validLins, validCols);
    }

    int lin = validLins[0];
    int col;
    validLins.erase(std::remove(validLins.begin(), validLins.end(), lin), validLins.end());
    std::vector<int> cs;
    float det = 0;
    for(int i = 0; i < validCols.size(); i++) {
        cs = validCols;
        col = cs[i];

        cs.erase(std::remove(cs.begin(), cs.end(), col), cs.end());

        if(i % 2 == 0) {
            det += calc_determinant(matrix, size - 1, validLins, cs);
        } else {
            det -= calc_determinant(matrix, size - 1, validLins, cs);
        }
    }

    return det;
}

char *Matrix::determinant(int float_precision) {
    if(this->lines != this->cols) {
        char *c = (char *) malloc((strlen("0.0") + 1) * sizeof(char));
        sprintf(c, "0.0");
        return c;
    }
    
    std::vector<int> validLins, validCols;
    for(int i = 0; i < this->cols; i++) {
        validLins.push_back(i);
        validCols.push_back(i);
    }


    float det = calc_determinant(this->matrix, this->cols, validLins, validCols);

    std::stringstream ss;
    ss.precision(float_precision);
    ss << std::fixed << det;

    char *c = (char *) malloc((ss.str().size() + 1) * sizeof(char));
    sprintf(c, "%s", ss.str().data());

    return c;
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
