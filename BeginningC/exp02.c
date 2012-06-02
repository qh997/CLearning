#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <complex.h>
#include <string.h>
#include <limits.h> 
#include <locale.h>
#include <math.h>

#define TITLE_WIDTH (65)
#define TITLE_LINE '-'

void print_title (char *title);

int main ()
{
    print_title("exp02");

    print_title("limits.h");
    printf("%+19s: %21d to %d\n", "char", CHAR_MIN, CHAR_MAX);
    printf("%+19s: %21u to %u\n", "unsigned char", 0, UCHAR_MAX);
    printf("%+19s: %21d to %d\n", "short", SHRT_MIN, SHRT_MAX);
    printf("%+19s: %21u to %u\n", "unsigned short", 0, USHRT_MAX);
    printf("%+19s: %21d to %d\n", "int", INT_MIN, INT_MAX);
    printf("%+19s: %21u to %u\n", "unsigned int", 0, UINT_MAX);
    printf("%+19s: %21ld to %ld\n", "long", LONG_MIN, LONG_MAX);
    printf("%+19s: %21lu to %lu\n", "unsigned long", 0, ULONG_MAX);
    printf("%+19s: %21lld to %lld\n", "long long", LLONG_MIN, LLONG_MAX);
    printf("%+19s: %21lu to %llu\n", "unsigned long long", 0, ULLONG_MAX);

    print_title("sizeof");
    printf("%+13s: %3d bytes\n", "char", sizeof(char));
    printf("%+13s: %3d bytes\n", "short", sizeof(short));
    printf("%+13s: %3d bytes\n", "int", sizeof(int));
    printf("%+13s: %3d bytes\n", "long", sizeof(long));
    printf("%+13s: %3d bytes\n", "long long", sizeof(long long));
    printf("%+13s: %3d bytes\n", "float", sizeof(float));
    printf("%+13s: %3d bytes\n", "double", sizeof(double));
    printf("%+13s: %3d bytes\n", "long double", sizeof(long double));

    print_title("type problem");
    printf("9 / 2 * 2 = %.3f\n", (float)(9 / 2 * 2));
    printf("9 * 2 / 2 = %.3f\n", (float)(9 * 2 / 2));

    print_title("Wide character");
    setlocale(LC_ALL, "");
    wchar_t w_ch = 32831;
    printf("w_ch: %lc = %ld\n", w_ch, w_ch);

    print_title("Bool");
    _Bool valid_t = true;
    printf("valid_t = %d\n", valid_t);
    bool valid_f = false;
    printf("valid_f = %d\n", valid_f);

    print_title("Complex");
    double complex z1 = 2.5F + 3.8F * I;
    double complex z2 = 1.9F + 4.7F * I;
    printf("z1 + z2 = %6.2lf + %5.2lfi\n", creal(z1 + z2), cimag(z1 + z2));
    printf("z1 - z2 = %6.2lf + %5.2lfi\n", creal(z1 - z2), cimag(z1 - z2));
    printf("z1 * z2 = %6.2lf + %5.2lfi\n", creal(z1 * z2), cimag(z1 * z2));
    printf("z1 / z2 = %6.2lf + %5.2lfi\n", creal(z1 / z2), cimag(z1 / z2));

    print_title("math.h");
    printf("sin(3.14 / 3) = %lf\n", sin(3.14 / 3));
    printf("sqrt(13) = %lf\n", sqrt(13));
}

void print_title (char *title)
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
