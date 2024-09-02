//+ Initial_swap_colums.c

#include "simplex.h"

 //Function to swap two columns in the matrix Initial_A_aux.
 //param i The index of the first column to swap.
 //param j The index of the second column to swap.
 
void Initial_swap_colums(int i, int j) {
    int k;
    RATIONALNUMBER temp;

    // Iterate through each row to swap the elements in columns i and j
    for (k = 0; k < m; k++) {
        // Save the element in column i to temp
        copy_rationalnumber(&temp, Initial_A_aux[k][i]);
        // Copy the element from column j to column i
        copy_rationalnumber(&Initial_A_aux[k][i], Initial_A_aux[k][j]);
        // Copy the element from temp (original column i) to column j
        copy_rationalnumber(&Initial_A_aux[k][j], temp);
    }
} // Initial_swap_colums

