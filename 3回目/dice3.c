#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dice3sub.h"

int main(void)
{
    int d1[N_MAX];     /* 1個目のサイコロの出目の系列 */
    int d2[N_MAX];     /* 2個目のサイコロの出目の系列 */
    int d3[N_MAX];     /* 3個目のサイコロの出目の系列 */
    int n;             /* サイコロを振る回数 */
    int c[D3_MAX + 1]; /* 目の和の出現回数 */
    int i;

    fprintf(stderr, "サイコロを振る回数 n = ");
    scanf("%d", &n);
    assert(0 < n && n <= N_MAX);

    srand(1);
    for (i = D3_MIN; i <= D3_MAX; i++)
    {
        c[i] = rand();
    }

    srand(1);
    dice_throw(d1, n);
    dice_throw(d2, n);
    dice_throw(d3, n);
    dice3_distr(n, d1, d2, d3, c);

    for (i = D3_MIN; i <= D3_MAX; i++)
    {
        printf("%2d: %6d\n", i, c[i]);
    }

    return 0;
}