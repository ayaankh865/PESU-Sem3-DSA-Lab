#include <stdlib.h>
#include "queue.h"

static queue_node_t *create_node(tree_node_t *data)
{
    queue_node_t *n = (queue_node_t *)malloc(sizeof(queue_node_t));
    if (n != NULL)
    {
        n->data_ = data;
        n->next_ = NULL;
    }
    return n;
}

void init_queue(queue_t *ptr_q)
{
    ptr_q->front_ = ptr_q->rear_ = NULL;
}

void deinit_queue(queue_t *ptr_q)
{
    while (ptr_q->front_ != NULL)
    {
        queue_node_t *t = ptr_q->front_;
        ptr_q->front_ = t->next_;
        free(t);                 /* frees queue node only, not the tree node */
    }
    ptr_q->rear_ = NULL;
}

void enqueue(queue_t *ptr_q, tree_node_t *data)
{
    queue_node_t *n = create_node(data);
    if (n == NULL) return;
    if (ptr_q->rear_ == NULL)
        ptr_q->front_ = ptr_q->rear_ = n;
    else
    {
        ptr_q->rear_->next_ = n;
        ptr_q->rear_ = n;
    }
}

tree_node_t *dequeue(queue_t *ptr_q)
{
    if (ptr_q->front_ == NULL) return NULL;
    queue_node_t *t = ptr_q->front_;
    tree_node_t *d = t->data_;
    ptr_q->front_ = t->next_;
    if (ptr_q->front_ == NULL) ptr_q->rear_ = NULL;
    free(t);
    return d;
}

int is_empty(queue_t *ptr_q) { return ptr_q->front_ == NULL; }
int is_full(queue_t *ptr_q)  { (void)ptr_q; return 0; }
