#include "expxx.h"
#include "exp05/array.h"

int main(void)
{
    print_title("exp05");

    print_title("Array");
    {
        Array Ary;
        InitArray(&Ary, 3, 2, 3, 4);
        Assign(&Ary, 558, 1, 1, 2);
        int e;
        Value(&Ary, &e, 1, 1, 2);
        show_var("%d", e);
    }

    return 0;
}