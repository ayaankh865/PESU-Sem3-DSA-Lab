#include <stdio.h>
#include "rect.h"

int main(void)
{
    struct rect r;
    int length, breadth;

    printf("Enter length and breadth: ");
    scanf("%d %d", &length, &breadth);

    set_rect(&r, length, breadth);

    printf("\nRectangle:\n");
    display_rect(&r);

    printf("\nArea = %d\n", area(&r));

    return 0;
}