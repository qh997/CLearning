#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <stdbool.h>

#define TITLE_WIDTH (65)
#define TITLE_LINE '-'

#define show_var(fmt, var) printf("%s = "fmt"\n", #var, var)

void print_title(char *title);
void shellsort(int v[], int n);
char *expand(const char *s1);
char *itoa(int n);
char *itob(int n, int b);

int main(void)
{
    print_title("exp03");

    print_title("shellsort");
    {
        int a[10] = {11, 23, 7, 56, 88, 42, 41, 60, 71, 4};
        for (int i = 0; i < 10; i++)
            printf("%2d ", a[i]);
        printf("\n");
        shellsort(a, 10);
        for (int i = 0; i < 10; i++)
            printf("%2d ", a[i]);
        printf("\n");
    }

    print_title("expand");
    {
        show_var("%s", expand("helo-z,4-8,e-h-o"));
    }

    print_title("itoa");
    {
        show_var("%s", itoa(-2147483648));
    }

    print_title("itob");
    {
        show_var("%s", itob(997, 1));
    }

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

void shellsort(int v[], int n)
{
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        //printf("gap = %d\n", gap);
        for (int i = gap; i < n; i++)
        {
            //printf("i = %d\n", i);
            for (int j = i-gap; j >= 0 && v[j] > v[j+gap]; j -= gap)
            {
                //printf("gap = %d;i = %d; j = %d\n", gap, i, j);
                int temp = v[j];
                v[j] = v[j + gap];
                v[j + gap] = temp;

                /*for (int i = 0; i < 10; i++)
                    printf("%2d ", v[i]);
                printf("\n");*/
            }
        }
    }
}

char *expand(const char *s1)
{
    bool inexp = false;
    char start = '\0';
    while ('\0' != *(s1++))
    {
        show_var("%c", (*s1));
        if (isalnum(*s1))
        {
            if (!inexp)
                start = *s1;
            else
            {
                if (start <= *s1)
                {
                    printf("%c - %c: ", start, *s1);
                    for (int i = 0; start + i <= *s1; i++)
                        printf("%c ", start + i);
                    printf("\n");
                }
                inexp = false;
                start = *s1;
            }
        }
        else if ('-' == *s1)
        {
            if ('\0' != start)
                inexp = true;
        }
        else
        {
            inexp = false;
            start = '\0';
        }
    }
}

char *itoa(int n)
{
    long int nlen, plx, over = 1;
    bool sign = n < 0 ? true : false;
    n = sign ? -n : n;
    if (n != 0 && -n == n)
        over = -1;

    for (nlen = 1, plx = 1; n/(10*plx); ++nlen, plx*=10);

    char *numbers = malloc((nlen + 2) * sizeof(char));
    char *pn = numbers;
    if (sign)
    {
        *pn = '-';
        pn++;
    }
    while (0 < plx)
    {
        *pn++ = (over) * (int)(n / plx) + '0';
        n = n - (int)(n / plx) * plx;
        plx /= 10;
    }
    *pn = '\0';


    return numbers;
}

char *itob(int n, int b)
{
    if (b < 2)
        return NULL;

    long int nlen, plx, over = 1;
    bool sign = n < 0 ? true : false;

    if (n != 0 && -n == n)
        over = -1;
    else
        n = sign ? -n : n;

    for (nlen = 1, plx = 1; n/(b*plx); ++nlen, plx*=b);

    char *numbers = malloc((nlen + 2) * sizeof(char));
    char *pn = numbers;
    if (sign)
    {
        *pn = '-';
        pn++;
    }
    while (0 < plx)
    {
        *pn++ = (int)(n / plx) > 9 ? (int)(n / plx) - 10 + 'A'
                                   : (int)(n / plx) + '0';
        n = n - (int)(n / plx) * plx;
        plx /= b;
    }
    *pn = '\0';

    return numbers;
}