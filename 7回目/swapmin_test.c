#include <stdio.h>
#include <assert.h>
#define MAX_N 64
#define MAX_REPEAT 10

void swapmin(int n, double *a, int k);

int array_scan(double *a)
/* 整数 n を読み込み,
   続いて n 個のデータを a[0]〜a[n-1] に読み込み,
   最後に n を返す */
{
    int i;
    int n;
    fprintf(stderr, "n = ");
    scanf("%d", &n);
    assert(n <= MAX_N);
    for (i = 0; i < n; i++)
    {
        fprintf(stderr, "[%d] : ", i);
        scanf("%lf", &a[i]);
    }
    return n;
}

void array_print(int n, double *a)
/* a[0]〜a[n-1] の値を表示する */
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("[%d] %10.5f\n", i, a[i]);
    }
}

int main(void)
{
    int n;
    int k;
    int i;
    double a[MAX_N];

    n = array_scan(a);
    array_print(n, a);

    /* k を入力し, swapmin(n, a , k) を呼び出す,
       という操作を繰り返す */
    for (i = 0; i < MAX_REPEAT; i++)
    {
        fprintf(stderr, "k = ");
        if (scanf("%d", &k) == EOF)
        {
            break;
        }
        swapmin(n, a, k);
        printf("swapmin(n, a, %d)\n", k);
        array_print(n, a);
    }

    return 0;
}