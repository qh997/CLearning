#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>
#include "../mydef.h"

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

Status ListAdd_L(LinkList *L, int e);
Status ListInsert_L(LinkList *L, int i, int e);
Status GetElem_L(LinkList L, int i, int *e);
Status DestroyList_L(LinkList *L);

#endif //LINKEDLIST_H