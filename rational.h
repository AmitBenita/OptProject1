#ifndef RATIONAL_H
#define RATIONAL_H

#define STRSIZE 80
#define DIGITSIZE 124

typedef struct rationalnumber {
    int sign;
    long long int num;
    long long int denom;
    char str_form[STRSIZE];
} RATIONAL, RATIONALNUMBER, *RATIONALNUMBER_PTR, *RATIONAL_PTR;

// Global Variables
extern RATIONALNUMBER zero;

// Function Prototypes
long long int gcd(long long int a, long long int b);
void rationalnumber_init(RATIONALNUMBER_PTR xptr, int sign, long long int num, long long int denom);
double rational_to_double(RATIONALNUMBER x);
void rationalnumber_print(const RATIONALNUMBER_PTR x);
void rationalnumber_assign_const(RATIONALNUMBER_PTR dest, const char* str);
void rationalnumber_add(RATIONALNUMBER_PTR dest, RATIONALNUMBER a, RATIONALNUMBER b);
void rationalnumber_sub(RATIONALNUMBER_PTR dest, RATIONALNUMBER a, RATIONALNUMBER b);
void rationalnumber_mult(RATIONALNUMBER_PTR dest, RATIONALNUMBER a, RATIONALNUMBER b);
void rationalnumber_div(RATIONALNUMBER_PTR dest, RATIONALNUMBER a, RATIONALNUMBER b);
RATIONALNUMBER rationalnumber_fabs(RATIONALNUMBER src);
RATIONALNUMBER rationalnumber_neg(RATIONALNUMBER src);
int rationalnumber_is_zero(const RATIONALNUMBER_PTR xptr);
int rationalnumber_is_negative(const RATIONALNUMBER_PTR xptr);
int rationalnumber_is_positive(const RATIONALNUMBER_PTR xptr);
int rationalnumber_is_equal(const RATIONALNUMBER_PTR a, const RATIONALNUMBER_PTR b);
int rationalnumber_is_not_equal(const RATIONALNUMBER_PTR a, const RATIONALNUMBER_PTR b);
int rationalnumber_is_greater(const RATIONALNUMBER_PTR a, const RATIONALNUMBER_PTR b);
int rationalnumber_is_less(const RATIONALNUMBER_PTR a, const RATIONALNUMBER_PTR b);
int rationalnumber_is_less_or_equal(const RATIONALNUMBER_PTR a, const RATIONALNUMBER_PTR b);
int rationalnumber_is_greater_or_equal(const RATIONALNUMBER_PTR a, const RATIONALNUMBER_PTR b);
void copy_rationalnumber(RATIONALNUMBER_PTR dest, const RATIONALNUMBER a);
int rationalnumber_which_is_larger(RATIONALNUMBER a, RATIONALNUMBER b, RATIONALNUMBER_PTR* smaller, RATIONALNUMBER_PTR* larger);
int which_is_larger(RATIONALNUMBER a, RATIONALNUMBER b, RATIONALNUMBER_PTR smaller, RATIONALNUMBER_PTR larger);

#endif // RATIONAL_H
