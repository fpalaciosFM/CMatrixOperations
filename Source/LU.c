#include "../Headers/LU.h"

void decompose_LU(matrix L, matrix U) {
    double k;
    int i, j;
    for (i = 0; i < L.rows; i++) {
        for (j = 0; j < i; j++) {
            k = U.body[i][j] / U.body[j][j];
            L.body[i][j] = k;
            rowSumScalar(-k, j, i, U);
        }
    }
}


void decompose_ALU(matrix A, matrix* L, matrix* U) {
    *L = identity(A.rows);
    *U = matCopy(A);
    decompose_LU(*L, *U);
}