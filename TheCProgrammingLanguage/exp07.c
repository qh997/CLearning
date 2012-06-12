#include "expxx.h"

void minprintf(char *fmt, ...);

int main(int argc, char *argv[])
{
    print_title("exp07");
    {
        char *p = argv[0];
        while ('\0' != *p)
        {
            if (islower(*p))
                putchar(toupper(*p));
            else if (isupper(*p))
                putchar(tolower(*p));
            else
                putchar(*p);

            p++;
        }

        printf("\n");
    }

    print_title("printf");
    {
        printf(":%s:\n", "hello, world");
        printf(":%10s:\n", "hello, world");
        printf(":%.10s:\n", "hello, world");
        printf(":%-10s:\n", "hello, world");
        printf(":%.15s:\n", "hello, world");
        printf(":%-15s:\n", "hello, world");
        printf(":%15.10s:\n", "hello, world");
        printf(":%-15.10s:\n", "hello, world");
    }

    print_title("minprintf");
    {
        minprintf("string : [%s]\n", "gengs");
        minprintf("int : [%d]\n", 997);
    }

    print_title("system");
    {
        system("date");
    }

    return 0;
}

void minprintf(char *fmt, ...)
{
    va_list ap;
    char *p, *sval;
    int ival;
    double dval;

    va_start(ap, fmt);
    for (p = fmt; *p; p++)
    {
        if (*p != '%')
        {
            putchar(*p);
            continue;
        }

        switch (*++p)
        {
            case 'd':
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 's':
                for (sval = va_arg(ap, char *); *sval; sval++)
                    putchar(*sval);
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap);
}