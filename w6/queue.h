#ifndef QUEUE_H
#define QUEUE_H

#include "deque.h"

/*
 * Queue implemented by embedding a Deque ("has-a" relationship).
 * No new linked-list logic is written here -- every Queue
 * operation is expressed purely in terms of a Deque operation.
 */

typedef struct {
    Deque dq;
} Queue;

void queueInit(Queue *q);
int  queueIsEmpty(const Queue *q);
void queueEnqueue(Queue *q, int value);
int  queueDequeue(Queue *q, int *outValue); /* returns 1 on success, 0 if empty */
void queueDisplay(const Queue *q);

#endif /* QUEUE_H */
