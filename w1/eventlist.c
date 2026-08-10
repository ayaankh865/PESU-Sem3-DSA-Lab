#include "eventlist.h"

int read_all(FILE *fp, event_t e[], int n)
{
    int count = 0;

    while (count < n &&
           fscanf(fp, "%d-%d-%d %s",
                  &e[count].d.dd,
                  &e[count].d.mm,
                  &e[count].d.yy,
                  e[count].detail) == 4)
    {
        count++;
    }

    return count;
}

void disp_all(event_t e[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        print_event(e[i]);
    }
}

event_t find_latest(event_t e[], int n)
{
    int i;
    event_t latest = e[0];

    for (i = 1; i < n; i++)
    {
        if (compare_event(e[i], latest) > 0)
        {
            latest = e[i];
        }
    }

    return latest;
}

int count_in_month(event_t e[], int n, int month)
{
    int i, count = 0;

    for (i = 0; i < n; i++)
    {
        if (e[i].d.mm == month)
        {
            count++;
        }
    }

    return count;
}