#ifndef STACK_H
#define STACK_H

#define MAX 100

typedef struct {
    char data[MAX];
    int top;
} Stack;

void initStack(Stack *s);
void push(Stack *s, char value);
char pop(Stack *s);
char peek(Stack *s);
int isEmpty(Stack *s);
int isFull(Stack *s);
void clearStack(Stack *s);

#endif