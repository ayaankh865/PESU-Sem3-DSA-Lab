#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

void dequeInit(Deque *dq) {
    dq->front = NULL;
    dq->rear = NULL;
}

int dequeIsEmpty(const Deque *dq) {
    return dq->front == NULL;
}

void insertFront(Deque *dq, int value) {
    DNode *newNode = (DNode *) malloc(sizeof(DNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = dq->front;

    if (dq->front != NULL) {
        dq->front->prev = newNode;
    } else {
        dq->rear = newNode; /* list was empty */
    }
    dq->front = newNode;
}

void insertRear(Deque *dq, int value) {
    DNode *newNode = (DNode *) malloc(sizeof(DNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = dq->rear;

    if (dq->rear != NULL) {
        dq->rear->next = newNode;
    } else {
        dq->front = newNode; /* list was empty */
    }
    dq->rear = newNode;
}

int deleteFront(Deque *dq, int *outValue) {
    if (dequeIsEmpty(dq)) {
        return 0;
    }
    DNode *temp = dq->front;
    *outValue = temp->data;

    dq->front = dq->front->next;
    if (dq->front != NULL) {
        dq->front->prev = NULL;
    } else {
        dq->rear = NULL; /* list is now empty */
    }
    free(temp);
    return 1;
}

int deleteRear(Deque *dq, int *outValue) {
    if (dequeIsEmpty(dq)) {
        return 0;
    }
    DNode *temp = dq->rear;
    *outValue = temp->data;

    dq->rear = dq->rear->prev;
    if (dq->rear != NULL) {
        dq->rear->next = NULL;
    } else {
        dq->front = NULL; /* list is now empty */
    }
    free(temp);
    return 1;
}

void dequeDisplay(const Deque *dq) {
    if (dequeIsEmpty(dq)) {
        printf("Deque is empty.\n");
        return;
    }
    printf("Front -> ");
    const DNode *curr = dq->front;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("<- Rear\n");
}
