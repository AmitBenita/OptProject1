// simplex_algorithm.c

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "simplex.h"

void simplex_algorithm()
{
    int i, j, k, optimal_flag, enter_id, exiting_id;
    RATIONALNUMBER min_value;
    int count = 0;

    optimal_flag = 0;

    printf(" m = %d, n = %d\n", m, n);

    printf("\nbasis:\n");
    for (i = 0; i < m; i++)
        printf(" %d ", basis[i]);
    printf("\n");

    printf("A:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            rationalnumber_print(&A[i][j]);
        printf("\n");
    }

    while (optimal_flag == 0)
    {
        bublesort(basis, m);

        printf("\nbasis:\n");
        for (i = 0; i < m; i++)
            printf(" %d ", basis[i]);
        printf("\n");

        set_d();

        printf("\nd:\n");
        for (i = 0; i < n; i++)
            printf(" %d ", d[i]);
        printf("\n");

        set_A_aux();

        printf("\nA_aux (B, D):\n");
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
                rationalnumber_print(&A_aux[i][j]);
            printf("\n");
        }

        copy_submatrix(B, A_aux, 0, m, 0, m);

        printf("\nB:\n");
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < m; j++)
                rationalnumber_print(&B[i][j]);
            printf("\n");
        }

        inv_gaussian(BI, B, m);
        erase_epsilons_matrix(BI, m, m);

        printf("\nBI:\n");
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < m; j++)
                rationalnumber_print(&BI[i][j]);
            printf("\n");
        }

        matrix_mult(BIA_aux, BI, A_aux, m, m, n);
        erase_epsilons_matrix(BIA_aux, m, n);

        printf("\nBIA_aux (I, B-1*D):\n");
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
                rationalnumber_print(&BIA_aux[i][j]);
            printf("\n");
        }

        matrix_vector_mult(BIb, BI, b, m, m);
        erase_epsilons_vector(BIb, m);

        printf("\nBIb:\n");
        for (i = 0; i < m; i++)
            rationalnumber_print(&BIb[i]);
        printf("\n");

        copy_submatrix(D, A_aux, 0, m, m, n - m);

        printf("D:\n");
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n - m; j++)
                rationalnumber_print(&D[i][j]);
            printf("\n");
        }

        compute_cb_cd();

        printf("\ncb:\n");
        for (i = 0; i < m; i++)
            rationalnumber_print(&cb[i]);
        printf("\n");

        printf("\ncd:\n");
        for (i = 0; i < n - m; i++)
            rationalnumber_print(&cd[i]);
        printf("\n");

        vector_matrix_mult(cbBI, cb, BI, m, m);
        erase_epsilons_vector(cbBI, m);

        printf("\ncbBI:\n");
        for (i = 0; i < m; i++)
            rationalnumber_print(&cbBI[i]);
        printf("\n");

        vector_matrix_mult(cbBID, cbBI, D, m, n - m);
        erase_epsilons_vector(cbBID, n - m);

        printf("\ncbBID:\n");
        for (i = 0; i < n - m; i++)
            rationalnumber_print(&cbBID[i]);
        printf("\n");

        vector_subtract(rd, cd, cbBID, n - m);
        erase_epsilons_vector(rd, n - m);

        printf("\nrd( cd - cbBID ):\n");
        printf("\nXXd:");
        for (i = 0; i < n - m; i++)
            printf(" %6d ", d[i + m]);
        printf("\nXXrd:");
        for (i = 0; i < n - m; i++)
            rationalnumber_print(&rd[i]);
        printf("\n\n");

        min_value = find_min_value(rd, n - m);
        if (rationalnumber_is_greater_or_equal(&min_value, &zero))
            optimal_flag = 1;
        else
        {
            int negative_rds[N];
            int index, n_n_rds, best_improvement_id, best_exiting_id, q;
            RATIONALNUMBER best_improvement, temp_improvement;

            find_all_negative_rds(negative_rds, &n_n_rds);

            copy_rationalnumber(&best_improvement, zero);
            best_improvement_id = -1;
            for (index = 0; index < n_n_rds; index++)
            {
                enter_id = negative_rds[index];
                for (k = 0; k < n - m; k++)
                    if (d[m + k] == enter_id)
                        q = k;
                printf("\nXXenter_id = %d, q = %d, rd[q] = ", enter_id, q);
                rationalnumber_print(&rd[q]);
                printf("\n");
                exiting_id = find_exiting_id(BIA_aux, BIb, enter_id, n, m, &temp_improvement);
                printf("\n1:temp_improvement = ");
                rationalnumber_print(&temp_improvement);
                printf(", best_improvement = ");
                rationalnumber_print(&best_improvement);
                printf("\n");

                RATIONALNUMBER tmp;
                rationalnumber_assign_const(&tmp, "-1.0");
                rationalnumber_mult(&temp_improvement, temp_improvement, rd[q]);
                rationalnumber_mult(&temp_improvement, temp_improvement, tmp);

                printf("\n2:temp_improvement = ");
                rationalnumber_print(&temp_improvement);
                printf(", best_improvement = ");
                rationalnumber_print(&best_improvement);
                if (rationalnumber_is_greater_or_equal(&temp_improvement, &best_improvement))
                {
                    copy_rationalnumber(&best_improvement, temp_improvement);
                    best_improvement_id = enter_id;
                    best_exiting_id = exiting_id;
                }
            }

            enter_id = best_improvement_id;
            exiting_id = best_exiting_id;

            printf("pivot: enter_id = %d, exiting_id = %d\n", enter_id, d[exiting_id]);

            basis[exiting_id] = enter_id;
            printf("\nbasis:\n");
            for (i = 0; i < m; i++)
                printf(" %d ", basis[i]);
            printf("\n");
        }
    }
} //simplex_algorithm

         
