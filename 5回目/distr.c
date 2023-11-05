#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int *new_array_scan(int *pn);

int main(void)
{
    int *a = NULL;
    int *b = NULL;
    int i, n;
    int max = INT_MIN;
    int min = INT_MAX;

    // 課題 (5-1) の new_array_scan を使って, 標準入力から数値を読み取った配列を取得する.
    a = new_array_scan(&n);

    // 配列中のデータの最大値 max と最小値 min を求める.
    for (i = 0; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
        if (a[i] < min)
            min = a[i];
    }

    // サイズが max-min+1 の int 型配列を malloc により割り当て, この配列を使ってデータの出現回数を数える
    b = (int *)malloc(sizeof(int) * (max - min + 1));

    // カウント用配列の初期化
    for (i = 0; i < max - min + 1; i++)
        b[i] = 0;

    for (i = 0; i < n; i++)
        b[a[i] - min]++;

    for (i = 0; i < max - min + 1; i++)
    {
        if (b[i] >= 1)
            printf("%d: %d\n", i + min, b[i]);
    }

    free(a);
    a = NULL;
    free(b);
    b = NULL;
}