#ifndef POLY_H
#define POLY_H

#include "term.h"

typedef struct {
    term_t *head;
} poly_t;

poly_t create_poly(void);
void display_poly(poly_t poly);
void add_poly(poly_t poly1, poly_t poly2, poly_t *sum);
void destroy_poly(poly_t *poly);
double eval_poly(poly_t poly, double x);
poly_t integrate_poly(poly_t poly);

#endif
