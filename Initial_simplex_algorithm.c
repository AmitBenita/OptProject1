//+ Initial_simplex_algorithm.c

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "simplex.h"

 //Function to implement the initial phase of the simplex algorithm.
 //The function iterates to find the optimal solution by updating the basis and
 //non-basis variables until the optimal condition is met.
 
void Initial_simplex_algorithm() {
    int i, j, optimal_flag, enter_id, exiting_id;
    RATIONALNUMBER min_value;
    int count = 0;

    optimal_flag = 0;

    printf(" m = %d, Initial_n = %d\n", m, Initial_n);

    printf("\nInitial_basis:\n");
    for (i = 0; i < m; i++)
        printf(" %d ", Initial_basis[i]);
    printf("\n");

    printf("Initial_A:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < Initial_n; j++) {
            rationalnumber_print(&Initial_A[i][j]);
        }
        printf("\n");
    }

    while (optimal_flag == 0) {
        bublesort(Initial_basis, m);

        printf("\nInitial_basis:\n");
        for (i = 0; i < m; i++)
            printf(" %d ", Initial_basis[i]);
        printf("\n");

        Initial_set_d();

        printf("\nInitial_d:\n");
        for (i = 0; i < Initial_n; i++)
            printf(" %d ", Initial_d[i]);
        printf("\n");

        set_Initial_A_aux();

        printf("\nInitial_A_aux (B, D):\n");
        for (i = 0; i < m; i++) {
            for (j = 0; j < Initial_n; j++) {
                rationalnumber_print(&Initial_A_aux[i][j]);
            }
            printf("\n");
        }

        copy_submatrix(Initial_B, Initial_A_aux, 0, m, 0, m);

        printf("\nInitial_B:\n");
        for (i = 0; i < m; i++) {
            for (j = 0; j < m; j++) {
                rationalnumber_print(&Initial_B[i][j]);
            }
            printf("\n");
        }

        inv_gaussian(Initial_BI, Initial_B, m); // BI = B-1  

        erase_epsilons_matrix(Initial_BI, m, m);

        printf("\nInitial_BI:\n");
        for (i = 0; i < m; i++) {
            for (j = 0; j < m; j++) {
                rationalnumber_print(&Initial_BI[i][j]);
            }
            printf("\n");
        }

        matrix_mult(Initial_BIA_aux, Initial_BI, Initial_A_aux, m, m, Initial_n);

        erase_epsilons_matrix(Initial_BIA_aux, m, Initial_n);

        printf("\nInitial_BIA_aux (I, B-1*D):\n");
        for (i = 0; i < m; i++) {
            for (j = 0; j < Initial_n; j++) {
                rationalnumber_print(&Initial_BIA_aux[i][j]);
            }
            printf("\n");
        }

        printf("\nInitial_A_aux (B,D):\n");
        for (i = 0; i < m; i++) {
            for (j = 0; j < Initial_n; j++) {
                rationalnumber_print(&Initial_A_aux[i][j]);
            }
            printf("\n");
        }

        printf("Initial_b:\n");
        for (i = 0; i < m; i++) {
            rationalnumber_print(&Initial_b[i]);
        }

        matrix_vector_mult(Initial_BIb, Initial_BI, Initial_b, m, m);
        erase_epsilons_vector(Initial_BIb, m);

        printf("\nInitial_BIb:\n");
        for (i = 0; i < m; i++) {
            rationalnumber_print(&Initial_BIb[i]);
        }
        printf("\n");

        copy_submatrix(Initial_D, Initial_A_aux, 0, m, m, Initial_n - m);

        printf("Initial_D:\n");
        for (i = 0; i < m; i++) {
            for (j = 0; j < Initial_n - m; j++) {
                rationalnumber_print(&Initial_D[i][j]);
            }
            printf("\n");
        }

        compute_Initial_cb_Initial_cd();

        vector_matrix_mult(Initial_cbBI, Initial_cb, Initial_BI, m, m);
        erase_epsilons_vector(Initial_cbBI, m);

        printf("\nInitial_cbBI:\n");
        for (i = 0; i < m; i++) {
            rationalnumber_print(&Initial_cbBI[i]);
        }
        printf("\n");

        vector_matrix_mult(Initial_cbBID, Initial_cbBI, Initial_D, m, Initial_n - m);
        erase_epsilons_vector(Initial_cbBID, Initial_n - m);

        printf("\nInitial_cbBID:\n");
        for (i = 0; i < Initial_n - m; i++) {
            rationalnumber_print(&Initial_cbBID[i]);
        }
        printf("\n");

        vector_subtract(Initial_rd, Initial_cd, Initial_cbBID, Initial_n - m);
        erase_epsilons_vector(Initial_rd, Initial_n - m);

        printf("\nInitial_rd( cd - cbBID ):\n");
        for (i = 0; i < Initial_n - m; i++) {
            rationalnumber_print(&Initial_rd[i]);
        }
        printf("\n\n");

        min_value = find_min_value(Initial_rd, Initial_n - m);

        if (rationalnumber_is_greater_or_equal(&min_value, &zero)) {
            optimal_flag = 1;
        }
        else {
            enter_id = find_Initial_most_negative();
            exiting_id = find_Initial_exiting_id(Initial_BIA_aux, Initial_BIb, enter_id, Initial_n, m);

            printf("\nenter_id  = %d,  exiting_id = %d, Initial_d[exiting_id] = %d\n", enter_id, exiting_id, Initial_d[exiting_id]);

            Initial_basis[exiting_id] = enter_id;

            printf("\nInitial_basis:\n");
            for (i = 0; i < m; i++) {
                printf(" %d ", Initial_basis[i]);
            }
            printf("\n");
        }
    }
}