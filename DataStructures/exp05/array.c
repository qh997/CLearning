#include "array.h"

Status InitArray(Array *A, int dim, ...)
{
    if (1 > dim || MAX_ARRAY_DIM < dim)
        return ERROR;

    A->dim = dim;
    if (NULL == (A->bounds = (int *)malloc(dim * sizeof(int))))
        return OVERFLOW;

    int elemtotal = 1;
    va_list ap;
    va_start(ap, dim);
    for (int i = 0; i < dim; i++)
    {
        A->bounds[i] = va_arg(ap, int);
        if (A->bounds[i] < 0)
            return ERROR;
        elemtotal *= A->bounds[i];
    }
    va_end(ap);

    if (NULL == (A->base = (int *)malloc(elemtotal * sizeof(int))))
        return OVERFLOW;

    if (NULL == (A->constants = (int *)malloc(dim * sizeof(int))))
        return OVERFLOW;

    A->constants[dim - 1] = 1;
    for (int i = dim - 2; i >= 0; i--)
    {
        A->constants[i] = A->bounds[i + 1] * A->constants[i + 1];
    }

    return OK;
}