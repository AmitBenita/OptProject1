//+ vector_subtract.c 

#include "simplex.h"

void vector_subtract(RATIONALNUMBER result_v[], RATIONALNUMBER v1[], RATIONALNUMBER v2[], int n)
{
    int i;
    RATIONALNUMBER temp;

    // Loop through each element of the vectors v1 and v2
    for (i = 0; i < n; i++)
    {
        // Initialize temp to zero
        copy_rationalnumber(&temp, zero);

        // Calculate v1[i] - v2[i]
        rationalnumber_sub(&temp, v1[i], v2[i]);

        // Store the result in result_v[i]
        copy_rationalnumber(&result_v[i], temp);
    }
} // vector_subtract
