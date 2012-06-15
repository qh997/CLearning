#include "linkedqueue.h"

Status InitQueue(LinkQueue *Q)
{
    Q->front = Q->rear = NULL;

    return OK;
}

Status DestroyQueue(LinkQueue *Q)
{
    while (NULL != Q->front)
    {
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
}

bool QueueEmpty(const LinkQueue *Q)
{
    if (NULL == Q->front)
        return TRUE;
    else
        return FALSE;
}

int QueueLength(const LinkQueue *Q)
{
    QueuePtr p_qn = Q->front;
    int count = 0;
    while (NULL != p_qn)
    {
        count++;
        p_qn = p_qn->next;
    }

    return count;
}

Status EnQueue(LinkQueue *Q, int e)
{
    QueuePtr p_qn;
    if (NULL == (p_qn = (QueuePtr)malloc(sizeof(QNode))))
        return OVERFLOW;

    if (NULL == Q->front)
        Q->front = Q->rear = p_qn;
    else
    {
        Q->rear->next = p_qn;
        Q->rear = Q->rear->next;
    }

    Q->rear->data = e;
    Q->rear->next = NULL;

    return OK;
}

Status DeQueue(LinkQueue *Q, int *e)
{
    if (NULL == Q->front)
        return ERROR;

    *e = Q->front->data;
    QueuePtr del = Q->front;
    Q->front = Q->front->next;
    if (del == Q->rear)
        Q->rear = NULL;

    free(del);

    return OK;
}