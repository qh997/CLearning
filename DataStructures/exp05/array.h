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
Status DestroyArray(Array *A);
Status Locate(const Array *A, va_list ap, int *off);
Status Value(const Array *A, int *e, ...);
Status Assign(Array *A, int e, ...);

#endif //ARRAY_H