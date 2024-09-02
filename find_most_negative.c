//+ find_most_negative.c

#include "simplex.h"

 //Function to find the index of the most negative value in an array of RATIONALNUMBER elements.
 //return The index of the most negative value found in the array.
 
int find_most_negative() {
    // Assumptions: d[i] is original index, rd ordered by i=0,.., n-1
    //                                                  d[0] ... d[n-1]

    int most_index, i;
    RATIONALNUMBER temp_value;

    // Initialize most_index to the first element index of the non-basic variables
    most_index = d[m];

    // Initialize temp_value to the first element of the reduced costs array
    copy_rationalnumber(&temp_value, rd[0]);

    // Iterate through the non-basic variables to find the most negative reduced cost
    for (i = 0; i < (n - m); i++) {
        if (rationalnumber_is_less(&rd[i], &temp_value)) {
            most_index = d[m + i];
            copy_rationalnumber(&temp_value, rd[i]);
        }
    }

    // Return the index of the most negative value found in the array
    return most_index;
} // find_most_negative
