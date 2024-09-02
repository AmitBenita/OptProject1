//+ matrix_vector_mult.c

#include "simplex.h"

 //Function to perform matrix-vector multiplication c = A * b.
 //param c The resulting vector from the multiplication.
 //param A The matrix to be multiplied (dimensions n x m).
 //param b The vector to be multiplied (dimension m).
 //param n The number of rows in matrix A and elements in vector c.
 //param m The number of columns in matrix A (and elements in vector b).

void matrix_vector_mult(RATIONALNUMBER c[], RATIONALNUMBER A[][N], RATIONALNUMBER b[], int n, int m) {
    int i, k;
    RATIONALNUMBER sum, temp;

    // Perform matrix-vector multiplication c = A * b
    for (i = 0; i < n; i++) {
        copy_rationalnumber(&sum, zero); // Initialize sum to zero

        // Compute each element of c[i]
        for (k = 0; k < m; k++) {
            // Multiply corresponding elements from A[i][k] and b[k], and add to sum
            rationalnumber_mult(&temp, A[i][k], b[k]);
            rationalnumber_add(&sum, sum, temp);
        }

        // Assign the computed sum to c[i]
        copy_rationalnumber(&c[i], sum);
    }
}
