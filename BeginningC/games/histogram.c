#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define PAGE_HEIGHT (20)
#define PAGE_WIDTH (40)

typedef struct barTAG
{
    double value;
    struct barTAG *pnextbar;
} bar;

typedef unsigned int uint;

bar *add_bar(bar *const pfristbar, double value);
int bar_chart(bar *const pfristbar, uint page_width, uint page_height, char const *title);

int main(void)
{
    bar *pfristrbar = malloc(sizeof(bar));
    pfristrbar->value = 22;
    add_bar(pfristrbar, -9);
    add_bar(pfristrbar, 12);
    add_bar(pfristrbar, 23);
    add_bar(pfristrbar, 17);
    add_bar(pfristrbar, -3);
    add_bar(pfristrbar, 25);
    add_bar(pfristrbar, 7);

    bar_chart(pfristrbar, PAGE_WIDTH, PAGE_HEIGHT, "Test Bar Drawing");

    return 0;
}

bar *add_bar(bar *const pfristbar, double value)
{
    bar *plastbar = pfristbar;

    while (NULL != plastbar->pnextbar)
        plastbar = plastbar->pnextbar;

    if (NULL == (plastbar->pnextbar = malloc(sizeof(bar))))
    {
        printf("\nFailed to allocate memory in add_bar()"
            " - terminating program.\n");
        exit(1);
    }

    plastbar = plastbar->pnextbar;
    plastbar->value = value;
    plastbar->pnextbar = NULL;

    return plastbar;
}

int bar_chart(bar *const pfristbar, uint page_width, uint page_height, char const *title)
{
    bar *plastbar = pfristbar;
    double max = 0.0, min = 0.0, vert_scale = 0.0;
    uint bar_count = 1, barwidth = 0, space = 2, i = 0;
    char *column = NULL, *blank = NULL;

    max = min = plastbar->value;

    while (NULL != (plastbar = plastbar->pnextbar))
    {
        bar_count++;
        max = (max < plastbar->value) ? plastbar->value : max;
        min = (min > plastbar->value) ? plastbar->value : min;
    }
    vert_scale = (max - min) / page_height;

    if ((barwidth = page_width / bar_count - space) < 1)
    {
        printf("\nPage width too narrow.\n");
        return -1;
    }

    if (NULL == (column = malloc(barwidth + space + 1)))
    {
        printf("\nFailed to allocate memory in bar_chart()"
            " - terminating program.\n");
        exit(1);
    }

    for (i = 0; i < space; i++)
        *(column + i) = ' ';
    for (; i < space + barwidth; i++)
        *(column + i) = '#';
    *(column + i) = '\0';

    if (NULL == (blank = malloc(barwidth + space + 1)))
    {
        printf("\nFailed to allocate memory in bar_chart()"
            " - terminating program.\n");
        exit(1);
    }

    for (i = 0; i < space + barwidth; i++)
        *(blank + i) = ' ';
    *(blank + i) = '\0';

    double position = max;
    bool axis = false;

    printf("^ %s\n", title);
    for (i = 0; i <= page_height; i++)
    {
        if (position <= 0.0 && !axis)
        {
            printf("+");
            for (uint bars = 0; bars < bar_count * (barwidth + space); bars++)
                printf("-");
            printf(">\n");
            axis = true;
            position -= vert_scale;
            continue;
        }
        printf("|");

        plastbar = pfristbar;

        for (uint bars = 0; bars < bar_count; bars++)
        {
            printf(
                "%s", position <= plastbar->value &&
                      plastbar->value >= 0.0 && position > 0.0
                      ||
                      position >= plastbar->value &&
                      plastbar->value <= 0.0 && position <=0.0
                      ? column : blank
            );
            plastbar = plastbar->pnextbar;
        }
        printf("\n");
        position -= vert_scale;
    }

    if (!axis)
    {
        printf("+");
        for (uint bars = 0; bars < bar_count * (barwidth + space); bars++)
            printf("-");
        printf(">\n");
    }

    free(column);
    free(blank);

    return 0;
}