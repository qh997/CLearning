#include <stdio.h>

#define NAME "gengs"

int main ()
{
    printf("----------3.1----------\n");
    float f, c;
    f = 64.0;
    c = (5.0 / 9) * (f - 32);
    printf("f = %f\nc = %f\n", f, c);

    printf("----------3.2----------\n");
    float p0 = 1000, r1 = 0.0036, r2 = 0.0225, r3 = 0.0198, p1, p2, p3;
    p1 = p0 * (1 + r1);
    p2 = p0 * (1 + r2);
    p3 = p0 * (1 + r3 / 2) * (1 + 3 / 2);
    printf("p1 = %f\np2 = %f\np3 = %f\n", p1, p2, p3);
    printf("Hello my name is %s\n", NAME);

    printf("---------const---------\n");
    const int a = 65535;
    printf("Const int a = %d\n", a);
    printf("1/3 = %f\n", 1.0 / 3.0);

    printf("--------sizeof---------\n");
    printf("Sizeof short  = %zu\n", sizeof(short));
    printf("Sizeof int    = %zu\n", sizeof(int));
    printf("Sizeof long   = %zu\n", sizeof(long));
    printf("Sizeof float  = %zu\n", sizeof(float));
    printf("Sizeof double = %zu\n", sizeof(double));
    printf("Sizeof char   = %zu\n", sizeof(char));

    printf("---------char----------\n");
    char d = '?';
    printf("%d %c\n", d, d);
    unsigned char e = 159;
    printf("%d %c\n", e, e);

    printf("----Type conversion----\n");
    float fg = 3.1415926535897932384626;
    printf("fg = %f\n", fg);
    printf("(int)c = %d\n", (int)c);
    int i = 289;
    d = i;
    printf("d = %d -> %c\n", d, d);

    printf("--------printf---------\n");
    printf("fg = %.6f\n", fg);
    double dg = 3.1415926535897932384626;
    printf("dg = %.15f\n", dg);
    printf("%13.2e\n", 123.456);
    printf("%13.2E\n", 123.456);
    printf("-1 = %x\n", -1);
    printf("%g\n", (double)12345678954321);
    printf("%f%%\n", 1.0 / 3);

    printf("--------putchar--------\n");
    char char1 = 'B', char2 = 'O', char3 = 'Y';
    putchar(char1);
    putchar(char2);
    putchar(char3);
    putchar('\015');
    putchar('X');
    putchar('\n');

    printf("--------getchar--------\n");
    char c1, c2;
    c1 = getchar();
    c2 = c1 + 32;
    putchar(c2);
    putchar('\n');

    return 0;
}