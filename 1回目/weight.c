#include <stdio.h>
#include <assert.h>
#define n_MAX 10

int main(void)
{
    int i;   // カウンタ変数
    int n;   // 入力する値
    int num; // 入力する値
    double weight[n_MAX + 1];
    double w, total = 0;

    for (;;)
    {
        // 整数nの入力
        fprintf(stderr, "整数nを入力: ");
        if (scanf("%d", &n) == EOF)
            break;
        assert(0 <= n && n <= n_MAX);

        // weightの要素の入力
        for (i = 0; i < n; i++)
        {
            if (scanf("%lf", &w) == EOF)
                break;
            weight[i] = w;
        }

        //  品物の番号 (0〜n-1) の系列の入力
        for (;;)
        {
            if (scanf("%d", &num) == EOF)
                break;
            total += weight[num];
        }
        printf("%0.1f", total);
    }
}