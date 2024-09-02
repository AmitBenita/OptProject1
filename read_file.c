//+  read_file.c

#include <stdio.h>
#include "simplex.h"

void read_file()
{
    int i, j;
    char str[80];

    fgets(str, 80, fp);   // Read the "c:" line
    printf("str = %s\n", str);
    for (i = 0; i < n; i++) {
        char s[DIGITSIZE + 1];
        fscanf(fp, "%s", s);
        rationalnumber_assign_const(&c[i], s);
    }
    for (i = 0; i < n; i++) {
        printf("c[%d] = ", i);
        rationalnumber_print(&c[i]);
        printf("\n");
    }

    fgets(str, 80, fp);   // Skip a line
    printf("str = %s\n", str);
    fgets(str, 80, fp);   // Read the "A:" line
    printf("A: str = %s\n", str);

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            char s[DIGITSIZE + 1];
            fscanf(fp, "%s", s);
            rationalnumber_assign_const(&A[i][j], s);
        }
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            rationalnumber_print(&A[i][j]);
        }
        printf("\n");
    }

    fgets(str, 80, fp);   // Skip a line
    printf("str = %s\n", str);

    fgets(str, 80, fp);   // Read the "b:" line
    printf("b: str = %s\n", str);

    for (i = 0; i < m; i++) {
        char s[DIGITSIZE + 1];
        fscanf(fp, "%s", s);
        rationalnumber_assign_const(&b[i], s);
    }

    fgets(str, 80, fp);   // Skip a line
    fgets(str, 80, fp);   // Read the "epsilon:" line
    printf("str = %s\n", str);

    char se[DIGITSIZE + 1];
    fscanf(fp, "%s", se);
    rationalnumber_assign_const(&epsilon, se);

    printf("b:\n");
    for (i = 0; i < m; i++) {
        printf(" ");
        rationalnumber_print(&b[i]);
        printf(" ");
    }
    printf("\n");

    copy_matrix(A_aux, A, n, m);
}
