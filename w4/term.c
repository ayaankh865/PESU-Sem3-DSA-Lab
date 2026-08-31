#include <stdio.h>
#include <stdlib.h>
#include "term.h"

term_t *create_term(double coeff, int exp)
{
    term_t *t = (term_t *) malloc(sizeof(term_t));
    if (t == NULL) {
        fprintf(stderr, "create_term: memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    t->coeff = coeff;
    t->exp   = exp;
    t->next  = NULL;
    return t;
}

void print_term(term_t *ptr_term, int is_first)
{
    if (ptr_term == NULL) {
        return;
    }

    double coeff = ptr_term->coeff;
    int    exp   = ptr_term->exp;
    double abs_coeff = (coeff < 0) ? -coeff : coeff;

    if (is_first) {
        if (coeff < 0) {
            printf("-");
        }
    } else {
        printf(coeff < 0 ? " - " : " + ");
    }

    if (exp == 0) {
        printf("%g", abs_coeff);
    } else if (exp == 1) {
        if (abs_coeff == 1.0) {
            printf("x");
        } else {
            printf("%gx", abs_coeff);
        }
    } else {
        if (abs_coeff == 1.0) {
            printf("x^%d", exp);
        } else {
            printf("%gx^%d", abs_coeff, exp);
        }
    }
}

void integrate_term(term_t *ptr_term, term_t *ptr_integrated_term)
{
    if (ptr_term == NULL || ptr_integrated_term == NULL) {
        return;
    }

    if (ptr_term->exp == -1) {
        fprintf(stderr,
            "integrate_term: warning - term with exponent -1 has no "
            "polynomial antiderivative (integral is c*ln|x|); "
            "writing a 0 placeholder term.\n");
        ptr_integrated_term->coeff = 0.0;
        ptr_integrated_term->exp   = 0;
        return;
    }

    ptr_integrated_term->coeff = ptr_term->coeff / (double)(ptr_term->exp + 1);
    ptr_integrated_term->exp   = ptr_term->exp + 1;
}
