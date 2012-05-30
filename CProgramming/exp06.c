#include <stdio.h>
#include <string.h>
#define FBNCI 40

int main (void) {
    printf("---------- EXP06 ----------\n");

    printf("-------- Fibonacci --------\n");
    int fibonacci[FBNCI] = {1,1};
    for (int i = 2; i < FBNCI; i++)
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    for (int i = 0; i < FBNCI; i++)
    {
        printf("%9d ", fibonacci[i]);
        if ((i + 1) % 4 == 0) printf("\n");
    }
    printf("\n");

    printf("----------- Sort ----------\n");
    int numbers[10] = {34,67,90,43,124,87,65,99,132,26};
    for (int i = 0; i < 10; i++)
        printf("%3d ", numbers[i]);
    printf("\n");
    for (int i = 0; i < 10; i++)
    {
        int min = numbers[i];
        for (int j = i; j < 10; j++)
        {
            if(min > numbers[j])
            {
                numbers[i] = numbers[j];
                numbers[j] = min;
                min = numbers[i];
            }
        }
    }
    for (int i = 0; i < 10; i++)
        printf("%3d ", numbers[i]);
    printf("\n");

    printf("----- Matrix multiply -----\n");
    int muld[2][3] = {{4,2,8},{0,7,1}};
    int mulr[3][2] = {{3,3},{4,1},{2,5}};
    int result[2][2] = {0};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                result[i][j] += muld[i][k] * mulr[k][j];
            }
            printf("%3d ", result[i][j]);
        }
        printf("\n");
    }

    printf("-------- char array -------\n");
    char hello[100] = "Hello world!";
    printf("hello = %s\n", hello);

    printf("---------- String ---------\n");
    puts(hello);
    printf("hello = %s\n", strcat(hello, " I am gengs."));
    char foo[100];
    strcpy(foo, hello);
    printf("foo = %s\n", foo);

    printf("strlen = %3ld\n", strlen(foo));
    printf("sizeof = %3ld\n", sizeof(foo));
    memset(foo, 0, sizeof(foo));
    strncpy(foo, hello, 12);
    printf("foo = %s\n", foo);

    printf("---- Pascal's triangle ----\n");
    #define PASCAL 8
    int pascal[PASCAL][PASCAL] = {0};
    for (int i = 0; i < PASCAL; i++)
    {
        pascal[i][0] = 1;
        for (int j = 1; j < i; j++)
        {
            pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
        }
    }

    for (int i = 0; i < PASCAL; i++)
    {
        for (int j = 0; j < PASCAL; j++)
        {
            if (pascal[i][j] != 0)
                printf("%3d ", pascal[i][j]);
            else
                break;
        }
        printf("\n");
    }

    printf("------- String copy -------\n");
    char ori_str[13] = "1234567890123";
    char tar_str[50] = "XXXXXXXXXXXXXXXXXXXX";
    for (int i = 0; ori_str[i] != '\0'; i++)
    {
        tar_str[i] = ori_str[i];
    }

    printf("%s\n", tar_str);

    return 0;
}