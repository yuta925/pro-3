#include <stdio.h>
#include <stdlib.h>

int *new_array_scan(int *pn);

int main(void)
{
    int *a = NULL;
    int i, n;

    a = new_array_scan(&n);

    for (i = 0; i < n; i++)
    {
        printf(" %d", a[i]);
    }
    printf("\n");

    free(a);
    a = NULL;

    return 0;
}