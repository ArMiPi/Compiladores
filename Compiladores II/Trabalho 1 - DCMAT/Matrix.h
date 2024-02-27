#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix {
    public:
        Matrix(int flt_prc);

        Matrix(int n_lines, int n_cols, float **m, int flt_prc);

        void updateMatrix(int n_lines, int n_cols, float **m);

        char *asString();

        float determinant();

        char *linear_system();

        Matrix add(Matrix m2);

        Matrix sub(Matrix m2);

        Matrix mul(Matrix m2);

        Matrix mul(float num);

    
    private:
        int lines, cols, float_precision;
        float **matrix;

        int *alignment_measures();
};

#endif