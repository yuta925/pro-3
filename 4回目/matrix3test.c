#include <stdio.h>
#include "matrix.h"

int main(void)
{
    int n;
    double A[N][N], B[N][N], Y[N][N];

    fprintf(stderr, "n = ");
    scanf("%d", &n);
    fprintf(stderr, "A\n");
    matrix_scan(n, A);
    fprintf(stderr, "B\n");
    matrix_scan(n, B);

    matrix_sum(n, A, B, Y);

    printf("A\n");
    matrix_print(n, A);
    printf("B\n");
    matrix_print(n, B);
    printf("Y\n");
    matrix_print(n, Y);

    return 0;
}