#ifndef EVENTLIST_H
#define EVENTLIST_H

#include <stdio.h>
#include "event.h"

#define MAX_EVENTS 100

int read_all(FILE *fp, event_t e[], int n);
void disp_all(event_t e[], int n);
event_t find_latest(event_t e[], int n);
int count_in_month(event_t e[], int n, int month);

#endif