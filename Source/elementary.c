#include "../Headers/elementary.h"

void rowInter(int row1, int row2, matrix M) {
    double* rowAux = M.body[row1];
    M.body[row1] = M.body[row2];
    M.body[row2] = rowAux;
}

void rowScalar(double k, int row, matrix A) {
    int j;
    for (j = 0; j < A.cols; j++) {
        A.body[row][j] *= k;
    }
}

void rowSumScalar(double k, int row1, int row2, matrix A) {
    int j;
    for (j = 0; j < A.cols; j++) {
        A.body[row2][j] += k * A.body[row1][j];
    }
}