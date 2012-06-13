#ifndef SEQLIST_H
#define SEQLIST_H

#include <stdlib.h>
#include "../mydef.h"

#define LIST_INIT_SIZE (100)
#define LISTINCREMENT (10)

typedef struct
{
    int *elem;
    int length;
    int listsize;
} SqList;

extern Status InitList_Sq(SqList *L);
extern Status ListInsert_Sq(SqList *L, int i, int e);
extern Status ListDelete_Sq(SqList *L, int i, int *e);

#endif //SEQLIST_H