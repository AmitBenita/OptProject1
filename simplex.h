//+ simplex.h

#include <stdio.h>
#include "rational.h"
#include "debug.h"

// Global Variables

#define N 128
#define M 64

extern RATIONALNUMBER  A[N][N];
extern RATIONALNUMBER B[N][N];
extern RATIONALNUMBER C[N];
extern RATIONALNUMBER D[N][N];
extern RATIONALNUMBER c[N];
extern RATIONALNUMBER b[N];
extern RATIONALNUMBER b_aux[N];
extern RATIONALNUMBER cb[N];
extern RATIONALNUMBER cbBI[N];
extern RATIONALNUMBER cbBID[M];
extern RATIONALNUMBER cd[N];
extern RATIONALNUMBER rd[N];
extern RATIONALNUMBER BID[N][N];
extern RATIONALNUMBER W[N][N];
extern RATIONALNUMBER BI[N][N];
extern RATIONALNUMBER BIA_aux[N][N];
extern RATIONALNUMBER A_aux[N][N];
extern RATIONALNUMBER BIb[N];
extern RATIONALNUMBER epsilon;
  
extern  int d[N];
extern  int d_aux[N];
extern  int basis[N];
extern  int n;
extern  int m;
extern  FILE *fp;

extern  int Initial_n;
extern  RATIONALNUMBER Initial_W[N][N];
extern  RATIONALNUMBER Initial_cb[N];
extern  RATIONALNUMBER Initial_cd[N];
extern  RATIONALNUMBER Initial_A[N][N];
extern  RATIONALNUMBER Initial_A_aux[N][N];
extern  RATIONALNUMBER Initial_c[N];
extern  RATIONALNUMBER Initial_c_aux[N];
extern  int Initial_basis[N];
extern  RATIONALNUMBER Initial_D[N][N];
extern  int Initial_d[N];
extern  RATIONALNUMBER Initial_B[N][N];
extern  RATIONALNUMBER Initial_BIb[N];

extern  RATIONALNUMBER Initial_C[N][N];
extern  RATIONALNUMBER Initial_b[N];
extern  RATIONALNUMBER Initial_b_aux[N];
extern  RATIONALNUMBER Initial_rd[N];
extern  RATIONALNUMBER Initial_BID[N][N];
extern  RATIONALNUMBER Initial_BI[N][N];
extern  RATIONALNUMBER Initial_cbBI[N];
extern  RATIONALNUMBER Initial_cbBID[N];
extern  RATIONALNUMBER Initial_BIA_aux[N][N];

// Global functions

extern void copy_matrix(RATIONALNUMBER Dest[][N], RATIONALNUMBER Source[][N], int n, int m);

extern void copy_vector(RATIONALNUMBER Dest[], RATIONALNUMBER Source[], int n);

extern void bublesort(int array[],  int n);

extern void print_result();

extern void Initial_simplex_algorithm();

extern void simplex_algorithm();

extern int find_exiting_id(RATIONALNUMBER y[][N], RATIONALNUMBER x[], int enter_id,int n, int m, RATIONALNUMBER_PTR max_new_value);

extern int find_most_negative();

extern int find_Initial_most_negative();

extern void inv_gaussian(RATIONALNUMBER B[][N], RATIONALNUMBER A[][N],  int n);

extern  void matrix_mult(RATIONALNUMBER C[][N], RATIONALNUMBER A[][N], RATIONALNUMBER B[][N], int n, int m, int p);

extern void matrix_vector_mult(RATIONALNUMBER c[], RATIONALNUMBER A[][N], RATIONALNUMBER b[], int n, int m); 

extern void vector_matrix_mult(RATIONALNUMBER c[], RATIONALNUMBER b[], RATIONALNUMBER A[][N], int n, int m);

extern void print_no_solution();

extern void print_original_system();

extern void print_result();

extern void read_file();

extern void swap_colums(RATIONALNUMBER A[][N], int i, int j, int m, int n);

extern void swap_rows(RATIONALNUMBER W[][N], int n, int m1, int m2);

extern void vector_subtract(RATIONALNUMBER result_v[], RATIONALNUMBER v1[], RATIONALNUMBER v2[],  int n);

extern void copy_submatrix(RATIONALNUMBER Dest[][N], RATIONALNUMBER Source[][N],  int istart,int depth, int jstart, int length);

extern void copy_initial_matrix();

extern RATIONALNUMBER find_min_value(RATIONALNUMBER rd[], int n);

extern void compute_cb_cd();

extern void compute_Initial_cb_Initial_cd();
 
extern void print_initial_solution(); 

extern void print_solution();

extern void Initial_swap_colums(int i, int j);

extern void stage2_swap_colums(int i, int j);

extern void Initial_set_d();

extern void set_d();

extern void set_Initial_A_aux();

extern void set_A_aux();

extern void bublesort_d(int array[], RATIONALNUMBER darr[],  int n);

extern void erase_epsilons_matrix(RATIONALNUMBER darray[][N], int m, int n);

extern void erase_epsilons_vector(RATIONALNUMBER darray[], int n);

extern int find_Initial_exiting_id(RATIONALNUMBER y[][N], RATIONALNUMBER x[], int enter_id, int n, int m);

extern void copy_to_initial_matrix();

extern void find_all_negative_rds(int neg_ids[], int *n);
