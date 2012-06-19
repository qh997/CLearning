#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>
#include <stdarg.h>
#include "../mydef.h"

#define MAX_ARRAY_DIM (8)

typedef struct
{
    int *base;
    int dim;
    int *bounds;
    int *constants;
} Array;

Status InitArray(Array *A, int dim, ...);

#endif //ARRAY_H