#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>
#include "../mydef.h"

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

extern Status ListAdd_L(LinkList *L, int e);
extern Status ListInsert_L(LinkList *L, int i, int e);
extern Status GetElem_L(LinkList L, int i, int *e);

#endif //LINKEDLIST_H