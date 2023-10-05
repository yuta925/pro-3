#include <stdio.h>
#include <stdlib.h>

int *create_iarray_n_d(int n, int d);
double *create_darray_n_d(int n, double d);

#define NI 6
#define ND 8

int main(void)
{
    int *a = NULL;
    double *b = NULL;
    int i;

    a = create_iarray_n_d(NI, 23); /* 呼び出し */
    for (i = 0; i < NI; i++)
    { /* 表示してみる */
        printf(" %d", a[i]);
    }
    printf("\n");
    free(a);  /* 解放を忘れないこと */
    a = NULL; /* free した後に NULL を代入する習慣をつける */

    b = create_darray_n_d(ND, 3.14); /* 呼び出し */
    for (i = 0; i < ND; i++)
    { /* 表示してみる */
        printf(" %f", b[i]);
    }
    printf("\n");
    free(b);  /* 解放を忘れないこと */
    b = NULL; /* free した後に NULL を代入する習慣をつける */

    return 0;
}