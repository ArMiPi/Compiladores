#include "Matrix.h"

Matrix::Matrix(int flt_prc) {
    lines = 0;
    cols = 0;
    matrix = nullptr;
    float_precision = flt_prc;
}

Matrix::Matrix(int n_lines, int n_cols, float **m, int flt_prc) {
    lines = n_lines;
    cols = n_cols;
    matrix = m;
    float_precision = flt_prc;
}

void Matrix::updateMatrix(int n_lines, int n_cols, float **m) {
    if(matrix) {
        for(int i = 0; i < lines; i++) {
            free(matrix[i]);
        }

        free(matrix);
    }

    lines = n_lines;
    cols = n_cols;
    matrix = m;
}

int *Matrix::alignment_measures() {
    int *measures = (int *) malloc(cols * sizeof(int));
    if(!measures) {
        std::cout << "Não foi possível alocar -- Matrix::alignment_measures\n";
    }

    for(int col = 0; col < cols; col++) {
        for(int lin = 0; lin < lines; lin++) {

        }
    }
}

char *Matrix::asString() {

}
