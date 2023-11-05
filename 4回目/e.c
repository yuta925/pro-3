#include <stdio.h>
#define N 3

void matrix_vector_prod(int A[N][N], int x[N][N], int y[N][N]);

int main(void)
{
    int A[N][N] = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    int x[N][N] = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    int y[N][N];
    matrix_vector_prod(A, x, y);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d ", y[i][j]);
        printf("\n");
    }
}

void matrix_vector_prod(int A[N][N], int x[N][N], int y[N][N])
{
    int i, j, k;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            for (k = 0; k < N; k++)
                y[i][j] = A[i][k] * x[k][j];
}