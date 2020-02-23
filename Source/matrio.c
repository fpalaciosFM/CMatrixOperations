#include "../Headers/matrio.h"

matrix readMatrixFrom(char* fileName) {
    FILE* filePointer = fopen(fileName, "r");

    if (!filePointer) {
        printf("Hubo un error al intentar abrir el archivo \"%s\".", fileName);
        return zerosSquare(1);
    }

    int rows, cols;
    fscanf(filePointer, "%d %d", &rows, &cols);

    matrix M;
    M.rows = rows;
    M.cols = cols;
    M.body = (double**)malloc(rows * sizeof(double*));

    int i, j;
    for (i = 0; i < rows; i++) {
        M.body[i] = (double*)malloc(cols * sizeof(double));
        for (j = 0; j < cols; j++) {
            fscanf(filePointer, "%lf", &M.body[i][j]);
        }
    }

    return M;
}

void saveMatrixInFile(matrix A, char* fileName) {
    FILE* filePointer = fopen(fileName, "w");

    if (!filePointer) {
        printf("Error al intentar escribir en el archivo \"%s\"", fileName);
        return;
    }

    fprintf(filePointer, "%d %d\n", A.rows, A.cols);
    int i, j;
    for (i = 0; i < A.rows; i++) {
        for (j = 0; j < A.cols; j++) {
            fprintf(filePointer, "%lf ", A.body[i][j]);
        }
        fprintf(filePointer, "\n");
    }
}