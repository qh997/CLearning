#include <stdio.h>
#include <math.h>

int main ()
{
    printf("---------- EXP05 ----------\n");

    printf("-------- Fibonacci --------\n");
    int fibonacci1 = 1, fibonacci2 = 1;

    for (int i = 1; i <= 20; i++)
    {
        printf("%9d %9d", fibonacci1, fibonacci2);
        if (i % 2 == 0) printf("\n");
        fibonacci1 = fibonacci1 + fibonacci2;
        fibonacci2 = fibonacci1 + fibonacci2;

    }

    printf("------- Prime number ------\n");
    int column_width = 0;
    for (int number = 1; number <= 1000; number += 2)
    {
        int k = sqrt(number);
        int i;
        for (i = 2; i <= k; i++)
            if (number % i == 0) break;

        if (!(i <= k))
        {
            printf("%3d ", number);
            if (++column_width % 10 == 0) printf("\n");
        }
    }
    printf("\n");

    printf("------- a + aa + aaa ------\n");
    int amount = 2, median = 5;
    int plus = 0, sum = 0;
    for (int i = 1; i <= median; i++)
    {
        plus *= 10;
        plus += amount;
        sum += plus;
        printf("%d", plus);
        if (i < median)
            printf(" + ");
        else
            printf(" = ");
    }
    printf ("%d\n", sum);

    printf("-------- Fall down --------\n");
    float high = 100;
    int times = 5;
    while (times--)
        high /= 2;
    printf("High : %.3f\n", high);

    printf("------ Perfect number -----\n");
    for (int i = 1; i <= 1000; i++)
    {
        int divisor_sum = 0;
        for (int divisor = 1; divisor < i; divisor++)
        {
            if (i % divisor == 0)
                divisor_sum += divisor;
        }

        if (divisor_sum == i) {
            printf("%5d its factors are ", divisor_sum);
            int dot = 0;
            for (int divisor = 1; divisor < i; divisor++)
            {
                if (divisor_sum % divisor == 0)
                {
                    if (dot)
                        printf(",");
                    else
                        dot = 1;
                    printf("%d", divisor);
                }
            }
            printf("\n");
        }
    }

    return 0;
}