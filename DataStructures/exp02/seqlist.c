#include "seqlist.h"

Status InitList_Sq(SqList *L)
{
    if (NULL == (L->elem = (int *)malloc(LIST_INIT_SIZE * sizeof(int))))
        return OVERFLOW;

    L->length = 0;
    L->listsize = LIST_INIT_SIZE;

    return OK;
}

Status ListInsert_Sq(SqList *L, int i, int e)
{
    if (i < 0 || i > L->length)
        return ERROR;

    if (L->length >= L->listsize)
    {
        int *newbase = NULL;
        if (NULL == (newbase = (int *)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(int))))
        {
            return OVERFLOW;
        }

        L->elem = newbase;
        L->listsize += LISTINCREMENT;
    }

    if (0 == L->length)
    {
        *(L->elem) = e;
    }
    else
    {
        int *q = L->elem + i;
        for (int *p = L->elem + L->length - 1; p >= q; --p)
            *(p + 1) = *p;

        *q = e;
    }

    ++L->length;

    return OK;
}

Status ListDelete_Sq(SqList *L, int i, int *e)
{
    if (i < 0 || i > L->length - 1)
        return ERROR;

    int *p = L->elem + i;
    if (NULL != e)
        *e = *p;

    for (; p < L->elem + L->length; p++)
    {
        *p = *(p + 1);
    }

    --L->length;

    return OK;
}