#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include <stdlib.h>
#include <stdbool.h>
#include "../mydef.h"

typedef struct qNode
{
    int data;
    struct qNode *next;
} QNode, *QueuePtr;

typedef struct
{
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;

Status InitQueue(LinkQueue *Q);
Status DestroyQueue(LinkQueue *Q);
bool QueueEmpty(const LinkQueue *Q);
int QueueLength(const LinkQueue *Q);
Status EnQueue(LinkQueue *Q, int e);
Status DeQueue(LinkQueue *Q, int *e);

#endif