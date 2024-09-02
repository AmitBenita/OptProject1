/*+  simplex_main.c - Partial pivoting */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "simplex.h"
#include "debug.h"

// Global Variables

#define N 128
#define M 64

RATIONALNUMBER  A[N][N];
RATIONALNUMBER B[N][N];
RATIONALNUMBER C[N];
RATIONALNUMBER D[N][N];
RATIONALNUMBER c[N];
RATIONALNUMBER b[N];
RATIONALNUMBER b_aux[N];
RATIONALNUMBER cb[N];
RATIONALNUMBER cbBI[N];
RATIONALNUMBER cbBID[M];
RATIONALNUMBER cd[N];
RATIONALNUMBER rd[N];
RATIONALNUMBER BID[N][N];
RATIONALNUMBER W[N][N];
RATIONALNUMBER BI[N][N];
RATIONALNUMBER BIA_aux[N][N];
RATIONALNUMBER A_aux[N][N];
RATIONALNUMBER BIb[N];
RATIONALNUMBER epsilon;
RATIONALNUMBER zero;

int d[N];
int d_aux[N];
int basis[N];
int n;
int m;
FILE *fp;
 
int Initial_n;
RATIONALNUMBER Initial_W[N][N];
RATIONALNUMBER Initial_cb[N];
RATIONALNUMBER Initial_cd[N];
RATIONALNUMBER Initial_A[N][N];
RATIONALNUMBER Initial_A_aux[N][N];
RATIONALNUMBER Initial_c[N];
RATIONALNUMBER Initial_c_aux[N];
int Initial_basis[N];
RATIONALNUMBER Initial_D[N][N];
int Initial_d[N];
RATIONALNUMBER Initial_B[N][N];
RATIONALNUMBER Initial_BIb[N];
RATIONALNUMBER Initial_C[N][N];
RATIONALNUMBER Initial_b[N];
RATIONALNUMBER Initial_b_aux[N];
RATIONALNUMBER Initial_rd[N];
RATIONALNUMBER Initial_BID[N][N];
RATIONALNUMBER Initial_BI[N][N];
RATIONALNUMBER Initial_cbBI[N];
RATIONALNUMBER Initial_cbBID[N];
RATIONALNUMBER Initial_BIA_aux[N][N];


int main(int argc, char* argv[])
{
    int i, j, p, n_p_m, itemp;
    char str[80];

    // Check if filename argument is provided
    if (argc < 2)
    {
        fprintf(stderr, "Usage: a.exe filename\n");
        return 0;
    }

    // Open file for reading
    fp = fopen(argv[1], "rt");

    // Read first line from file
    fgets(str, 80, fp);
    printf("str = %s\n", str);

    // Read dimensions m and n from file
    fscanf(fp, "%d %d", &m, &n);
    printf("n = %d, m = %d\n", n, m);

    // Calculate Initial_n as n + m
    Initial_n = n + m;

    // Read and print next line from file
    fgets(str, 80, fp);
    printf("str = %s\n", str);

    // Calculate n_p_m as n + m
    n_p_m = n + m;

    // Read the file contents into appropriate variables
    read_file();

    // Print epsilon value
    printf("\nepsilon = ");
    rationalnumber_print(&epsilon);
    printf("\n");

    // Print original system matrix A
    printf(" A: \n");
    print_original_system(A, n, m);

    // Copy original system matrix A to Initial_A
    copy_to_initial_matrix();

    // Print Initial_A matrix
    printf("Initial_A:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n_p_m; j++)
        {
            printf(" ");
            rationalnumber_print(&Initial_A[i][j]);
            printf(" ");
        }
        printf("\n");
    }

    // Initialize Initial_basis with values
    for (i = 0; i < m; i++)
        Initial_basis[i] = i + n;

    // Initialize Initial_c for non-basic variables with 0.0 and basic variables with 1.0
    for (i = 0; i < n; i++)
    {
        copy_rationalnumber(&Initial_c[i], zero);
    }
    for (i = n; i < Initial_n; i++)
        rationalnumber_assign_const(&Initial_c[i], "1.0");

    // Copy b to Initial_b and Initial_b_aux
    for (i = 0; i < m; i++)
    {
        copy_rationalnumber(&Initial_b[i], b[i]);
        copy_rationalnumber(&Initial_b_aux[i], b[i]);
    }

    // Print Initial_basis
    printf("\nInitial_basis:\n");
    for (i = 0; i < m; i++)
        printf(" %d  ", Initial_basis[i]);
    printf("\n");

    // Print Initial_c
    printf("\nInitial_c:\n");
    for (i = 0; i < Initial_n; i++)
        rationalnumber_print(&Initial_c[i]);
    printf("\n");

    // Print Initial_b
    printf("\nInitial_b:\n");
    for (i = 0; i < m; i++)
        rationalnumber_print(&Initial_b[i]);
    printf("\n");

    // Perform initial simplex algorithm to find basic feasible solution
    Initial_simplex_algorithm();

    // Copy Initial_basis to basis and check for infeasibility
    for (i = 0; i < m; i++)
    {
        itemp = Initial_basis[i];
        basis[i] = itemp;
        if (itemp >= n)
        {
            // Print message and exit if no feasible solution exists
            print_no_solution();
            exit(0);
        }
    }

    // Print initial feasible solution
    print_initial_solution();

    // Perform main simplex algorithm to optimize the solution
    simplex_algorithm();

    // Sort basis and BIb for final solution
    bublesort_d(basis, BIb, m);

    // Print final optimized solution
    print_solution();

    // Return 0 to indicate successful execution
    return 0;
}
