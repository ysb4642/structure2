#ifndef __DEQUE_BASE_QUEUE_H
#define __DEQUE_BASE_QUEUE_H

#include "Deque.h"

typedef Deque Queue;

void QueueInit(Queue *pq);
int QIsEmpty(Queue *pq);

void Enqueue(Queue *pq, Data data);
Data Dequeue(Queue *pq);
Data QPeek(Queue *pq);

#endif
