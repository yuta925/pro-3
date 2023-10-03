#include <stdio.h>
#include <limits.h>
#include "ave_max.h"

int array_scan(int a[])
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        if (scanf("%d", &a[i]) == EOF)
            break;
    }
    return i;
}

void array_ave_max(int n, int a[], double *ave, int *max)
{
    int i;
    int m = INT_MIN;
    for (i = 0; i < n; i++)
    {
        if (a[i] > m)
            m = a[i];
        *ave += a[i];
    }
    *max = m;
    *ave /= n;
}