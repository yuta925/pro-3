#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "str_sort.h"
#define MAX_N 64

int str_array_scan(record_t a[])
{
    int i;
    int n;
    fprintf(stderr, "n = ");
    scanf("%d", &n);
    assert(n <= MAX_N);
    for (i = 0; i < n; i++)
    {
        fprintf(stderr, "[%d].name : ", i);
        scanf(STRFMT, a[i].name);
        fprintf(stderr, "[%d].age : ", i);
        scanf("%d", &a[i].age);
        fprintf(stderr, "[%d].height : ", i);
        scanf("%lf", &a[i].height);
    }
    return n;
}

void str_array_print(int n, record_t a[])
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%-10s", a[i].name);
        printf("%3d", a[i].age);
        printf("%7.2f", a[i].height);
        printf("\n");
    }
}

int main(void)
{
    int n;
    record_t a[MAX_N];

    n = str_array_scan(a);
    str_sort(n, a);
    str_array_print(n, a);

    return 0;
}
