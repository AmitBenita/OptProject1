//+ swap_colums.c

#include "simplex.h"

void swap_colums(RATIONALNUMBER A[][N], int i, int j, int m, int n)
{
    int k;
    RATIONALNUMBER temp;

    // Iterate over each row k in the matrix A
    for (k = 0; k < m; k++)
    {
        // Copy element A[k][i] to temporary variable temp
        copy_rationalnumber(&temp, A[k][i]);

        // Copy element A[k][j] to A[k][i]
        copy_rationalnumber(&A[k][i], A[k][j]);

        // Copy temporary variable temp to A[k][j]
        copy_rationalnumber(&A[k][j], temp);
    } // for
} // swap_colums

