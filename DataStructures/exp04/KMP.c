#include "KMP.h"

int *get_kmp_next(char *S)
{
    int S_len = strlen(S);
    int *next;
    if (NULL == (next = (int *)malloc(S_len * sizeof(int))))
        return NULL;

    int i = 0, j = -1;
    next[i] = j;
    while (i < S_len)
    {
        if (j == -1 || S[j] == S[i])
        {
            i++; j++;
            if(S[i] != S[j])
                next[i] = j;
            else
                next[i] = next[j];
        }
        else
            j = next[j];
    }   
    

    return next;
}

int kmp_matching(char *T, char *P)
{
    int *next = get_kmp_next(P);
    if (NULL == next)
        return -1;

    int T_len = strlen(T);
    int P_len = strlen(P);

    int i = 0, j = -1;
    while (i < T_len)
    {
        if (j == -1 || P[j] == T[i])
            i++-++j;
        else
            j = next[j];

        if (j == P_len)
            return i - j;
    }

    return -1;
}

int *get_kmp_next1(char *S)
{
    int S_len = strlen(S);
    int *next;
    if (NULL == (next = (int *)malloc(S_len * sizeof(int))))
        return NULL;

    next[0] = -1;
    for (int i = 0, j = -1; i < S_len;)
    {
        while ((j > -1) && (S[j] != S[i]))
            j = next[j];
        
        if (j == -1 || S[j] == S[i])
            ++j;

        if (S[++i] != S [j])
            next[i] = j;
        else
            next[i] = next[j];
    }

    return next;
}

int kmp_matching1(char *T, char *P)
{
    int *next = get_kmp_next(P);
    if (NULL == next)
        return -1;

    int P_len = strlen(P);

    for (int i = 0, j = -1; '\0' != T[i];)
    {
        while (j > -1 && P[j] != T[i])
            j = next[j];

        if (j == -1 || P[j] == T[i])
            ++j, ++i;

        if (j == P_len)
            return i - j;
    }

    return -1;
}