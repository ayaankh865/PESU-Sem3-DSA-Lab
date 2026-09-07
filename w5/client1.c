#include <stdio.h>
#include "clist.h"

int main(void)
{
    clist_t list;
    int n;
    int k;
    int i;

    init(&list);

    printf("Enter number of people (n): ");

    if (scanf("%d", &n) != 1 || n < 1)
    {
        printf("Invalid input. n must be at least 1.\n");
        return 1;
    }

    for (i = 1; i <= n; i++)
    {
        add(&list, i);
    }

    printf("Enter the count k [kth element is removed]: ");

    if (scanf("%d", &k) != 1 || k < 1)
    {
        printf("Invalid input. k must be at least 1.\n");
        deinit(&list);
        return 1;
    }

    printf("\nInitial list:\n");
    disp(&list);

    printf("\nElimination process:\n");

    for (i = 1; i <= n - 1; i++)
    {
        find_kth(&list, k);

        printf("After round %d: ", i);
        disp(&list);
    }

    printf("\nSurvivor -> ");
    disp(&list);

    deinit(&list);

    return 0;
}