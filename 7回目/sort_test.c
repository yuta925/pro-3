#include <stdio.h>
#include <assert.h>
#define MAX_N 64

void sort(int n, double *a);

int array_scan(double *a)
{
    int i;
    int n;
    fprintf(stderr, "n = ");
    if (scanf("%d", &n) == EOF)
    {
        n = 0;
    }
    if (n != 0)
    {
        assert(0 < n && n <= MAX_N);
        for (i = 0; i < n; i++)
        {
            fprintf(stderr, "[%d] : ", i);
            scanf("%lf", &a[i]);
        }
    }
    return n;
}

void array_print(int n, double *a)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf(" %0.1f", a[i]);
    }
    printf("\n");
}

int main(void)
{
    int n;
    double a[MAX_N];

    while (0 < (n = array_scan(a)))
    {
        sort(n, a);
        array_print(n, a);
    }

    return 0;
}