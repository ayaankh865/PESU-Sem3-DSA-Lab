#include <stdio.h>
#include "pqueue.h"

int main(void) {
    PriorityQueue pq;
    pqInit(&pq);

    int choice;
    int depth, traffic;
    PQNode job;

    while (1) {
        printf("\n----- Pothole Repair Priority Queue -----\n");
        printf("1. Add Pothole Job (Enqueue)\n");
        printf("2. Process Highest Priority Job (Dequeue)\n");
        printf("3. Display All Pending Jobs\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter pothole depth (1-5): ");
                scanf("%d", &depth);
                printf("Enter traffic heaviness (1-5): ");
                scanf("%d", &traffic);
                pqEnqueue(&pq, depth, traffic);
                break;

            case 2:
                if (pqDequeue(&pq, &job)) {
                    printf("Processing Job %d (Depth=%d, Traffic=%d, Priority=%d)\n",
                           job.jobID, job.depth, job.traffic, job.priority);
                } else {
                    printf("No pending jobs to process.\n");
                }
                break;

            case 3:
                pqDisplay(&pq);
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
