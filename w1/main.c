#include <stdio.h>
#include "date.h"
#include "event.h"
#include "eventlist.h"

int main(void)
{
    event_t events[MAX_EVENTS];
    int count;
    FILE *fp = fopen("events.txt", "r");

    if (fp == NULL)
    {
        printf("Could not open events.txt\n");
        return 1;
    }

    count = read_all(fp, events, MAX_EVENTS);
    fclose(fp);

    printf("Read %d events:\n\n", count);
    disp_all(events, count);

    event_t latest = find_latest(events, count);
    printf("\nLatest event: ");
    print_event(latest);

    int month = 12;
    int n = count_in_month(events, count, month);
    printf("\n%d event(s) found in month %d\n", n, month);

    return 0;
}