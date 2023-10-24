#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int *new_array_scan(int *pn);

int main(void)
{
    int *a = NULL;
    int *b = NULL;
    int i, n;
    int max = INT_MIN;
    int min = INT_MAX;

    a = new_array_scan(&n);

    for (i = 0; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
        if (a[i] < min)
            min = a[i];
    }

    b = (int *)malloc(sizeof(int) * (max - min + 1));

    for (i = 0; i < max - min + 1; i++)
        b[i] = 0;

    for (i = 0; i < n; i++)
        b[a[i] - min]++;

    for (i = 0; i < n; i++)
    {
        if (b[i] >= 1)
            printf("%d: %d\n", i + 1, b[i]);
    }
    free(a);
    free(b);
}