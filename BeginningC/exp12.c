#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TITLE_WIDTH (65)
#define TITLE_LINE '-'

void print_title(char* title);

int main(void)
{
    print_title("exp12");

    print_title("Write file");
    {
        FILE *pfile = NULL;
        if (NULL == (pfile = fopen("/tmp/myfile.txt", "a")))
            printf("open file failed.\n");

        if (EOF == fflush(pfile))
            printf("fflush failed.\n");

        if (EOF == fclose(pfile))
            printf("close failed.\n");

        remove("/tmp/myfile.txt");
    }

    print_title("Writing a file");
    if (0)
    {
        char mystr[80];
        printf("Enter string:\n");
        fgets(mystr, 80, stdin);

        FILE *pfile = NULL;
        if (NULL == (pfile = fopen("/tmp/myfile.txt", "w")))
        {
            printf("open file failed.\n");
            exit(1);
        }

        int lstr = strlen(mystr);
        for (int i = lstr - 1; i >= 0; i--)
            fputc(mystr[i], pfile);

        fclose(pfile);

        if (NULL == (pfile = fopen("/tmp/myfile.txt", "r")))
        {
            printf("open file failed.\n");
            exit(1);
        }

        int mychar = 0;
        while (EOF != (mychar = fgetc(pfile)))
            putchar(mychar);
        putchar('\n');

        fclose(pfile);
        remove("/tmp/myfile.txt");
    }

    print_title("Writing string to files");
    {
        fputs("Hello world\n", stdout);
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