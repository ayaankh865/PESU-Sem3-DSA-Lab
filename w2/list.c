#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void init_list(list_t *list)
{
    list->head = NULL;
}

int insert(list_t *list, int length, int breadth)
{
    node_t *new_node;
    struct rect new_rect;
    node_t *current;

    set_rect(&new_rect, length, breadth);

    new_node = malloc(sizeof(node_t));

    if (new_node == NULL)
    {
        return 0;
    }

    new_node->data = new_rect;
    new_node->next = NULL;

    /*
     * Insert at the beginning if:
     * 1. The list is empty
     * 2. New rectangle has smaller area than the first rectangle
     */
    if (list->head == NULL ||
        compare(&new_node->data, &list->head->data))
    {
        new_node->next = list->head;
        list->head = new_node;
        return 1;
    }

    /*
     * Find the correct position.
     *
     * Equal-area rectangles are placed AFTER
     * existing equal-area rectangles.
     */
    current = list->head;

    while (current->next != NULL &&
           !compare(&new_node->data, &current->next->data))
    {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;

    return 1;
}

void display_list(const list_t *list)
{
    const node_t *current;
    int count = 1;

    current = list->head;

    if (current == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    while (current != NULL)
    {
        printf("Site %d: ", count);
        display_rect(&current->data);
        printf(", Area = %d\n", area(&current->data));

        current = current->next;
        count++;
    }
}

double layout_value(const list_t *list, double unit_area_value)
{
    const node_t *current;
    double total = 0;

    current = list->head;

    while (current != NULL)
    {
        total += area(&current->data) * unit_area_value;
        current = current->next;
    }

    return total;
}

int highest_length(const list_t *list, struct rect *result)
{
    const node_t *current;

    if (list->head == NULL)
    {
        return 0;
    }

    current = list->head;
    *result = current->data;

    current = current->next;

    while (current != NULL)
    {
        if (current->data.length > result->length)
        {
            *result = current->data;
        }

        current = current->next;
    }

    return 1;
}

int least_breadth(const list_t *list, struct rect *result)
{
    const node_t *current;

    if (list->head == NULL)
    {
        return 0;
    }

    current = list->head;
    *result = current->data;

    current = current->next;

    while (current != NULL)
    {
        if (current->data.breadth < result->breadth)
        {
            *result = current->data;
        }

        current = current->next;
    }

    return 1;
}

void clear_list(list_t *list)
{
    node_t *current;
    node_t *next;

    current = list->head;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    list->head = NULL;
}