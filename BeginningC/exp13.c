#define NDEBUG
#define TITLE_WIDTH (65)
#define TITLE_LINE '-'

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

#define say_int(var) printf("%s = %d\n", #var, var)
#define show_var(fmt, var) printf("%s = "fmt"\n", #var, var)

void print_title(char* title);

int main(void)
{
    clock_t start, end;
    double cpu_time;
    start = clock();
    show_var("%ld", start);

    print_title("exp13");
    {
        int data = 226;
        say_int(data);
        show_var("%d", data);
        char c = 'a';
        show_var("%c", c);
        char str[20] = "hello world";
        show_var("%s", str);
        printf("Program last compile at %s on %s\n", __TIME__, __DATE__);
    }

    print_title("assert()");
    {
        assert(0);
        int long_time = 99999999;
        while (long_time--);
    }

    print_title("time.h");
    {
        end = clock();
        cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
        show_var("%ld", end - start);
        show_var("%.3f", cpu_time);
        time_t cal = time(NULL);
        show_var("%s", ctime(&cal));
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