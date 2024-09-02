//+ find_most_negative.c

#include "simplex.h"

 //Function to find the most negative reduced cost in the initial phase of the simplex algorithm.
 //return The index of the variable with the most negative reduced cost.
 
int find_Initial_most_negative() {
    // Assumptions: d[i] is the original index, rd ordered by i=0,.., n-1
    //                                                  d[0] ... d[n-1]

    int most_index, i;
    RATIONALNUMBER temp_value;

    // Initialize most_index to the first non-basic variable
    most_index = Initial_d[m];
    // Initialize temp_value to the first reduced cost
    copy_rationalnumber(&temp_value, Initial_rd[0]);

    // Iterate through the reduced costs to find the most negative value
    for (i = 0; i < (Initial_n - m); i++) {
        if (rationalnumber_is_less(&Initial_rd[i], &temp_value)) {
            most_index = Initial_d[m + i];
            copy_rationalnumber(&temp_value, Initial_rd[i]);
        }
    }

    // Return the index of the variable with the most negative reduced cost
    return most_index;
} // find_Initial_most_negative

