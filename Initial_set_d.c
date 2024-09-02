//+ Initial_set_d.c

#include "simplex.h"

 //Function to initialize the Initial_d array with basis and non-basis indices.
 //The function first sets the first m elements of Initial_d to be the basis indices.
 //It then iterates over all indices from 0 to Initial_n - 1 and adds those not in the basis
 //to the remaining positions in Initial_d.

void Initial_set_d() {
    int i, j, pos, flag;

    // Copy basis indices to the beginning of Initial_d
    for (i = 0; i < m; i++)
        Initial_d[i] = Initial_basis[i];

    pos = m;

    // Iterate over all possible indices
    for (i = 0; i < Initial_n; i++) {
        flag = 1;

        // Check if the index is part of the basis
        for (j = 0; (j < m) && (flag == 1); j++) {
            if (i == Initial_basis[j]) {
                flag = 0;
            }
        }

        // If the index is not part of the basis, add it to Initial_d
        if (flag == 1) {
            Initial_d[pos++] = i;
        }
    }
} // Initial_set_d
