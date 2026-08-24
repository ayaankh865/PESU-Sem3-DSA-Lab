#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "stack1.h"

int precedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int isRightAssociative(char c) {
    return c == '^';
}

void convert(char *infix, char *postfix) {
    Stack s;
    int i = 0;
    int j = 0;
    char c;

    initStack(&s);

    while (infix[i] != '\0') {
        c = infix[i];

        if (isspace(c)) {
            i++;
            continue;
        }

        if (isalnum(c) || c == '_') {
            while (isalnum(infix[i]) || infix[i] == '_')
                postfix[j++] = infix[i++];

            postfix[j++] = ' ';
            continue;
        }

        if (c == '(') {
            push(&s,c);
        }
        else if (c == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
                postfix[j++] = ' ';
            }

            if (!isEmpty(&s) && peek(&s) == '(')
                pop(&s);
        }
        else if (isOperator(c)) {
            while (!isEmpty(&s) && peek(&s) != '(' &&
                  (precedence(peek(&s)) > precedence(c) ||
                  (precedence(peek(&s)) == precedence(c) && !isRightAssociative(c)))) {
                postfix[j++] = pop(&s);
                postfix[j++] = ' ';
            }

            push(&s,c);
        }

        i++;
    }

    while (!isEmpty(&s)) {
        if (peek(&s) != '(') {
            postfix[j++] = pop(&s);
            postfix[j++] = ' ';
        }
        else {
            pop(&s);
        }
    }

    postfix[j] = '\0';
}

int main() {
    char infix[200];
    char postfix[400];

    printf("Enter infix expression: ");
    fgets(infix,sizeof(infix),stdin);

    convert(infix,postfix);

    printf("Postfix expression: %s\n",postfix);

    return 0;
}