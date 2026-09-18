#include <stdio.h>
#include "queue.h"

int main(void) {
    Queue q;
    queueInit(&q);

    int choice, value;
    printf("\n----- Queue (implemented using Deque) -----\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    while (1) {
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            break;
        }
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                queueEnqueue(&q, value);
                break;

            case 2:
                if (queueDequeue(&q, &value)) {
                    printf("Dequeued value: %d\n", value);
                } else {
                    printf("Queue is empty.\n");
                }
                break;

            case 3:
                queueDisplay(&q);
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
