#ifndef LIST_H
#define LIST_H

#include "rect.h"

typedef struct node
{
    struct rect data;
    struct node *next;
} node_t;

typedef struct
{
    node_t *head;
} list_t;

void init_list(list_t *list);

int insert(list_t *list, int length, int breadth);

void display_list(const list_t *list);

double layout_value(const list_t *list, double unit_area_value);

int highest_length(const list_t *list, struct rect *result);

int least_breadth(const list_t *list, struct rect *result);

void clear_list(list_t *list);

#endif