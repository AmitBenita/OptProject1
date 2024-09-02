//+ print_simplex_params.c

#include <stdio.h>
#include <stdlib.h>

#include "simplex.h"

/**
 * Function to print the parameters used in the simplex algorithm.
 */
void print_simplex_params(RATIONALNUMBER A[][N],RATIONALNUMBER A_aux[][N],RATIONALNUMBER c[],RATIONALNUMBER b[],int n,int m,RATIONALNUMBER B[][N],RATIONALNUMBER BID[][N],RATIONALNUMBER D[][N],int basis[],int d[],RATIONALNUMBER cb[],RATIONALNUMBER cd[]
) {
    int i, j;
    static int count = 0;

    printf(" m = %d, n = %d\n", m, n);

    // Print matrix A
    printf("A:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf(" ");
            rationalnumber_print(&A[i][j]);
            printf(" ");
        }
        printf("\n");
    }

    // Print vector c
    printf("c:\n");
    for (i = 0; i < n; i++) {
        printf(" ");
        rationalnumber_print(&c[i]);
        printf(" ");
    }
    printf("\n");

    // Print vector b
    printf("b:\n");
    for (i = 0; i < m; i++) {
        printf(" ");
        rationalnumber_print(&b[i]);
        printf(" ");
    }
    printf("\n");

    // Print auxiliary matrix A_aux
    printf("A_aux:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf(" ");
            rationalnumber_print(&A_aux[i][j]);
            printf(" ");
        }
        printf("\n");
    }

    // Print matrix B
    printf("B:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) {
            printf(" ");
            rationalnumber_print(&B[i][j]);
            printf(" ");
        }
        printf("\n");
    }

    // Print basis array
    printf("basis:\n");
    for (i = 0; i < m; i++)
        printf(" %d ", basis[i]);
    printf("\n");

    // Increment count and exit if the count reaches 8
    count++;
    if (count >= 8)
        exit(0);

} // print_simplex_params
