#include <stdio.h>
#include "poly.h"

int main(void)
{
    poly_t poly, integrated_poly;
    double lower_limit, upper_limit;
    double result;

    printf("Enter the polynomial to integrate:\n");
    poly = create_poly();

    integrated_poly = integrate_poly(poly);

    printf("Enter lower limit: ");
    scanf("%lf", &lower_limit);
    printf("Enter upper limit: ");
    scanf("%lf", &upper_limit);

    result = eval_poly(integrated_poly, upper_limit)
           - eval_poly(integrated_poly, lower_limit);

    printf("Polynomial           : "); display_poly(poly);
    printf("Integrated Polynomial: "); display_poly(integrated_poly);
    printf("Definite integral from %.2lf to %.2lf = %.4lf\n",
           lower_limit, upper_limit, result);

    destroy_poly(&poly);
    destroy_poly(&integrated_poly);

    return 0;
}
