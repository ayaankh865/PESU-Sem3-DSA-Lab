#include <stdio.h>
#include "tree.h"

static void run(const char *title, const int *keys, int n)
{
    tree_t t;
    init(&t);
    for (int i = 0; i < n; ++i) insert(&t, keys[i]);

    printf("%s\n", title);
    disp(&t);
    level_order(&t);
    level_order_lines(&t);
    disp_tree(&t);
    printf("\n");
    deinit(&t);
}

int main(void)
{
    int a[] = {40, 20, 60, 10, 70, 30, 50};
    int b[] = {10, 20, 30, 40, 50, 60, 70};
    int d[] = {50, 30, 70, 20, 40, 60, 80, 35, 45, 65, 5, 100};

    run("Case 1: balanced", a, 7);
    run("Case 2: right-skewed", b, 7);
    run("Case 3: empty", NULL, 0);
    run("Case 4: B3 test", d, 12);
    return 0;
}
