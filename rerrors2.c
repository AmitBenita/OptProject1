// rerrors2.c

#include <stdio.h>
#include <math.h>
#include "rational.h"

int main()
{
    
    RATIONALNUMBER x, y, z, diff, temp1, temp2, two;

    rationalnumber_assign_const(&two, "2.0");

    printf("\n\nroundoff error:\n\n");
    //  x = 100000.0;
    rationalnumber_assign_const(&x, "100000.0");

    //  y = 737191377;
    rationalnumber_assign_const(&y, "737191377.0");

    //  z = x / y * y;
    rationalnumber_div(&temp1, x, y);
    rationalnumber_mult(&z, temp1, y);

    //  diff = z - x;
    rationalnumber_sub(&diff, z, x);

    //  printf("%lf / %lf *%lf = %lf\n", x, y, y, z);
    rationalnumber_print(&x);
    printf(" / ");
    rationalnumber_print(&y);
    printf(" * ");
    rationalnumber_print(&y);
    printf(" = ");
    rationalnumber_print(&z);
    printf("\n");

    //  printf("diff = %lg\n", diff); 
    printf("diff = ");
    rationalnumber_print(&diff);
    printf("\n");

    printf("\n\ncancellation error\n");
    //  x = y = 10000000000.0; 
    rationalnumber_assign_const(&x, "10000000000.0");
    y = x;
    //  z = 0.00000000007;
    rationalnumber_assign_const(&z, "0.00000000007");
    rationalnumber_sub(&temp1, x, y);
    rationalnumber_add(&temp1, temp1, z);
    rationalnumber_add(&temp2, x, z);
    rationalnumber_sub(&temp2, temp2, y);
    // printf("%lg - %lg + %lg = %lg\n", x, y, z, x - y + z); 
    printf("x - y + z = ");
    rationalnumber_print(&temp1);
    printf("\n");

    //  printf("%lg + %lg - %lg = %lg\n", x, z, y, x + z - y); 
    printf("x + z - y = ");
    rationalnumber_print(&temp2);
    printf("\n");

    return 0;
} // main