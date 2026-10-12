#ifndef QUEUE_H
#define QUEUE_H

#include "tree.h"

typedef struct queue_node
{
    tree_node_t *data_;
    struct queue_node *next_;
} queue_node_t;

typedef struct
{
    queue_node_t *front_;
    queue_node_t *rear_;
} queue_t;

void init_queue(queue_t *ptr_q);
void deinit_queue(queue_t *ptr_q);
void enqueue(queue_t *ptr_q, tree_node_t *data);
tree_node_t *dequeue(queue_t *ptr_q);
int is_empty(queue_t *ptr_q);
int is_full(queue_t *ptr_q);

#endif
