#include <stdio.h>
#include "stack.h"

void initStack(Stack *s)
{
    s->top = -1;
}

int isFull(Stack *s)
{
    return s->top == MAX_SIZE - 1;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

int push(Stack *s, int value)
{
    if (isFull(s))
    {
        printf("Memory Manager: Stack is full. Cannot free index %d.\n", value);
        return 0;
    }

    s->data[++s->top] = value;
    return 1;
}

int pop(Stack *s, int *value)
{
    if (isEmpty(s))
    {
        printf("Memory Manager: No free node available.\n");
        return 0;
    }

    *value = s->data[s->top--];
    return 1;
}