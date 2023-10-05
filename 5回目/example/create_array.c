#include <stdio.h>
#include <stdlib.h> /* malloc と exit を使うのに必要 */

int *create_iarray_n_d(int n, int d)
{
    int *a = NULL; /* 配列の先頭要素を指すポインタの宣言 */
    int i;

    a = (int *)malloc(sizeof(int) * n); /* 動的割当て; 書き方は覚える */
    if (a == NULL)
    { /* malloc が失敗すると NULL が返るので, エラー処理 */
        fprintf(stderr, "a のmalloc が失敗\n");
        exit(1);
    }

    for (i = 0; i < n; i++)
    {
        a[i] = d;
    } /* 値のセット */

    return a;
}

double *create_darray_n_d(int n, double d)
{
    double *x = NULL;
    int i;

    x = (double *)malloc(sizeof(double) * n);
    if (x == NULL)
    {
        fprintf(stderr, "x の malloc が失敗\n");
        exit(1);
    }

    for (i = 0; i < n; i++)
    {
        x[i] = d;
    } /* 値のセット */

    return x;
}