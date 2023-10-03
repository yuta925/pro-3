#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int irand(int, int);

int main(void)
{
    int a, b, n, i, r;
    int *count;

    printf("3つの整数をa,b,nを入力してください: ");
    scanf("%d %d %d", &a, &b, &n);

    count = (int *)malloc((b - a + 1) * sizeof(int));
    for (i = 0; i < b - a + 1; i++)
        count[i] = 0;

    for (i = 0; i < n; i++)
    {
        r = irand(a, b);
        count[r - a]++;
        printf("%d ", r);
    }

    printf("\n");

    for (i = a; i <= b; i++)
        printf("%d: %d回\n", i, count[i - a]);
}

int irand(int a, int b)
{
    int r = rand() % (b - a + 1) + a;
    return r;
}