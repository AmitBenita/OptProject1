//+ matrix_vector_mult.c

#include "simplex.h"

void vector_matrix_mult(RATIONALNUMBER c[], RATIONALNUMBER b[], RATIONALNUMBER A[][N], int n, int m)
{
    int i, k;
    RATIONALNUMBER sum, temp;

    // Loop through each column i of the matrix A
    for (i = 0; i < m; i++)
    {
        // Initialize sum to zero
        copy_rationalnumber(&sum, zero);

        // Compute the dot product of column i of A with vector b
        for (k = 0; k < n; k++)
        {
            // Compute A[k][i] * b[k]
            copy_rationalnumber(&temp, zero);
            rationalnumber_mult(&temp, A[k][i], b[k]);

            // Add the result to sum
            rationalnumber_add(&sum, sum, temp);
        }

        // Assign the computed sum to the corresponding element of c
        copy_rationalnumber(&c[i], sum);
    } // for
} // vector_matrix_mult
