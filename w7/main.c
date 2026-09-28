#include <stdio.h>
#include <stdlib.h>
#include "patient.h"

int main()
{
    Patient *head = NULL;

    int choice;
    int severity;
    char name[50];

    while (1)
    {
        printf("\n===== ER PATIENT SYSTEM =====\n");
        printf("1. Admit Patient\n");
        printf("2. Treat Next Patient\n");
        printf("3. Display Waiting List\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter patient name: ");
                scanf("%49s", name);

                printf("Enter severity (1-Critical, 2-Urgent, 3-Stable): ");
                scanf("%d", &severity);

                if (severity < 1 || severity > 3)
                {
                    printf("Invalid severity!\n");
                }
                else
                {
                    admitPatient(&head, name, severity);
                    printf("Patient admitted successfully.\n");
                }

                break;

            case 2:
            {
                Patient *patient = treatNextPatient(&head);

                if (patient == NULL)
                {
                    printf("No patients waiting.\n");
                }
                else
                {
                    printf("\nTreating patient: %s\n", patient->name);
                    printf("Severity: %d\n", patient->severity);

                    free(patient);
                }

                break;
            }

            case 3:
                displayWaitingList(head);
                break;

            case 4:
                // Free remaining patients
                while (head != NULL)
                {
                    Patient *temp = head;
                    head = head->next;
                    free(temp);
                }

                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}