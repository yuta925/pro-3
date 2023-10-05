#include <stdio.h>
#include "matrix.h"

/* matrix_print のテスト */
int main(void)
{
    int n;
    double A[N][N];
    int i, j;

    n = 3;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            A[i][j] = i + j;
        }
    }

    printf("A\n");
    matrix_print(n, A);
    return 0;
}