#include <stdio.h>
#include <stdlib.h>

int *new_array_scan(int *pn)
{
    int n;
    int *a = NULL;
    int i;

    // 1.標準入力からまず整数nを読み込む
    fprintf(stderr, "n:");
    scanf("%d", &n);

    // 2.サイズnのint型配列を割り当てる
    a = (int *)malloc(sizeof(int) * n);

    // 3.n個の整数を標準入力からその配列に読み込む
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // 4.*pnにnをセットする
    *pn = n;

    // 5.その配列の先頭要素へのポインタを返す
    return a;
}
