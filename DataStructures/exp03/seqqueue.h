#ifndef SEQQUEUE_H
#define SEQQUEUE_H

#include <stdlib.h>
#include "../mydef.h"

#define QUEUE_INIT_SIZE (5)
#define QUEUEINCREMENT (2)

typedef struct
{
    int *base;

    int *front;
    int *rear;

    int size;
} SeqQueue;

Status InitSeqQueue(SeqQueue *Q);
Status DestroySeqQueue(SeqQueue *Q);
int SeqQueueLength(const SeqQueue *Q);
Status EnSeqQueue(SeqQueue *Q, int e);
Status DeSeqQueue(SeqQueue *Q, int *e);

#endif