#include <stdio.h>
#include "list.h"

int main(void)
{
    list_t list;
    struct rect result;

    int n;
    int length;
    int breadth;
    int i;

    double unit_area_value;

    init_list(&list);

    printf("Enter number of sites: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter length and breadth of site %d: ", i + 1);
        scanf("%d %d", &length, &breadth);

        if (!insert(&list, length, breadth))
        {
            printf("Memory allocation failed.\n");
            clear_list(&list);
            return 1;
        }
    }

    printf("\nOrdered List of Sites:\n");
    display_list(&list);

    printf("\nEnter value of one unit area: ");
    scanf("%lf", &unit_area_value);

    printf("Total layout value = %.2f\n",
           layout_value(&list, unit_area_value));

    if (highest_length(&list, &result))
    {
        printf("\nSite with highest length:\n");
        display_rect(&result);
        printf(", Area = %d\n", area(&result));
    }

    if (least_breadth(&list, &result))
    {
        printf("\nSite with least breadth:\n");
        display_rect(&result);
        printf(", Area = %d\n", area(&result));
    }

    clear_list(&list);

    return 0;
}