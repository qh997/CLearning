#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

#define TITLE_WIDTH (65)
#define TITLE_LINE '-'
#define STR_LENGTH (40)

void print_title (char *title);

int main (void)
{
    print_title("exp06");

    print_title("Joining string");
    {
        char str1[STR_LENGTH] = "To be or not to be";
        char str2[STR_LENGTH] = ",that is the question";
        size_t count1 = strlen(str1), count2 = strlen(str2);

        if (sizeof(str1) < count1 + count2 + 1)
            printf("You can't put a quart into a pint pot.\n");
        else
            printf("%s\n", strcat(str1, str2));

        size_t str1_len = strlen(str1);
        printf("strlen(str1) = %d\n", str1_len);
        printf("sizeof(str1) = %d\n", sizeof(str1));
    }

    print_title("strcmp");
    {
        char str1[] = "The quick black fox";
        char str2[] = "The quick brown fox";
        if (strcmp(str1, str2) < 0)
            printf("str1 is less than str2\n");
    }

    print_title("strchr");
    {
        char str[] = "The quick brown fox";
        char c = 'q';
        char *pGot_char = NULL;
        pGot_char = strchr(str, c);
        printf("%s\n", pGot_char);
        if (pGot_char != NULL)
            printf("%C\n", *pGot_char);
    }

    print_title("string to number");
    {
        char value_str[] = "98.4";
        double value = 0;
        value = atof(value_str);
        printf("value = %.3f\n", value);
    }

    print_title("wide string");
    {
        wchar_t name[] = L"耿爽";
        printf("%ls\n", name);
    }

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
