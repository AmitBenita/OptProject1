//+ set_A_aux.c

#include "simplex.h"

void set_A_aux()
{
    int i, j, k;

    for (i = 0; i < n; i++)
    {
        k = d[i];
        for (j = 0; j < m; j++)
        {
            copy_rationalnumber(&A_aux[j][i], A[j][k]);
        }
    }
}

