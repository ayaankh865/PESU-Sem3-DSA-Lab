#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "stack2.h"

int isOperator(const char *token)
{
    return strlen(token) == 1 &&
           (token[0] == '+' ||
            token[0] == '-' ||
            token[0] == '*' ||
            token[0] == '/' ||
            token[0] == '^');
}

int applyOperator(char op, double left, double right, double *result)
{
    switch (op) {

        case '+':
            *result = left + right;
            return 1;

        case '-':
            *result = left - right;
            return 1;

        case '*':
            *result = left * right;
            return 1;

        case '/':
            if (right == 0.0) {
                return 0;
            }

            *result = left / right;
            return 1;

        case '^':
            *result = pow(left, right);
            return 1;

        default:
            return 0;
    }
}

int evaluatePostfix(const char *expression,
                    double *result,
                    Stack *stack,
                    char *errorMessage)
{
    char input[1000];
    char *token;

    strcpy(input, expression);

    token = strtok(input, " \t\r\n");

    if (token == NULL) {
        strcpy(errorMessage, "empty expression");
        return 0;
    }

    while (token != NULL) {

        char *endptr;
        double value;

        /*
         * Try to interpret the token as a number.
         */
        value = strtod(token, &endptr);

        if (*endptr == '\0') {

            push(stack, value);
        }
        else if (isOperator(token)) {

            double rightOperand;
            double leftOperand;
            double calculatedResult;

            /*
             * Right operand is popped FIRST.
             */
            if (isEmpty(stack)) {
                strcpy(errorMessage, "stack underflow");
                return 0;
            }

            rightOperand = pop(stack);

            /*
             * Left operand is popped SECOND.
             */
            if (isEmpty(stack)) {
                strcpy(errorMessage, "stack underflow");
                return 0;
            }

            leftOperand = pop(stack);

            if (token[0] == '/' && rightOperand == 0.0) {
                strcpy(errorMessage, "division by zero");
                return 0;
            }

            if (!applyOperator(token[0],
                                leftOperand,
                                rightOperand,
                                &calculatedResult)) {

                strcpy(errorMessage, "invalid operator");
                return 0;
            }

            push(stack, calculatedResult);
        }
        else {

            strcpy(errorMessage, "invalid token");
            return 0;
        }

        token = strtok(NULL, " \t\r\n");
    }

    /*
     * Exactly one result must remain.
     */
    if (isEmpty(stack)) {
        strcpy(errorMessage, "malformed expression");
        return 0;
    }

    if (stack->top != 0) {
        strcpy(errorMessage, "leftover operands");
        return 0;
    }

    *result = pop(stack);

    return 1;
}

int main(void)
{
    Stack stack;
    char input[1000];
    char errorMessage[100];

    initStack(&stack);

    while (1) {

        double result;

        printf("postfix> ");

        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        /*
         * Remove newline.
         */
        input[strcspn(input, "\n")] = '\0';

        /*
         * Check exit commands.
         */
        if (strcmp(input, "exit") == 0 ||
            strcmp(input, "quit") == 0) {
            break;
        }

        /*
         * Reset stack before every expression.
         */
        clearStack(&stack);

        if (evaluatePostfix(input,
                            &result,
                            &stack,
                            errorMessage)) {

            printf("Result = %g\n", result);
        }
        else {

            printf("Error: %s\n", errorMessage);
        }
    }

    return 0;
}