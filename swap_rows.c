//+ swap_rows.c

#include "simplex.h"

void swap_rows(RATIONALNUMBER W[][N], int n, int m1, int m2)
{
    int i;
    RATIONALNUMBER temp;

    // Iterate over each column i in the matrix W
    for (i = 0; i < 2 * n; i++)
    {
        // Copy element W[m1][i] to temporary variable temp
        copy_rationalnumber(&temp, W[m1][i]);

        // Copy element W[m2][i] to W[m1][i]
        copy_rationalnumber(&W[m1][i], W[m2][i]);

        // Copy temporary variable temp to W[m2][i]
        copy_rationalnumber(&W[m2][i], temp);
    } // for
} // swap_rows


