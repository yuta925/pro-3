#include <stdio.h>
#include "matrix.h"

/* matrix_scan のテスト */
int main(void)
{
    int n;
    double A[N][N];

    fprintf(stderr, "n = ");
    scanf("%d", &n);
    matrix_scan(n, A);
    printf("A\n");
    matrix_print(n, A);
    return 0;
}