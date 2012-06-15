#include "expxx.h"
#include "exp03/seqstack.h"
#include "exp03/linkedqueue.h"
#include "exp03/seqqueue.h"

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

    print_title("Linked Queue");
    {
        LinkQueue lk_q;
        InitQueue(&lk_q);
        EnQueue(&lk_q, 523);
        EnQueue(&lk_q, 119);
        show_var("%p", lk_q.front);
        show_var("%p", lk_q.rear);
        show_var("%d", QueueLength(&lk_q));

        int e = 0;
        DeQueue(&lk_q, &e);
        show_var("%d", e);
        show_var("%p", lk_q.front);
        show_var("%p", lk_q.rear);
        show_var("%d", QueueEmpty(&lk_q));
        show_var("%d", QueueLength(&lk_q));

        DeQueue(&lk_q, &e);
        show_var("%d", e);
        show_var("%p", lk_q.front);
        show_var("%p", lk_q.rear);

        DestroyQueue(&lk_q);
        show_var("%p", lk_q.front);
        show_var("%p", lk_q.rear);
        show_var("%d", QueueEmpty(&lk_q));
    }

    print_title("Seq Queue");
    {
        SeqQueue sq_q;
        InitSeqQueue(&sq_q);
        show_var("%p", sq_q.rear);
        show_var("%d", SeqQueueLength(&sq_q));
        EnSeqQueue(&sq_q, 33);
        show_var("%p", sq_q.rear);
        show_var("%d", SeqQueueLength(&sq_q));
        EnSeqQueue(&sq_q, 58);
        show_var("%p", sq_q.rear);
        show_var("%d", SeqQueueLength(&sq_q));
        show_var("%d", *(sq_q.base+1));
        int e = 0;
        DeSeqQueue(&sq_q, &e);
        show_var("%d", e);
        show_var("%d", SeqQueueLength(&sq_q));
        EnSeqQueue(&sq_q, 413);
        EnSeqQueue(&sq_q, 997);
        EnSeqQueue(&sq_q, 5);
        DeSeqQueue(&sq_q, &e);
        show_var("%d", SeqQueueLength(&sq_q));
        EnSeqQueue(&sq_q, 23);
        EnSeqQueue(&sq_q, 17);
        show_var("%d", SeqQueueLength(&sq_q));
        EnSeqQueue(&sq_q, 71);
        show_var("%d", SeqQueueLength(&sq_q));
        EnSeqQueue(&sq_q, 29);
        EnSeqQueue(&sq_q, 108);
        EnSeqQueue(&sq_q, 811);
        EnSeqQueue(&sq_q, 911);
        show_var("%d", SeqQueueLength(&sq_q));
        show_var("%d", sq_q.size);
        DestroySeqQueue(&sq_q);
        show_var("%p", sq_q.base);
        InitSeqQueue(&sq_q);
        show_var("%p", sq_q.base);
        DestroySeqQueue(&sq_q);
    }

    return 0;
}