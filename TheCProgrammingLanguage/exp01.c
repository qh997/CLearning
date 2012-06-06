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
#define QUIT_CHAR 'Q'

#define show_var(fmt, var) printf("%s = "fmt"\n", #var, var)

void print_title(char *title);
double power(double base, int n);
char *string_copy(char *strDest, const char *strSrc);
char *string_reverse(char *const strDest);

int main(void)
{
    print_title("exp01");

    print_title("Fahrenheit to Celsius");
    {
        for (int ft = F_LOWER; ft <= F_UPPER; ft += F_STEP)
            printf("%3dF => %6.2fC\n", ft, (ft - 32) * 5 / 9.0F);
    }

    print_title("getchar putchar");
    if (false)
    {
        int c = 0, nc = 0, nl = 0, nw = 0;
        bool state = WORD_OUT;
        fflush(stdout);
        while (QUIT_CHAR != (c = getchar()))
        {
            if ('\n' == c)
            {
                nl++;
                state = WORD_OUT;
            }
            else
            {
                nc++;
                if (' ' == c || '\t' == c)
                {
                    state = WORD_OUT;
                }
                else if (WORD_OUT == state)
                {
                    state = WORD_IN;
                    nw++;
                }
            }
        }
        show_var("%d", nc);
        show_var("%d", nl);
        show_var("%d", nw);
    }

    print_title("Character statistics");
    if (false)
    {
        int ndigit[10] = {0}, nwhite = 0, nother = 0;
        char c;
        fflush(stdout);
        while (QUIT_CHAR != (c = getchar()))
        {
            if ('0' <= c && c <= '9')
                ++ndigit[c - '0'];
            else if (' ' == c || '\t' == c || '\n' == c)
                ++nwhite;
            else
                ++nother;
        }

        printf("digits = ");
        for (int i = 0; i < 10; i++)
            printf("%d ", ndigit[i]);
        printf(", nwhite = %d", nwhite);
        printf(", nother = %d\n", nother);
    }

    print_title("power");
    {
        show_var("%.3lf", power(2.0, 4));
        show_var("%.3lf", power(-3.0, 4));
        show_var("%.3lf", power(128, 0));
    }

    print_title("string_copy");
    {
        char *str_src = "Hello world!";
        char *str1 = string_copy(NULL, str_src);
        show_var("%s", str1);
        free(str1);

        char *str2 = malloc(100);
        string_copy(str2, "chang jiang ba hao!");
        show_var("%s", str2);
        string_reverse(str2);
        show_var("%s", str2);
        free(str2);
    }

    show_var("%X", EOF);

    return 0;
}

void print_title(char *title)
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

double power(double base, int n)
{
    if (0 == n)
        return 1;
    else
        return(base * power(base, n - 1));
}

char *string_copy(char *strDest, const char *strSrc)
{
    if (NULL == strSrc)
        return strDest;
    else if (NULL == strDest)
    {
        int string_length = 0;
        while ('\0' != *(strSrc + string_length++));
        strDest = malloc(string_length * sizeof(char));
    }

    char *pchar = strDest;
    while ('\0' != (*pchar++ = *strSrc++));

    return strDest;
}

char *string_reverse(char *const strDest)
{
    if (NULL != strDest)
    {
        int str_len = strlen(strDest);
        for (int i = 0; i < str_len / 2; i++)
        {
            char c = *(strDest + i);
            *(strDest + i) = *(strDest + str_len - 1 - i);
            *(strDest + str_len - 1 - i) = c;
        }
    }

    return strDest;
}