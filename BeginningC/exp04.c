#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <complex.h>
#include <string.h>
#include <limits.h> 
#include <locale.h>
#include <math.h>
#include <time.h>

#define TITLE_WIDTH (65)
#define TITLE_LINE '-'

void print_title (char *title);

int main ()
{
    print_title("exp04");

    print_title("Decimal reversal");
    int number = 25631;
    int result = 0;
    printf("%d", number);
    while (number)
    {
        result = result * 10 + number % 10;
        number /= 10;
    }
    printf(" => %d\n", result);

    for (int i = 0; i < 10; i++)
    {
        printf("\r[");
        for (int j = 0; j <= i; j++)
            printf("%c", '.');
        for (int j = 0; j < 9 - i; j++)
            printf(" ");
        printf("] %3d%%", (i + 1) * 10);

        time_t now = clock();
        for (; clock() - now < CLOCKS_PER_SEC;);
    }
    printf("\n");

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
