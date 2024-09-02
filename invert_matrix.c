//+  invert_matrix.c  

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "simplex.h"

 //Function to compute the inverse of a matrix A using Gaussian elimination.
 //param B The matrix that will store the inverse of A.
 //param A The original matrix to be inverted.
 //param n The dimension of the square matrix A.
 
void inv_gaussian(RATIONALNUMBER B[][N], RATIONALNUMBER A[][N], int n) {
    int i, j, k, p;
    RATIONALNUMBER MaxValue, RelativeValue;
    RATIONALNUMBER temp, tmp, tmp1, tmp2, tmp3;

    // Copy matrix A to W
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            copy_rationalnumber(&W[i][j], A[i][j]);
        }
    }

    // Initialize the right side of the augmented matrix W to zero
    for (i = 0; i < n; i++) {
        for (j = n; j < 2 * n; j++) {
            copy_rationalnumber(&W[i][j], zero);
        }
    }

    // Set the diagonal elements of the right side of W to 1
    for (i = 0; i < n; i++) {
        rationalnumber_assign_const(&W[i][n + i], "1.0");
    }

    printf("\nBefore loop W: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < 2 * n; j++) {
            printf(" ");
            rationalnumber_print(&W[i][j]);
            printf(" ");
        }
        printf("\n");
    }

    // Gaussian elimination process
    for (k = 0; k < n; k++) {
        printf("k = %d\n", k);
        p = k;
        copy_rationalnumber(&MaxValue, rationalnumber_fabs(W[k][k]));

        // Find the pivot row
        for (i = k + 1; i < n; i++) {
            tmp1 = rationalnumber_fabs(W[i][k]);
            if (rationalnumber_is_greater(&tmp1, &MaxValue)) {
                p = i;
                copy_rationalnumber(&MaxValue, rationalnumber_fabs(W[i][k]));
            }
        }
        printf("\np = %d, k = %d\n", p, k);

        // Swap rows if necessary
        if (p != k) {
            swap_rows(W, n, k, p);
        }

        copy_rationalnumber(&RelativeValue, W[k][k]);

        printf("RelativeValue = ");
        rationalnumber_print(&RelativeValue);
        printf("\n");

        rationalnumber_assign_const(&W[k][k], "1.0");

        // Normalize the pivot row
        for (j = k + 1; j < 2 * n; j++) {
            rationalnumber_div(&temp, W[k][j], RelativeValue);
            tmp2 = rationalnumber_fabs(temp);
            if (rationalnumber_is_less(&tmp2, &epsilon)) {
                rationalnumber_assign_const(&W[k][j], "0.0");
            }
            else {
                copy_rationalnumber(&W[k][j], temp);
            }
        }

        // Eliminate other rows
        for (i = 0; i < n; i++) {
            if (i != k) {
                copy_rationalnumber(&RelativeValue, W[i][k]);
                copy_rationalnumber(&W[i][k], zero);

                for (j = k + 1; j < 2 * n; j++) {
                    rationalnumber_mult(&tmp, RelativeValue, W[k][j]);
                    rationalnumber_sub(&temp, W[i][j], tmp);
                    tmp3 = rationalnumber_fabs(temp);
                    if (rationalnumber_is_less(&tmp3, &epsilon)) {
                        rationalnumber_assign_const(&W[i][j], "0.0");
                    }
                    else {
                        copy_rationalnumber(&W[i][j], temp);
                    }
                }
            }
        }

        printf("W: \n");
        for (i = 0; i < n; i++) {
            for (j = 0; j < 2 * n; j++) {
                printf(" ");
                rationalnumber_print(&W[i][j]);
                printf(" ");
            }
            printf("\n");
        }
    }

    // Extract the inverse matrix B from the augmented matrix W
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            copy_rationalnumber(&B[j][i], W[j][i + n]);
        }
    }

    printf("\nBI:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf(" ");
            rationalnumber_print(&B[i][j]);
            printf("   ");
        }
        printf("\n");
    }

    printf("\nW:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < 2 * n; j++) {
            printf(" ");
            rationalnumber_print(&W[i][j]);
            printf("   ");
        }
        printf("\n");
    }
}



