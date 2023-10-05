#define N 8

void matrix_print(int n, double A[N][N]);
void matrix_scan(int n, double A[N][N]);
void matrix_sum(int n, double A[N][N], double B[N][N], double Y[N][N]);
void matrix_trans2(int n, double A[N][N], double Y[N][N]);
void matrix_trans1(int n, double A[N][N]);
void vector_print(int n, double x[N]);
void vector_scan(int n, double x[N]);
void matrix_vector_prod(int n, double A[N][N], double x[N], double y[N]);

/* オプション課題用 */
void matrix_vector_print(int n, double A[N][N], double b[N]);
void matrix_copy(int n, double From[N][N], double To[N][N]);
void vector_copy(int n, double from[N], double to[N]);
void gauss_jordan(int n, double A[N][N], double b[N]);