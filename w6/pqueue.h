#ifndef PQUEUE_H
#define PQUEUE_H

/*
 * Priority Queue for Pothole Repair Scheduling
 * ----------------------------------------------
 * Implemented as a singly linked list, kept sorted in DESCENDING
 * order of priority. Only a single pointer (front) is stored in
 * the queue structure -- there is no rear pointer.
 *
 *   enqueue()  -> O(n) : walks the list to find the correct
 *                        sorted position for the new job.
 *   dequeue()  -> O(1) : always removes the node at front, since
 *                        the highest-priority job is always there.
 */

typedef struct PQNode {
    int jobID;
    int depth;          /* 1-5 */
    int traffic;         /* 1-5 */
    int priority;         /* depth + traffic, range 2-10 */
    struct PQNode *next;
} PQNode;

typedef struct {
    PQNode *front;       /* the ONLY pointer kept -- no rear */
    int nextJobID;
} PriorityQueue;

void pqInit(PriorityQueue *pq);
void pqEnqueue(PriorityQueue *pq, int depth, int traffic);
int  pqDequeue(PriorityQueue *pq, PQNode *outJob); /* returns 1 on success, 0 if empty */
int  pqIsEmpty(const PriorityQueue *pq);
void pqDisplay(const PriorityQueue *pq);

#endif /* PQUEUE_H */
