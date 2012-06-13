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

    if (1 < i)
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
        else if (i == 1)
        {
            (*L)->next = p_insert;
            p_insert->next = NULL;
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

Status DestroyList_L(LinkList *L)
{
    if (NULL == *L)
        return OK;
    else
    {
        DestroyList_L(&(*L)->next);
        free(*L);
        *L = NULL;
    }

    return OK;
}