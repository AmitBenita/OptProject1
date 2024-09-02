//+ stage2_swap_coloms.c

#include "simplex.h"

void stage2_swap_colums(int i, int j)
{
    int k;
    RATIONALNUMBER temp;

    // Iterate over each row k in the matrix A_aux
    for (k = 0; k < m; k++)
    {
        // Copy element A_aux[k][i] to temporary variable temp
        copy_rationalnumber(&temp, A_aux[k][i]);

        // Copy element A[k][j] to A_aux[k][i]
        copy_rationalnumber(&A_aux[k][i], A[k][j]);

        // Copy temporary variable temp to A_aux[k][j]
        copy_rationalnumber(&A_aux[k][j], temp);
    } // for
} // stage2_swap_colums
