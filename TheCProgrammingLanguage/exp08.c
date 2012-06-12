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

    return 0;
}