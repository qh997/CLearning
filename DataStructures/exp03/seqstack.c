#include "seqstack.h"

Status InitStack(SqStack *S)
{
    S->base = (int *)malloc(STACK_INIT_SIZE * sizeof(int));
    if (NULL == S->base)
        return OVERFLOW;

    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;

    return OK;
}

Status Push(SqStack *S, int e)
{
    if (S->top - S->base >= S->stacksize)
    {
        int *tmp;
        if (NULL == (tmp = (int *)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(int))))
            return OVERFLOW;

        S->base = tmp;
        S->top = S->base + S->stacksize;
        S->stacksize += STACKINCREMENT;
    }

    *S->top++ = e;

    return OK;
}

Status Pop(SqStack *S, int *e)
{
    if (S->top <= S->base)
        return ERROR;

    *e = *--S->top;

    return OK;
}