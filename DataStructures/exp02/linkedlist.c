#include "linkedlist.h"

Status ListAdd_L(LinkList *L, int e)
{
    while (NULL != *L)
        L = &(*L)->next;

    if (NULL == (*L = (LinkList)malloc(sizeof(LNode))))
        return OVERFLOW;

    (*L)->data = e;
    (*L)->next = NULL;

    return OK;
}

Status ListInsert_L(LinkList *L, int i, int e)
{
    if (0 > i || NULL == *L)
        return ERROR;

    while (--i > 0 && NULL != (*L)->next)
        L = &(*L)->next;

    if (0 < i)
        return ERROR;
    else
    {
        LinkList p_insert = NULL;
        if (NULL == (p_insert = (LinkList)malloc(sizeof(LNode))))
            return OVERFLOW;
        
        p_insert->data = e;

        if (0 > i)
        {
            p_insert->next = *L;
            *L = p_insert;
        }
        else
        {
            p_insert->next = (*L)->next;
            (*L)->next = p_insert;
        }
    }

    return OK;
}

Status GetElem_L(LinkList L, int i, int *e)
{
    while (NULL != L->next && i >= 0)
    {
        L = L->next;
        --i;
    }

    if (i > 0)
        return ERROR;
    else
        *e = L->data;

    return OK;
}