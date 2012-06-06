#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TITLE_WIDTH (65)
#define TITLE_LINE '-'
#define F_LOWER (0)
#define F_UPPER (300)
#define F_STEP (20)
#define WORD_IN true
#define WORD_OUT false

#define show_var(fmt, var) printf("%s = "fmt"\n", #var, var)

void print_title(char* title);

int main(void)
{
    print_title("exp01");

    print_title("Fahrenheit to Celsius");
    {
        for (int ft = F_LOWER; ft <= F_UPPER; ft += F_STEP)
            printf("%3dF => %6.2fC\n", ft, (ft - 32) * 5 / 9.0F);
    }

    print_title("getchar putchar");
    {
        int c = 0, nc = 0, nl = 0, nw = 0;
        bool state = WORD_OUT;
        while (EOF != (c = getchar()))
        {
            if ('\n' == c)
            {
                nl++;
            }
            else
            {

            }
            putchar(c);
        }
        show_var("%d", nc);
    }

    return 0;
}

void print_title(char* title)
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