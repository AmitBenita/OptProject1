#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "rational.h"

RATIONALNUMBER zero = { 1, 0, 1, "0" };

// Function to compute the greatest common divisor (GCD)
long long int gcd(long long int a, long long int b) {
    while (b != 0) {
        long long int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

void rationalnumber_init(RATIONALNUMBER_PTR xptr, int sign, long long int num, long long int denom) {
    if (num == 0) {
        xptr->sign = 1;
        xptr->num = 0;
        xptr->denom = 1;
    } else {
        long long int temp = gcd(num, denom);
        xptr->sign = sign;
        xptr->num = num / temp;
        xptr->denom = denom / temp;
    }

    snprintf(xptr->str_form, STRSIZE, "%lg", (double)xptr->num / xptr->denom * xptr->sign);
}

double rational_to_double(RATIONALNUMBER x) {
    if (x.denom == 0) {
        fprintf(stderr, "Error: Denominator cannot be zero.\n");
        exit(EXIT_FAILURE);
    }
    return x.sign * (double)x.num / x.denom;
}

void rationalnumber_print(const RATIONALNUMBER_PTR xptr) {
    printf("%s", xptr->str_form);
}

void rationalnumber_assign_const(RATIONALNUMBER_PTR dest, const char* str) {
    double dtemp = atof(str);
    int sign = (dtemp < 0) ? -1 : 1;
    dtemp = fabs(dtemp);

    long long int denom = 1;
    const char* p = strchr(str, '.');
    if (p != NULL) {
        denom = pow(10, strlen(p + 1));
    }
    long long int num = (long long int)(dtemp * denom);
    rationalnumber_init(dest, sign, num, denom);
}

void rationalnumber_add(RATIONALNUMBER_PTR dest, RATIONALNUMBER a, RATIONALNUMBER b) {
    long long int num = a.sign * a.num * b.denom + b.sign * b.num * a.denom;
    long long int denom = a.denom * b.denom;
    int sign = (num < 0) ? -1 : 1;
    rationalnumber_init(dest, sign, llabs(num), denom);
}

void rationalnumber_sub(RATIONALNUMBER_PTR dest, RATIONALNUMBER a, RATIONALNUMBER b) {
    b.sign = -b.sign;
    rationalnumber_add(dest, a, b);
    b.sign = -b.sign; // Restore original sign
}

void rationalnumber_mult(RATIONALNUMBER_PTR dest, RATIONALNUMBER a, RATIONALNUMBER b) {
    long long int num = a.num * b.num;
    long long int denom = a.denom * b.denom;
    int sign = a.sign * b.sign;
    rationalnumber_init(dest, sign, num, denom);
}

void rationalnumber_div(RATIONALNUMBER_PTR dest, RATIONALNUMBER a, RATIONALNUMBER b) {
    if (b.num == 0) {
        fprintf(stderr, "Error: Division by zero.\n");
        exit(EXIT_FAILURE);
    }
    long long int num = a.num * b.denom;
    long long int denom = a.denom * b.num;
    int sign = a.sign * b.sign;
    rationalnumber_init(dest, sign, num, denom);
}

RATIONALNUMBER rationalnumber_fabs(RATIONALNUMBER src) {
    src.sign = 1;
    return src;
}

RATIONALNUMBER rationalnumber_neg(RATIONALNUMBER src) {
    src.sign = -src.sign;
    return src;
}

int rationalnumber_is_zero(const RATIONALNUMBER_PTR xptr) {
    return xptr->num == 0;
}

int rationalnumber_is_negative(const RATIONALNUMBER_PTR xptr) {
    return xptr->sign < 0;
}

int rationalnumber_is_positive(const RATIONALNUMBER_PTR xptr) {
    return xptr->sign > 0;
}

int rationalnumber_is_equal(const RATIONALNUMBER_PTR a, const RATIONALNUMBER_PTR b) {
    return (a->sign == b->sign) && (a->num == b->num) && (a->denom == b->denom);
}

int rationalnumber_is_not_equal(const RATIONALNUMBER_PTR a, const RATIONALNUMBER_PTR b) {
    return !rationalnumber_is_equal(a, b);
}

int rationalnumber_is_greater(const RATIONALNUMBER_PTR a, const RATIONALNUMBER_PTR b) {
    return rational_to_double(*a) > rational_to_double(*b);
}

int rationalnumber_is_less(const RATIONALNUMBER_PTR a, const RATIONALNUMBER_PTR b) {
    return rational_to_double(*a) < rational_to_double(*b);
}

int rationalnumber_is_less_or_equal(const RATIONALNUMBER_PTR a, const RATIONALNUMBER_PTR b) {
    return !rationalnumber_is_greater(a, b);
}

int rationalnumber_is_greater_or_equal(const RATIONALNUMBER_PTR a, const RATIONALNUMBER_PTR b) {
    return !rationalnumber_is_less(a, b);
}

void copy_rationalnumber(RATIONALNUMBER_PTR dest, const RATIONALNUMBER a) {
    rationalnumber_init(dest, a.sign, a.num, a.denom);
}

int rationalnumber_which_is_larger(RATIONALNUMBER a, RATIONALNUMBER b, RATIONALNUMBER_PTR* smaller, RATIONALNUMBER_PTR* larger) {
    if (rationalnumber_is_greater(&a, &b)) {
        *larger = &a;
        *smaller = &b;
        return 1;
    } else {
        *larger = &b;
        *smaller = &a;
        return -1;
    }
}

int which_is_larger(RATIONALNUMBER a, RATIONALNUMBER b, RATIONALNUMBER_PTR smaller, RATIONALNUMBER_PTR larger) {
    if (rational_to_double(a) > rational_to_double(b)) {
        copy_rationalnumber(larger, a);
        copy_rationalnumber(smaller, b);
        return 1;
    } else {
        copy_rationalnumber(larger, b);
        copy_rationalnumber(smaller, a);
        return -1;
    }
}
