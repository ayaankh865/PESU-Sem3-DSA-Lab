#include <stdio.h>
#include "poly.h"

int main(void)
{
    poly_t poly1, poly2, sum;

    printf("Enter first polynomial:\n");
    poly1 = create_poly();

    printf("Enter second polynomial:\n");
    poly2 = create_poly();

    add_poly(poly1, poly2, &sum);

    printf("Polynomial 1: "); display_poly(poly1);
    printf("Polynomial 2: "); display_poly(poly2);
    printf("Sum         : "); display_poly(sum);

    destroy_poly(&poly1);
    destroy_poly(&poly2);
    destroy_poly(&sum);

    return 0;
}
