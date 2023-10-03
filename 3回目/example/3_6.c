#include <stdio.h>

#define MAX 16 /* 配列の最大サイズ */

void array_scan(int a[], int *pn)
/* 配列の読み込み */
{
    int i;
    for (i = 0; i < MAX; i++)
    { /* 最大サイズを超えて読まない */
        fprintf(stderr, "a[%d] = ", i);
        if (scanf("%d", &a[i]) == EOF)
        {
            break;
        }
    }
    *pn = i;
}

void array_square(int a[], int n)
/* 要素を 2 乗する */
{
    int i;
    for (i = 0; i < n; i++)
    {
        a[i] = a[i] * a[i];
    }
}

void array_print(int a[], int n)
/* 配列の出力 */
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (i != 0)
        {
            printf(",");
        } /* コンマ区切り */
        printf("%d", a[i]);
    }
    printf("\n");
}

int main(void)
{
    int a[MAX];
    int n; /* 配列のサイズ */
    array_scan(a, &n);
    array_square(a, n);
    array_print(a, n);
    return 0;
}