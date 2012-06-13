#include "expxx.h"
#include <unistd.h>

int main(void)
{
    print_title("exp08");
#if 0
    {
        char buf[64];
        int n;

        while ((n = read(0, buf, 64)) > 0)
            write(0, buf, n);
    }
#endif

    print_title("*p++ *++p");
    {
        int number[10] = {0,1,2,3,4,5,6,7,8,9};
        int *p = number, *q = number;
        show_var("%d", *p++);
        show_var("%d", *p);
        show_var("%d", *++q);
        show_var("%d", *q);
    }

    return 0;
}