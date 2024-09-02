//+ print_initial_solution.c

#include <stdio.h>
#include "simplex.h"

 //Function to print the initial basis and the basic solution.
 
void print_initial_solution() {
    int i;

    // Print the initial basis indices
    printf("\nInitial basis:\n");
    for (i = 0; i < m; i++)
        printf(" %d ", Initial_basis[i]);
    printf("\n");

    // Print the basic solution corresponding to the initial basis
    printf("\nBasic Solution:\n");
    for (i = 0; i < m; i++) {
        printf(" X%d = ", Initial_basis[i]);
        rationalnumber_print(&Initial_BIb[i]);
    }
    printf("\n");
} // print_initial_solution
