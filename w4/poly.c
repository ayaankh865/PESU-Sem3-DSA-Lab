#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "poly.h"

static void append_term(poly_t *poly, double coeff, int exp)
{
    term_t *new_node = create_term(coeff, exp);

    if (poly->head == NULL) {
        poly->head = new_node;
        return;
    }

    term_t *cur = poly->head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = new_node;
}

poly_t create_poly(void)
{
    poly_t poly;
    poly.head = NULL;

    int n = 0;
    printf("Number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        double coeff;
        int exp;
        printf("Coefficient Exponent: ");
        scanf("%lf %d", &coeff, &exp);
        append_term(&poly, coeff, exp);
    }

    return poly;
}

void display_poly(poly_t poly)
{
    if (poly.head == NULL) {
        printf("0\n");
        return;
    }

    term_t *cur = poly.head;
    int is_first = 1;
    while (cur != NULL) {
        print_term(cur, is_first);
        is_first = 0;
        cur = cur->next;
    }
    printf("\n");
}

void add_poly(poly_t poly1, poly_t poly2, poly_t *sum)
{
    sum->head = NULL;

    term_t *p1 = poly1.head;
    term_t *p2 = poly2.head;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exp == p2->exp) {
            double combined = p1->coeff + p2->coeff;
            if (combined != 0.0) {
                append_term(sum, combined, p1->exp);
            }
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->exp > p2->exp) {
            append_term(sum, p1->coeff, p1->exp);
            p1 = p1->next;
        } else {
            append_term(sum, p2->coeff, p2->exp);
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        append_term(sum, p1->coeff, p1->exp);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        append_term(sum, p2->coeff, p2->exp);
        p2 = p2->next;
    }
}

void destroy_poly(poly_t *poly)
{
    term_t *cur = poly->head;
    while (cur != NULL) {
        term_t *next = cur->next;
        free(cur);
        cur = next;
    }
    poly->head = NULL;
}

double eval_poly(poly_t poly, double x)
{
    double result = 0.0;
    term_t *cur = poly.head;
    while (cur != NULL) {
        result += cur->coeff * pow(x, cur->exp);
        cur = cur->next;
    }
    return result;
}

poly_t integrate_poly(poly_t poly)
{
    poly_t result;
    result.head = NULL;

    term_t *cur = poly.head;
    while (cur != NULL) {
        term_t integrated;
        integrate_term(cur, &integrated);
        append_term(&result, integrated.coeff, integrated.exp);
        cur = cur->next;
    }

    return result;
}
