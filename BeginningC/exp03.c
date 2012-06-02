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
    print_title("exp03");
    printf("5 == 4 = %d\n", 5 == 4);
    printf("5 > 4  = %d\n", 5 > 4);

    print_title("Bitwise operators");
    unsigned char x = 13;
    unsigned char y = 6;
    printf("0xD & 0x6 = %X\n", x & y);
    printf("0xD | 0x6 = %X\n", x | y);
    printf("0xD ^ 0x6 = %X\n", x ^ y);
    printf("    ~ 0xD = %X\n", ~x);

    print_title("Hexadecimal reversal");
    unsigned int original = 0x19ABCDEF;
    unsigned int result = 0;
    for (int i = 0; i < sizeof(int) * 2; i++)
    {
        result <<= 4;
        unsigned int mask = 0xF;
        result |= original & mask;
        original >>= 4;
    }
    printf("%X => %X\n", original, result);

    return 0;
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
