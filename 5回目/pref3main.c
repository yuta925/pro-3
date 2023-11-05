#include <stdio.h>
#include <stdlib.h>
#include "pref.h"

#define P_MAX 47

int main(void)
{
    int i, j;
    pref_t *a[P_MAX + 1];

    for (i = 0; i < P_MAX; i++)
        a[i] = 0;

    for (i = 0; i < P_MAX; i++)
    {
        a[i] = pref_new_scan();
        if (a[i] == NULL)
            break;
    }

    for (j = i - 1; j >= 0; j--)
    {
        pref_print(a[j]);
        free(a[j]);
        a[i] = NULL;
    }

    return 0;
}