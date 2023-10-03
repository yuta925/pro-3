#include <stdio.h>
#include <assert.h>
#define k_MAX 10
#define n_MAX 16

int match(int *a, int *b, int k)
{
    int count = 0;
    for (int i = 0; i < n_MAX; i++)
    {
        for (int j = 0; j < k - 1; j++)
        {
            if ((b[i + j] == a[j]) && (b[i + j + 1] == a[j + 1]))
                count++;
            else
                count *= 0;
            if (count == k - 1)
                break;
        }
        if (count == k - 1)
            break;
    }
    if (count == 0)
        return 0;
    else
        return 1;
}

int main(void)
{
    int k;    // 入力する整数
    int m;    // 入力する整数
    int n;    // 入力する整数
    int i, j; // カウンタ変数
    int result;
    int a_i;
    int a[k_MAX];
    int b[n_MAX];

    for (;;)
    {
        // 整数kの入力
        fprintf(stderr, "整数kを入力して下さい:");
        if ((scanf("%d", &k)) == EOF)
            break;
        assert(0 <= k && k <= k_MAX);

        // 配列aの入力
        for (i = 0; i < k; i++)
        {
            if (scanf("%d", &a_i) == EOF)
                break;
            a[i] = a_i;
        }

        // 整数nの入力
        fprintf(stderr, "整数nを入力して下さい:");
        if (scanf("%d", &n) == EOF)
            break;
        assert(k <= n && n <= n_MAX);

        // 整数mの入力
        fprintf(stderr, "整数mを入力して下さい:");
        if (scanf("%d", &m) == EOF)
            break;
        assert(1 <= m && m <= 16);

        for (i = 0; i < m; i++)
        {
            // 配列bの入力
            for (j = 0; j < n; j++)
                scanf("%d", &b[j]);

            // match関数の実行
            result = match(a, b, k);
            if (result == 0)
                printf("0\n");
            else if (result == 1)
                printf("1\n");
        }
    }
}
