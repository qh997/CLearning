#include "KMP.h"

int *get_kmp_next(char *S)
{
    printf("\n%s\n", S);
    int *next = (int *)malloc((strlen(S)) * sizeof(int));
    
    for (int i = 0; i < strlen(S); i++)
    {
        //printf("i = %d\n", i);
        if (i == 0)
        {
            next[i] = 0;
            continue;
        }

        int j = 1;
        for (; j <= i - 1; j++)
        {
            //printf("\tj = %d\n", j);
            int k = 0;
            for (; k <= i - 1 - j; k++)
            {
                //printf("\t\tk = %d\n", k);
                if (S[k] != S[k + j])
                {
                    //printf("\t\tS[%d] != S[%d] break\n", k, k + j);
                    break;
                }
            }
            //printf("\t%d <=> %d\n", k, i - 1 - j);
            if (k - 1 == i - 1 - j)
            {
                //printf("\t\tk == i - 1 - j break\n");
                break;
            }
        }

        //printf("next[%d] = %d - %d\n", i, i, j);
        next[i] = i - j;
    }

    return next;
}

int *get_kmp_next1(char *S)
{
    printf("\nget_kmp_next1\n%s\n", S);
    int *next = (int *)malloc((strlen(S)) * sizeof(int));
    next[0] = 0;

    for (int i = 1, j = 0; i < strlen(S); i++)
    {
        printf("i = %d; j = %d\n", i, j);
        printf("%c <=> %c\n", S[j], S[i]);
        while ((j > 0) && (S[j] != S[i]))
            j = next[j - 1];

        if (S[j] == S[i])
            j++;

        next[i] = j;
    }

    return next;
}

int kmp_matching(char *T, char *P)
{
    int *next = get_kmp_next(P);

    for (int i = 0, j = 0; '\0' != T[i]; i++)
    {
        printf("i = %d\n", i);
        while (j > 0 && P[j] != T[i])
        {
            printf("\tj = %d\n", j);
            j = next[j];
        }

        printf("j = %d\n", j);
        if (P[j] == T[i])
            j++;

        if (j == strlen(P))
        {
            return i - j + 1;
        }
    }

    return -1;
}