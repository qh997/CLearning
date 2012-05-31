#include <stdio.h>
#include <string.h>

extern int ExA;

void get_extern ()
{
    printf("ExternA = %d\n", ExA);
}

float legendre (int rank, float x)
{
    if (rank == 0)
        return 1;
    else if (rank == 1)
        return x;
    else
        return
            ((
                (2 * rank - 1) * x
                - legendre(rank - 1, x)
                - (rank - 1) * legendre(rank - 2, x) 
            ) / rank);

}

int hex_to_dec (char hex[])
{
    int dec = 0;
    for (int i = 0; hex[i] != '\0'; i++)
    {
        if ('0' <= hex[i] && hex[i] <= '9')
            dec = 16 * dec + (hex[i] - '0');
        if ('A' <= hex[i] && hex[i] <= 'F')
            dec = 16 * dec + (hex[i] - 'A' + 10);
    }

    return dec;
}