#include <stdio.h>
#include "rect.h"

void set_rect(struct rect *r, int length, int breadth)
{
    r->length = length;
    r->breadth = breadth;
}

void display_rect(const struct rect *r)
{
    printf("Length = %d, Breadth = %d", r->length, r->breadth);
}

int area(const struct rect *r)
{
    return r->length * r->breadth;
}

int compare(const struct rect *r1, const struct rect *r2)
{
    return area(r1) < area(r2);
}