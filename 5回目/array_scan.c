#include <stdio.h>
#include <stdlib.h>

int *new_array_scan(int *pn)
{
    int n;
    int *a = NULL;
    int i;

    fprintf(stderr, "整数nの入力:");
    scanf("%d", &n);
    // printf("%d", n);

    a = (int *)malloc(sizeof(int) * *pn);

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    *pn = n;

    return &a[0];
}
