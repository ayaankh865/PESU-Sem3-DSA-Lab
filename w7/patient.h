#ifndef PATIENT_H
#define PATIENT_H

typedef struct Patient {
    char name[50];
    int severity;
    struct Patient *next;
} Patient;

void admitPatient(Patient **head, char name[], int severity);
Patient *treatNextPatient(Patient **head);
void displayWaitingList(Patient *head);

#endif