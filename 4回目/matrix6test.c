#include <stdio.h>
#include "matrix.h"

int main(void)
{
    int n;
    double x[N];
    int i;

    fprintf(stderr, "n = ");
    scanf("%d", &n);
    fprintf(stderr, "x\n");
    vector_scan(n, x);

    for (i = 0; i < n; i++)
    {
        x[i] *= 2.0;
    }

    printf("x\n");
    vector_print(n, x);

    return 0;
}