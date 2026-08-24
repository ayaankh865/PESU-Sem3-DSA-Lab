#ifndef STACK_HS
#define STACK_HS

#define MAX_SIZE 100

typedef struct {
    double data[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *s);
void clearStack(Stack *s);

void push(Stack *s, double value);
double pop(Stack *s);
double peek(const Stack *s);

int isEmpty(const Stack *s);
int isFull(const Stack *s);
int isFullStack(const Stack *s);

#endif