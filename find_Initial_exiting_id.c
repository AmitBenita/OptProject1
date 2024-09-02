//+ find_exiting_id.c

#include <stdio.h>
#include "simplex.h"

 //Function to find the exiting variable in the initial phase of the simplex algorithm.
 //param y Matrix representing B-1D.
 //param x Vector representing B-1b.
 //param enter_id The entering variable's index.
 //param n The total number of variables.
 //param m The number of constraints.
 //return The index of the exiting variable.
 
int find_Initial_exiting_id(RATIONALNUMBER y[][N], RATIONALNUMBER x[], int enter_id, int n, int m) {

    int i, temp_min_index, init_flag, q;
    RATIONALNUMBER temp_min, temp;

    // Find the column index q corresponding to the entering variable
    for (i = 0; i < Initial_n; i++) {
        if (Initial_d[i] == enter_id) {
            q = i;
            break;
        }
    }

    init_flag = 0;

    // Iterate over the constraints to find the minimum ratio
    for (i = 0; i < m; i++) {
        printf("y[%d][%d] = ", i, q);
        rationalnumber_print(&y[i][q]);
        printf("x[%d] = ", i);
        rationalnumber_print(&x[i]);
        printf("init_flag = %d\n", init_flag);

        // Check if y[i][q] is positive
        if (rationalnumber_is_greater(&y[i][q], &zero)) {

            // Compute the ratio x[i] / y[i][q]
            rationalnumber_div(&temp, x[i], y[i][q]);
            printf("i = %d, temp = ", i);
            rationalnumber_print(&temp);
            printf("\n");

            // Initialize temp_min and temp_min_index if this is the first valid ratio
            if (init_flag == 0) {
                copy_rationalnumber(&temp_min, temp);
                temp_min_index = i;
                init_flag = 1;
            }
            else {
                // Update temp_min and temp_min_index if a smaller ratio is found
                if (rationalnumber_is_less(&temp, &temp_min)) {
                    copy_rationalnumber(&temp_min, temp);
                    temp_min_index = i;
                }
            }

            printf("temp_min_index  = %d, temp_min  = ", temp_min_index);
            rationalnumber_print(&temp_min);
            printf("\n");
        }
    }

    // Return the index of the exiting variable
    return temp_min_index;
} // find_Initial_exiting_id
