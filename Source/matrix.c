#include "../Headers/matrix.h"

matrix zeros(int rows, int cols) {
    matrix M;
    M.rows = rows;
    M.cols = cols;
    M.body = malloc(rows * sizeof(double*));

    int i, j;
    for (i = 0; i < rows; i++) {
        M.body[i] = malloc(cols * sizeof(double));
        for (j = 0; j < cols; j++) {
            M.body[i][j] = 0;
        }
    }

    return M;
}

matrix zerosSquare(int size) {
    return zeros(size, size);
}

matrix identity(int size) {
    matrix M;
    M.cols = M.rows = size;
    M.body = malloc(size * sizeof(double*));

    int i, j;
    for (i = 0; i < size; i++) {
        M.body[i] = malloc(size * sizeof(double));
        for (j = 0; j < size; j++) {
            M.body[i][j] = i == j;
        }
    }

    return M;
}

matrix randomMatrix(int rows, int cols, int min, int max) {
    int interval_lenght = max - min;
    matrix M;
    M.rows = rows;
    M.cols = cols;
    M.body = malloc(rows * sizeof(double*));

    int i, j;
    for (i = 0; i < rows; i++) {
        M.body[i] = malloc(cols * sizeof(double));
        for (j = 0; j < cols; j++) {
            M.body[i][j] = min + random() % (interval_lenght + 1);
        }
    }

    return M;
}

matrix randomSquare(int size, int min, int max) {
    return randomMatrix(size, size, min, max);
}

matrix matAdd(matrix A, matrix B) {
    matrix M;
    M.rows = A.rows;
    M.cols = A.cols;
    M.body = malloc(A.rows * sizeof(double*));

    int i, j;
    for (i = 0; i < A.rows; i++) {
        M.body[i] = malloc(A.cols * sizeof(double));
        for (j = 0; j < A.cols; j++) {
            M.body[i][j] = A.body[i][j] + B.body[i][j];
        }
    }

    return M;
}

matrix matMul(matrix A, matrix B) {
    matrix M;
    M.rows = A.rows;
    M.cols = B.cols;
    M.body = malloc(M.rows * sizeof(double*));

    int i, j, k;
    for (i = 0; i < M.rows; i++) {
        M.body[i] = malloc(M.cols * sizeof(double));
        for (j = 0; j < M.cols; j++) {
            M.body[i][j] = 0;
            for (k = 0; k < A.cols; k++) {
                M.body[i][j] += A.body[i][k] * B.body[k][j];
            }
        }
    }

    return M;
}

matrix matCopy(matrix A) {
    matrix M;
    M.rows = A.rows;
    M.cols = A.cols;
    M.body = malloc(M.rows * sizeof(double*));

    int i, j;
    for (i = 0; i < M.rows; i++) {
        M.body[i] = malloc(M.cols * sizeof(double));
        for (j = 0; j < M.cols; j++) {
            M.body[i][j] = A.body[i][j];
        }
    }

    return M;
}

void printMatrix(matrix M) {
    int i, j;
    for (i = 0; i < M.rows; i++) {
        for (j = 0; j < M.cols; j++) {
            printf("%lf\t ", M.body[i][j]);
        }
        printf("\n");
    }
}
