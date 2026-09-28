#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patient.h"

void admitPatient(Patient **head, char name[], int severity)
{
    Patient *newPatient = (Patient *)malloc(sizeof(Patient));

    if (newPatient == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    strcpy(newPatient->name, name);
    newPatient->severity = severity;
    newPatient->next = NULL;

    // Empty list
    if (*head == NULL)
    {
        *head = newPatient;
        return;
    }

    // Higher priority (lower severity number)
    if (severity < (*head)->severity)
    {
        newPatient->next = *head;
        *head = newPatient;
        return;
    }

    /*
     * Find the correct position.
     * We move past patients with severity <= new patient's severity.
     *
     * This is important because it preserves FIFO for
     * patients having the same severity.
     */
    Patient *current = *head;

    while (current->next != NULL &&
           current->next->severity <= severity)
    {
        current = current->next;
    }

    newPatient->next = current->next;
    current->next = newPatient;
}

Patient *treatNextPatient(Patient **head)
{
    if (*head == NULL)
    {
        return NULL;
    }

    Patient *treated = *head;
    *head = (*head)->next;

    treated->next = NULL;

    return treated;
}

void displayWaitingList(Patient *head)
{
    if (head == NULL)
    {
        printf("\nWaiting list is empty.\n");
        return;
    }

    printf("\n--- Current Waiting List ---\n");

    Patient *current = head;

    while (current != NULL)
    {
        printf("Name: %-20s Severity: %d",
               current->name, current->severity);

        if (current->severity == 1)
            printf(" (Critical)");
        else if (current->severity == 2)
            printf(" (Urgent)");
        else
            printf(" (Stable)");

        printf("\n");

        current = current->next;
    }
}