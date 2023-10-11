#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dice3sub.h"

void dice_throw(int d[], int n)
{
    int i, r;
    for (i = 0; i < n; i++)
    {
        r = rand() % 6 + 1;
        assert(r >= 1 && r <= 6);
        d[i] = r;
    }
}
void dice3_distr(int n, int d1[], int d2[], int d3[], int c[])
{
    int i;
    int s = 0;

    for (i = 0; i < D3_MAX + 1; i++)
        c[i] = 0;

    for (i = 0; i < n; i++)
    {
        s = d1[i] + d2[i] + d3[i];
        c[s]++;
    }
}