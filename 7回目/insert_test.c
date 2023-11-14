#include <stdio.h>
#include <assert.h>
#define MAX_N 64
#define MAX_REPEAT 10

void insert(int n, double *a, int k);

int array_scan(double *a)
{
    int i;
    int n;
    fprintf(stderr, "n = ");
    scanf("%d", &n);
    assert(n <= MAX_N);
    for (i = 0; i < n; i++)
    {
        fprintf(stderr, "[%d] : ", i);
        scanf("%lf", &a[i]);
    }
    return n;
}

void array_print(int n, double *a)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("[%d] %10.5f\n", i, a[i]);
    }
}

int main(void)
{
    int n;
    int k;
    int i;
    double a[MAX_N];

    n = array_scan(a);
    array_print(n, a);

    for (i = 0; i < MAX_REPEAT; i++)
    {
        fprintf(stderr, "k = ");
        if (scanf("%d", &k) == EOF)
        {
            break;
        }
        insert(n, a, k);
        printf("insert(n, a, %d)\n", k);
        array_print(n, a);
    }

    return 0;
}