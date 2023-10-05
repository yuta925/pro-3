#include <stdio.h>
#include "matrix.h"

int main(void)
{
    int n;
    double A[N][N];

    fprintf(stderr, "n = ");
    scanf("%d", &n);
    fprintf(stderr, "A\n");
    matrix_scan(n, A);

    printf("A\n");
    matrix_print(n, A);

    matrix_trans1(n, A);

    printf("A\n");
    matrix_print(n, A);

    return 0;
}