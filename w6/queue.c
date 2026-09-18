#include "queue.h"

void queueInit(Queue *q) {
    dequeInit(&q->dq);
}

int queueIsEmpty(const Queue *q) {
    return dequeIsEmpty(&q->dq);
}

/* Enqueue = insert at the REAR of the deque. */
void queueEnqueue(Queue *q, int value) {
    insertRear(&q->dq, value);
}

/* Dequeue = delete from the FRONT of the deque.
 * Using different ends for enqueue/dequeue is what gives FIFO order. */
int queueDequeue(Queue *q, int *outValue) {
    return deleteFront(&q->dq, outValue);
}

void queueDisplay(const Queue *q) {
    dequeDisplay(&q->dq);
}
