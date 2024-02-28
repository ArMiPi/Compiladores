#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix {
    public:
        Matrix(char *matrix);

        char *asString();

        float determinant();

        char *linear_system();

        Matrix add(Matrix m2);

        Matrix sub(Matrix m2);

        Matrix mul(Matrix m2);

        Matrix mul(float num);

        ~Matrix();
    
    private:
        int lines, cols;
        char ***matrix;

        char ***create_matrix(char *matrix);
};

#endif