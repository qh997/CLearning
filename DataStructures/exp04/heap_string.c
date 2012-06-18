#include "heap_string.h"

Status InitStr(HString *T)
{
    T->ch = NULL;
    T->length = 0;

    return OK;
}

Status StrAssign(HString *T, const char *str)
{
    if (NULL == str)
        return ERROR;

    if (NULL != T->ch)
    {
        free(T->ch);
        T->ch = NULL;
    }

    int length = 0;
    for (length = 0; *(str + length); length++);

    if (0 < length)
    {
        if (NULL == (T->ch = (char *)malloc((length + 1) * sizeof(char))))
            return OVERFLOW;

        char *p = T->ch;
        while (*p++ = *str++);

        T->length = length;
    }

    return OK;
}

int StrLength(const HString *T)
{
    return T->length;
}

char *StrClone(const HString *T)
{
    if (NULL == T->ch)
        return NULL;

    char *new, *p_new, *p_old;
    if (NULL == (p_new = new = (char *)malloc((T->length + 1) * sizeof(char))))
        return NULL;

    p_old = T->ch;
    while (*p_new++ = *p_old++);

    return new;
}

Status Concat(HString *T, const char *str)
{
    if (NULL == str)
        return ERROR;

    int length = 0;
    for (length = 0; *(str + length); length++);

    if (0 < length)
    {
        char *new_str, *p_new;
        if (NULL == (p_new = new_str = (char *)malloc((T->length + length + 1) * sizeof(char))))
            return OVERFLOW;

        char *p_old = T->ch;
        while (*p_new++ = *p_old++);
        p_new--;
        while (*p_new++ = *str++);

        free(T->ch);
        T->ch = new_str;
        T->length = T->length + length;
    }

    return OK;
}