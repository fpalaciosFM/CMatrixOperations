#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct matrix {
    int rows;
    int cols;
    double** body;
};

typedef struct matrix matrix;

matrix zeros(int rows, int cols);
matrix zerosSquare(int size);
matrix identity(int size);
matrix randomMatrix(int rows, int cols, int min, int max);
matrix randomSquare(int size, int min, int max);
matrix matAdd(matrix A, matrix B);
matrix matMul(matrix A, matrix B);
matrix matCopy(matrix A);
void printMatrix(matrix M);

#endif /* MATRIX_H */