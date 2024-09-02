//+ print_solution.c

#include <stdio.h>
#include "simplex.h"

void print_solution()
{
    int i;
    RATIONALNUMBER sum, temp;

    // Print the current basis
    printf("\nbasis:\n");
    for (i = 0; i < m; i++)
        printf(" %d ", basis[i]);
    printf("\n");

    // Print the basic solution
    printf("\nBasic Solution:\n");
    for (i = 0; i < m; i++) {
        printf(" X%d = ", basis[i] + 1);
        rationalnumber_print(&BIb[i]);
        printf(" ");
    }
    printf("\n");

    // Print the solution value
    printf("\nSolution value:\n");

    // Initialize sum with the first term
    rationalnumber_mult(&temp, c[basis[0]], BIb[0]);
    copy_rationalnumber(&sum, temp);
    printf(" ");
    rationalnumber_print(&c[basis[0]]);
    printf(" * ");
    rationalnumber_print(&BIb[0]);
    printf(" ");

    // Add the remaining terms
    for (i = 1; i < m; i++) {
        rationalnumber_mult(&temp, c[basis[i]], BIb[i]);
        rationalnumber_add(&sum, sum, temp);
        printf(" + ");
        rationalnumber_print(&c[basis[i]]);
        printf(" * ");
        rationalnumber_print(&BIb[i]);
    }

    // Print the final solution value
    printf(" = ");
    rationalnumber_print(&sum);
    printf("\n");
} // print_solution