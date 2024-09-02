//+ set_d.c

#include "simplex.h"

void set_d()
{
    int i, j, pos, flag;

    // Initialize the first part of d with the current basis indices
    for (i = 0; i < m; i++)
        d[i] = basis[i];

    pos = m;

    // Populate the rest of d with indices not in the current basis
    for (i = 0; i < n; i++)
    {
        flag = 1;
        for (j = 0; j < m && flag == 1; j++)
        {
            if (i == basis[j])
                flag = 0;
        }
        if (flag == 1)
            d[pos++] = i;
    }
}
