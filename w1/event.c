#include <stdio.h>
#include "event.h"

void read_event(FILE *fp, event_t *e)
{
    read_date(fp, &e->d);
    fscanf(fp, "%s", e->detail);
}

void print_event(event_t e)
{
    print_date(e.d);
    printf(" %s\n", e.detail);
}

int compare_event(event_t e1, event_t e2)
{
    return compare_date(e1.d, e2.d);
}