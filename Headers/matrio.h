#ifndef MATRIO_H
#define MATRIO_H

#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

matrix readMatrixFrom(char* file);
void saveMatrixInFile(matrix A, char* file);

#endif /* MATRIO_H */