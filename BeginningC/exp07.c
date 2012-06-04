#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TITLE_WIDTH (65)
#define TITLE_LINE '-'

void print_title (char *title);

int main (void)
{
    print_title("exp07");
    {
        int number = 10, *pointer = &number;
        printf("number's   address : %p\n", &number);
        printf("number's   value   : %d\n", number);
        printf("pointer's  address : %p\n", &pointer);
        printf("pointer's  size    : %ld\n", sizeof(pointer));
        printf("pointer's  value   : %p\n", pointer);
        printf("pointer to value   : %d\n", *pointer);
        printf("pointer to size    : %d\n", (int)sizeof(*pointer));
    }

    print_title("const pointer");
    {
        int value = 4;
        const int *pvalue = NULL;
        pvalue = &value;
        printf("%d\n", *pvalue);
        value = 23;
        int *const pcount = &value;
        printf("%d\n", *pcount);

        const int hero = 81192;
        printf("const hero = %d\n", hero);
        int *phero = &hero;
        *phero = 1999;
        printf("const hero = %d\n", hero);
    }

    print_title("array & pointer");
    {
        char board[3][3] = {
            {'1','2','3'},
            {'4','5','6'},
            {'7','8','9'},
        };

        printf("address of board       : %p\n", board);
        printf("address of board[0]    : %p\n", board[0]);
        printf("address of board[0][0] : %p\n", &board[0][0]);

        printf("value of board[0][0] : %c\n", board[0][0]);
        printf("value of *board[0]   : %c\n", *board[0]);
        printf("value of **board     : %c\n", **board);

        char *pboard = board;
        printf("%c\n", *(pboard + 6));
        printf("%c\n", *(*(board + 1) + 1));
    }

    print_title("malloc calloc free");
    {
        char *pchar = malloc(10 * sizeof(char));
        for (int i = 0; i < 9; *(pchar + i) = (char)('a' + i), i++);
        *(pchar + 9) = '\0';
        printf("pchar = %s\n", pchar);
        char *pchar1 = pchar + 3;
        printf("%p\n", pchar);
        printf("%p\n", pchar1);
        free(pchar);
        printf("%p\n", pchar);
    }

    print_title("realloc");
    {
        char *pchar = malloc(10 * sizeof(char));
        for (int i = 0; i < 9; *(pchar + i) = (char)('a' + i), i++);
        *(pchar + 9) = '\0';
        printf("%p\n", pchar);
        printf("pchar = %s\n", pchar);

        pchar = realloc(pchar, 15 * sizeof(char));
        for (int i = 0; i < 14; *(pchar + i) = (char)('a' + i), i++);
        *(pchar + 14) = '\0';
        printf("%p\n", pchar);
        printf("pchar = %s\n", pchar);

        pchar = realloc(pchar, 25 * sizeof(char));
        for (int i = 0; i < 24; *(pchar + i) = (char)('a' + i), i++);
        *(pchar + 24) = '\0';
        printf("%p\n", pchar);
        printf("pchar = %s\n", pchar);

        free(pchar);
    }
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
