#include <stdio.h>
#include "ave_max.h"

int main(void)
{
    int a[MAX];
    int n;
    double ave;
    int max;
    n = array_scan(a);
    array_ave_max(n, a, &ave, &max);
    printf("%0.3f %d\n", ave, max);
    return 0;
}