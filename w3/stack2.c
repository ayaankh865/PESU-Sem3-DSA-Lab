#include "stack2.h"
#include <stdio.h>
#include <stdlib.h>

void initStack(Stack *s)
{
    s->top = -1;
}

void clearStack(Stack *s)
{
    s->top = -1;
}

int isEmpty(const Stack *s)
{
    return s->top == -1;
}

int isFull(const Stack *s)
{
    return s->top == MAX_SIZE - 1;
}

int isFullStack(const Stack *s)
{
    return isFull(s);
}

void push(Stack *s, double value)
{
    if (isFull(s)) {
        fprintf(stderr, "Error: stack overflow\n");
        exit(EXIT_FAILURE);
    }

    s->data[++s->top] = value;
}

double pop(Stack *s)
{
    if (isEmpty(s)) {
        fprintf(stderr, "Error: stack underflow\n");
        exit(EXIT_FAILURE);
    }

    return s->data[s->top--];
}

double peek(const Stack *s)
{
    if (isEmpty(s)) {
        fprintf(stderr, "Error: stack is empty\n");
        exit(EXIT_FAILURE);
    }

    return s->data[s->top];
}