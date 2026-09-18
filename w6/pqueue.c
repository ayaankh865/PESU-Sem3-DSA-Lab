#include <stdio.h>
#include <stdlib.h>
#include "pqueue.h"

void pqInit(PriorityQueue *pq) {
    pq->front = NULL;
    pq->nextJobID = 1;
}

int pqIsEmpty(const PriorityQueue *pq) {
    return pq->front == NULL;
}

/*
 * enqueue(): walk the list with a loop and insert the new job at the
 * position that keeps the list sorted in descending order of priority.
 * O(n) worst case -- the cost we accept in exchange for O(1) dequeue.
 */
void pqEnqueue(PriorityQueue *pq, int depth, int traffic) {
    PQNode *newNode = (PQNode *) malloc(sizeof(PQNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->jobID   = pq->nextJobID++;
    newNode->depth   = depth;
    newNode->traffic = traffic;
    newNode->priority = depth + traffic;
    newNode->next    = NULL;

    /* Case 1: empty list, or new job has strictly higher priority
     * than the current front -- insert at the front. */
    if (pq->front == NULL || newNode->priority > pq->front->priority) {
        newNode->next = pq->front;
        pq->front = newNode;
    } else {
        /* Case 2: walk the list to find the last node whose priority
         * is >= the new job's priority, then insert right after it. */
        PQNode *curr = pq->front;
        while (curr->next != NULL && curr->next->priority >= newNode->priority) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }

    printf("Job %d added with priority %d.\n", newNode->jobID, newNode->priority);
}

/*
 * dequeue(): simply remove the node pointed to by front.
 * No search is required -- O(1).
 */
int pqDequeue(PriorityQueue *pq, PQNode *outJob) {
    if (pqIsEmpty(pq)) {
        return 0;
    }

    PQNode *temp = pq->front;
    *outJob = *temp;       /* copy the job data out for the caller */
    outJob->next = NULL;

    pq->front = pq->front->next;
    free(temp);
    return 1;
}

void pqDisplay(const PriorityQueue *pq) {
    if (pqIsEmpty(pq)) {
        printf("No pending jobs.\n");
        return;
    }

    printf("JobID\tDepth\tTraffic\tPriority\n");
    printf("--------------------------------------\n");

    const PQNode *curr = pq->front;
    while (curr != NULL) {
        printf("%d\t%d\t%d\t%d\n", curr->jobID, curr->depth, curr->traffic, curr->priority);
        curr = curr->next;
    }
}
