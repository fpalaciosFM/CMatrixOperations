#include <stdio.h>
#include <stdlib.h>

#include "Headers/LU.h"
#include "Headers/elementary.h"
#include "Headers/matrio.h"

int main() {
    srand(time(NULL));

    int size = 4;
    matrix A = randomSquare(size, 1, 9);
    matrix L, U;
    decompose_ALU(A, &L, &U);
    // matrix L = identity(size);
    // matrix U = matCopy(A);
    // decompose_LU(L, U);

    printf("\nA:\n");
    printMatrix(A);
    printf("\nL:\n");
    printMatrix(L);
    printf("\nU:\n");
    printMatrix(U);
    printf("\nLU:\n");
    printMatrix(matMul(L, U));

    return 0;
}