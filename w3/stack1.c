#include "stack1.h"

void initStack(Stack *s) {
    s->top = -1;
}

void push(Stack *s, char value) {
    if (!isFull(s))
        s->data[++s->top] = value;
}

char pop(Stack *s) {
    if (!isEmpty(s))
        return s->data[s->top--];
    return '\0';
}

char peek(Stack *s) {
    if (!isEmpty(s))
        return s->data[s->top];
    return '\0';
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void clearStack(Stack *s) {
    s->top = -1;
}