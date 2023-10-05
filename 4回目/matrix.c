#include <stdio.h>
#include <assert.h>
#include "matrix.h"

/* 行列の出力 */
void matrix_print(int n, double A[N][N])
{
    int i, j;
    assert(n <= N);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf(" %.5f", A[i][j]);
        }
        printf("\n");
    }
}

void matrix_scan(int n, double A[N][N])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            fprintf(stderr, "[%d][%d] ", i, j);
            scanf("%lg", &A[i][j]);
        }
    }
}

void matrix_sum(int n, double A[N][N], double B[N][N], double Y[N][N])
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            Y[i][j] = A[i][j] + B[i][j];
}

void matrix_trans2(int n, double A[N][N], double Y[N][N])
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            Y[i][j] = A[j][i];
}

void matrix_trans1(int n, double A[N][N])
{
    int i, j;
    double tmp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            tmp = A[j][i];
            A[i][j] = tmp;
        }
    }
}

void vector_scan(int n, double x[N])
{
    int i;
    for (i = 0; i < n; i++)
        scanf("%lf", &x[i]);
}

void vector_print(int n, double x[N])
{
    int i;
    for (i = 0; i < n; i++)
        printf("%.5f\n", x[i]);
}

void matrix_vector_prod(int n, double A[N][N], double x[N], double y[N])
{
    int i, j, k;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            y[i] += A[i][j] * x[j];
}
