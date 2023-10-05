#include <stdio.h>
#include "matrix.h"

int main(void)
{
    int n;
    double A[N][N], Y[N][N];

    fprintf(stderr, "n = ");
    scanf("%d", &n);
    fprintf(stderr, "A\n");
    matrix_scan(n, A);

    matrix_trans2(n, A, Y);

    printf("A\n");
    matrix_print(n, A);
    printf("Y\n");
    matrix_print(n, Y);

    return 0;
}