#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

#define TITLE_WIDTH (65)
#define TITLE_LINE '-'

void print_title (char* title);
int any_function (int (*pfun) (int, int), int x, int y);
int sum (int a, int b);
int mul (int a, int b);
int miu (int a, int b);
double average (double v1, double v2, ...);

int main (int argc, char* argv[])
{
    print_title("exp09");

    print_title("Pointer to functions");
    {
        int (*pfunc) (int, int);
        pfunc = sum;
        printf("qh%d\n", pfunc(476, 521));
        printf("%p\n", pfunc);
    }

    print_title("Array of pointer to functions");
    {
        int (*pfuncs[3]) (int, int);
        pfuncs[0] = sum;
        pfuncs[1] = mul;
        pfuncs[2] = miu;

        for (int i = 0; i < 3; i++)
            printf("Result = %6d\n", pfuncs[i](476, 521));
    }

    print_title("Pointer in functions");
    {
        int (*pfunc) (int, int);
        pfunc = sum;
        printf("any_function(pfunc, 476, 521) = %d\n", any_function(pfunc, 476, 521));
        printf("any_function(miu, 476, 521) = %d\n", any_function(miu, 476, 521));
    }

    print_title("variable argument");
    {
        printf("average = %6.2f\n", average(3.0, 4.0, 5.0, 6.0, 0.0));
        printf("average = %6.2f\n", average(32.5, 4.8, 55.4, 11.9, 2.0, 0.0));
        printf("average = %6.2f\n", average(78.2, 88.3, 0.0));
    }

    print_title("main arguments");
    {
        printf("Program name : %s\n", argv[1]);
        for (int i = 1; i < argc; i++)
            printf("Argument %d : %s\n", i, argv[i]);
    }

    return 0;
}

void print_title (char* title)
{
    if (strlen(title) >= TITLE_WIDTH)
    {
        printf("%s\n", title);
        return;
    }

    int side = (TITLE_WIDTH - strlen(title)), fill = 0;
    fill = side % 2 == 0 ? 0 : 1;
    side /= 2; side -= 1;

    char *title_string = malloc((TITLE_WIDTH + 1) * sizeof(char));
    char *p = title_string;

    for (int i = 0; i < side; i++)
        *(p++) = TITLE_LINE;
    *(p++) = ' ';
    for (int i = 0; i < strlen(title); i++)
        *(p++) = *(title + i);
    *(p++) = ' ';
    for (int i = 0; i < side + fill; i++)
        *(p++) = TITLE_LINE;
    *p = '\0';

    printf("%s\n", title_string);

    free(title_string);
}

int any_function (int (*pfun) (int, int), int x, int y)
{
    return pfun(x, y);
}

int sum (int a, int b)
{
    return a + b;
}

int mul (int a, int b)
{
    return a * b;
}

inline int miu (int a, int b)
{
    return a - b;
}

double average (double v1, double v2, ...)
{
    va_list parg;
    double sum = v1 + v2;
    double value = 0;
    int count = 2;

    va_start(parg, v2);
    while ((value = va_arg(parg, double)) != 0.0)
    {
        sum += value;
        count++;
    }
    va_end(parg);
    return sum / count;
}
