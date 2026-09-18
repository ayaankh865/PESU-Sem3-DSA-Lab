#ifndef DEQUE_H
#define DEQUE_H

/*
 * Double-Ended Queue (Deque)
 * ---------------------------
 * A doubly linked list supporting insertion and deletion at both
 * the front and the rear. This is the given/base module: it owns
 * all the linked-list logic and is used only through the public
 * functions declared below.
 */

typedef struct DNode {
    int data;
    struct DNode *prev;
    struct DNode *next;
} DNode;

typedef struct {
    DNode *front;
    DNode *rear;
} Deque;

void dequeInit(Deque *dq);
int  dequeIsEmpty(const Deque *dq);

void insertFront(Deque *dq, int value);
void insertRear(Deque *dq, int value);

int  deleteFront(Deque *dq, int *outValue); /* returns 1 on success, 0 if empty */
int  deleteRear(Deque *dq, int *outValue);  /* returns 1 on success, 0 if empty */

void dequeDisplay(const Deque *dq);

#endif /* DEQUE_H */
