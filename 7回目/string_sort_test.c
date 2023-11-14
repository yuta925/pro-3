#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "string_sort.h"
#define MAX_N 64

int string_array_scan(char (*a)[STRLEN + 1])
{
    int i;
    int n;
    fprintf(stderr, "n = ");
    scanf("%d", &n);
    assert(n <= MAX_N);
    for (i = 0; i < n; i++)
    {
        fprintf(stderr, "[%d] : ", i);
        scanf(STRFMT, a[i]);
    }
    return n;
}

void string_array_print(int n, char (*a)[STRLEN + 1])
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%s\n", a[i]);
    }
}

int main(void)
{
    int n;
    char a[MAX_N][STRLEN + 1];

    n = string_array_scan(a);
    string_sort(n, a);
    string_array_print(n, a);

    return 0;
}