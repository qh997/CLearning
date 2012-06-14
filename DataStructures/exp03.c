#include "expxx.h"
#include "exp03/seqstack.h"

int main(void)
{
    print_title("exp03");

    print_title("Seq Stack");
    {
        SqStack sq_stack;
        InitStack(&sq_stack);
        show_var("%d", sq_stack.stacksize);
        Push(&sq_stack, 25);
        Push(&sq_stack, 997);
        show_var("%d", *(sq_stack.top - 1));

        int e;
        Pop(&sq_stack, &e);
        show_var("%d", e);
        Pop(&sq_stack, &e);
        show_var("%d", e);
        show_var("%d", Pop(&sq_stack, &e));

        int decn = 997;
        while (decn)
        {
            Push(&sq_stack, decn % 2);
            decn /= 2;
        }

        while (OK == Pop(&sq_stack, &e))
        {
            printf("%d ", e);
        }
        printf("\n");
    }

    return 0;
}