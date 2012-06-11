#include "expxx.h"
#include <float.h>

int day_of_year(int year, int month, int day);

int main(void)
{
    print_title("exp05");

    print_title("Multidimensional array");
    {
        show_var("%d", day_of_year(2012, 3, 31));
        show_var("%d", day_of_year(2012, 6, 11));
    }

    return 0;
}

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp= allocbuf;

char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n)
    {
        allocp += n;
        return allocp - n;
    }
    else
    {
        return NULL;
    }
}

void afree(char *p)
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
    {
        allocp = p;
    }
}

static char daytab[2][13] = 
{
    {0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31}
};

int day_of_year(int year, int month, int day)
{
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (i = 1; i < month; i++)
        day += *(*(daytab + leap) + i);
    return day;
}
