//+ find_min_value.c

#include "simplex.h"

 //Function to find the minimum value in an array of RATIONALNUMBER elements.
 //param rd[] The array of RATIONALNUMBER elements.
 //param n The number of elements in the array.
 //return The minimum value found in the array.
 
RATIONALNUMBER find_min_value(RATIONALNUMBER rd[], int n) {
    // Assumptions: d[i] is original index, rd ordered by i=0,.., n-1
    //                                                  d[0] ... d[n-1]

    int most_index, i;
    RATIONALNUMBER temp_value;

    // Initialize most_index to the first element index
    most_index = d[0];

    // Initialize temp_value to the first element of the array
    copy_rationalnumber(&temp_value, rd[0]);

    // Iterate through the array to find the minimum value
    for (i = 0; i < n; i++) {
        if (rationalnumber_is_less(&rd[i], &temp_value)) {
            most_index = d[i];
            copy_rationalnumber(&temp_value, rd[i]);
        }
    }

    // Return the minimum value found in the array
    return temp_value;
} // find_min_value

