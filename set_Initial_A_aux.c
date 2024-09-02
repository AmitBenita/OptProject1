//+ set_Initial_A_aux.c

#include "simplex.h"

void set_Initial_A_aux()
{
    int i, j, k;

    // Loop through each column of Initial_A_aux
    for (i = 0; i < Initial_n; i++)
    {
        k = Initial_d[i]; // Get the corresponding index from Initial_d
        printf("%d", k); // Optional: Print the index k for debugging purposes

        // Copy each row of Initial_A corresponding to index k into Initial_A_aux
        for (j = 0; j < m; j++)
        {
            copy_rationalnumber(&Initial_A_aux[j][i], Initial_A[j][k]);
        }
    }
}
