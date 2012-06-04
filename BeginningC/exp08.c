#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define TITLE_WIDTH (65)
#define TITLE_LINE '-'

void print_title (char* title);
void change_number (const int* pnum);

int main ()
{
    print_title("exp08");

    print_title("Variable scope");
    {
        int count = 0;
        do
        {
            int count = 0;
            ++count;
            printf("in count = %d\n", count);
        } while (++count <= 3);

        printf("\nout count = %d\n", count);
    }

    print_title("const in function");
    {
        int i = 20, *p = &i;
        change_number(p);
        printf("%d\n", *p);

        const int* pvalue = &i;
        int* const cpvalue = &i;

        pvalue = NULL;
        *cpvalue = 22;
    }

    print_title("pointer to pointer");
    {
        char *strings[5] = {NULL};
        printf("%p\n", strings[3]);
        strings[3] = malloc(5 * sizeof(char));
        printf("%p\n", strings[3]);
        *(*(strings + 3) + 2) = 'c';
        printf("*(*(strings + 3) + 2) = %c\n", *(*(strings + 3) + 2));
        char *pstr = strings[3];
        printf("*(pstr + 2) = %c\n", *(pstr + 2));
        char **ppstr = &strings[3];
        printf("*(*ppstr + 2) = %c\n", *(*ppstr + 2));
        long long *ppstr2 = &strings[3];
        printf("%p\n", (char *)*ppstr2);
        printf("%c\n", *((char *)*ppstr2 + 2));
        *strings = malloc(5 * sizeof(char));
        **strings = 'x';
        ppstr2 = &strings[0];
        printf("%c\n", *((char *)*ppstr2));
    }
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

void change_number (const int* pnum)
{
//    *pnum *= 2; //error: assignment of read-only location ‘*pnum’
}