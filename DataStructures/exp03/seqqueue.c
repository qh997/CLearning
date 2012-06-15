#include "seqqueue.h"

Status InitSeqQueue(SeqQueue *Q)
{
    if (NULL == (Q->base = (int *)malloc(QUEUE_INIT_SIZE * sizeof(int))))
        return OVERFLOW;

    Q->front = Q->rear = NULL;
    Q->size = QUEUE_INIT_SIZE;
    
    return OK;
}

Status DestroySeqQueue(SeqQueue *Q)
{
    if (NULL != Q->base)
        free(Q->base);

    Q->base = Q->front = Q->rear = NULL;
    Q->size = 0;
}

int SeqQueueLength(const SeqQueue *Q)
{
    if (NULL == Q->front)
        return 0;
    else
        return(
            (
                (Q->rear - Q->front)
                + Q->size
            ) % Q->size
            + 1
        );
}

Status EnSeqQueue(SeqQueue *Q, int e)
{

    if (NULL == Q->front)
    {
        Q->front = Q->rear = Q->base;
    }
    else
    {
        if (Q->size == SeqQueueLength(Q))
        {
            int *newbase, *p;
            if (NULL == (p = newbase = (int *)malloc((Q->size + QUEUEINCREMENT) * sizeof(int))))
                return OVERFLOW;

            int tmp = 0;
            while (ERROR != DeSeqQueue(Q, &tmp))
                *p++ = tmp;

            free(Q->base);
            Q->front = Q->base = newbase;
            Q->rear = --p;

            Q->size += QUEUEINCREMENT;
        }

        Q->rear = Q->base + (Q->rear + 1 - Q->base) % Q->size;
    }

    *Q->rear = e;

    return OK;
}

Status DeSeqQueue(SeqQueue *Q, int *e)
{
    if (NULL == Q->front)
        return ERROR;

    *e = *Q->front;

    if (Q->front == Q->rear)
        Q->front = Q->rear = NULL;
    else
    {
        Q->front = Q->base + (Q->front + 1 - Q->base) % Q->size;
    }

    return OK;
}