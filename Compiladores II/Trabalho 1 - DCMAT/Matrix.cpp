#include "Matrix.h"
#include "StringUtils.h"

#include <vector>
#include <string>
#include <algorithm>

Matrix::Matrix(char *matrix) {
    std::string str = std::string(matrix);

    std::vector<std::string> lins = split(str, " | ");

    int max = 0, temp_size = 0;
    for(int i = 0; i < lins.size(); i++) {
        temp_size = std::ranges::count(lins[i], ' ');
        
        if(temp_size > max) max = temp_size;
    }

    this->lines = lins.size() + 1;
    this->cols = max + 1;
    this->matrix = create_matrix(matrix);
}

char ***Matrix::create_matrix(char *matrix) {
    char ***new_matrix = (char ***) malloc(this->lines * sizeof(char **));

    /* Alocando a matriz */
    for(int i = 0; i < this->lines; i++) {
        new_matrix[i] = (char **) malloc(this->cols * sizeof(char *));

        for(int j = 0; j < this->cols; j++) {
            new_matrix[i][i] = nullptr;
        }
    }

    /* Preenchendo a matriz */
    size_t start = 0, end;
    int i = 0, j = 0;
    std::string temp_matrix = std::string(matrix);
    std::string moc = "0.0";
    std::string temp;
    std::string splitter = " ";
    while((end = temp_matrix.find(splitter, start)) != std::string::npos) {
        temp = temp_matrix.substr(start, end - start);

        if(temp.compare("|") == 0) {
            while(j < this->cols) {
                char *val = (char *) malloc((moc.size() + 1) * sizeof(char));
                sprintf(val, "%s", moc);

                new_matrix[i][j] = val;

                j++;
            }

            i++;
        } else {
            char *val = (char *) malloc((temp.size() + 1) * sizeof(char));
            sprintf(val, "%s", temp);

            new_matrix[i][j] = val;

            j++;
        }
        start = end + splitter.size();
    }

    temp = temp_matrix.substr(start);
    char *val = (char *) malloc((temp.size() + 1) * sizeof(char));
    sprintf(val, "%s", temp);

    new_matrix[this->lines -1][this->cols - 1] = val;

    return new_matrix;
}

Matrix::~Matrix() {

}
