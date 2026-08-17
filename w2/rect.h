#ifndef RECT_H
#define RECT_H

struct rect
{
    int length;
    int breadth;
};

void set_rect(struct rect *r, int length, int breadth);
void display_rect(const struct rect *r);
int area(const struct rect *r);
int compare(const struct rect *r1, const struct rect *r2);

#endif