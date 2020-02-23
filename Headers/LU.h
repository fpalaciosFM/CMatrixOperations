#ifndef LU_H
#define LU_H

#include "elementary.h"

void decompose_LU(matrix L, matrix U);
void decompose_ALU(matrix A, matrix* L, matrix* U);
void decompose_PLU(matrix P, matrix L, matrix U);
void decompose_PALU(matrix* P, matrix A, matrix* L, matrix* U);

#endif /* LU_H */