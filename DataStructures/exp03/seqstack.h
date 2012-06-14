#ifndef SEQSTACK_H
#define SEQSTACK_H

#include <stdlib.h>
#include "../mydef.h"

#define STACK_INIT_SIZE (100)
#define STACKINCREMENT (10)

typedef struct
{
    int *base;
    int *top;
    int stacksize;
}SqStack;

Status InitStack(SqStack *S);
Status Push(SqStack *S, int e);
Status Pop(SqStack *S, int *e);

#endif