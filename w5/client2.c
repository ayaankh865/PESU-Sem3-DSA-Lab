#include <stdio.h>
#include "clist.h"

int main(void)
{
    clist_t list;
    int n;
    int k;
    int i;
    int removed_key;
    char name[NAME_SIZE];

    init(&list);

    printf("Enter number of people (n): ");

    if (scanf("%d", &n) != 1 || n < 1)
    {
        printf("Invalid input. n must be at least 1.\n");
        return 1;
    }

    /*
     * Read names and create the circular list.
     */
    printf("\nEnter names:\n");

    for (i = 1; i <= n; i++)
    {
        printf("Person %d: ", i);

        scanf(" %99[^\n]", name);

        add_person(&list, i, name);
    }

    printf("\nEnter the count k [kth element is removed]: ");

    if (scanf("%d", &k) != 1 || k < 1)
    {
        printf("Invalid input. k must be at least 1.\n");
        deinit(&list);
        return 1;
    }

    printf("\nElimination order:\n");

    for (i = 1; i <= n - 1; i++)
    {
        find_kth_person(&list, k, name, &removed_key);

        printf("Round %d: %s (person #%d) executed\n",
               i,
               name,
               removed_key);
    }

    /*
     * Exactly one node remains.
     */
    if (list.current_ != NULL)
    {
        printf("\nSurvivor -> %s (person #%d)\n",
               list.current_->next_->name_,
               list.current_->next_->key_);
    }

    deinit(&list);

    return 0;
}