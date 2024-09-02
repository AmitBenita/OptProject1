//+ matrix_mult.c

#include "simplex.h"

 //Function to perform matrix multiplication C = A * B.
 //param C The resulting matrix from the multiplication.
 //param A The first matrix to be multiplied.
 //param B The second matrix to be multiplied.
 //param n The number of rows in matrix A and C.
 //param m The number of columns in matrix A (and rows in matrix B).
 //param p The number of columns in matrix B and C.

void matrix_mult(RATIONALNUMBER C[][N], RATIONALNUMBER A[][N], RATIONALNUMBER B[][N], int n, int m, int p) {
    int i, j, k;
    RATIONALNUMBER sum, temp;

    // Perform matrix multiplication C = A * B
    for (i = 0; i < n; i++) {
        for (j = 0; j < p; j++) {
            copy_rationalnumber(&sum, zero); // Initialize sum to zero

            // Compute each element of C[i][j]
            for (k = 0; k < m; k++) {
                // Multiply corresponding elements from A and B, and add to sum
                rationalnumber_mult(&temp, A[i][k], B[k][j]);
                rationalnumber_add(&sum, sum, temp);
            }

            // Assign the computed sum to C[i][j]
            copy_rationalnumber(&C[i][j], sum);
        }
    }
}

  
