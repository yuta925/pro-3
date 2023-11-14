#include <stdio.h>
#include "str_sort.h"
#include <string.h>
// 単純選択法
void str_sort(int n, record_t *a)
{
    int k, i, min;
    record_t tmp;
    for (k = 0; k <= n - 2; k++)
    {
        min = k;
        for (i = k + 1; i < n; i++)
            if (a[min].age > a[i].age)
                min = i;
        tmp = a[k];
        a[k] = a[min];
        a[min] = a[k];
    }
}
