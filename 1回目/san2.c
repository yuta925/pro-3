// 課題 (1-3)
// キーボードから n を入力し (1≤n≤99 とする), 1〜n の整数のうち,
// 3 の倍数か, いずれかの桁が 3 であるものを, 小さい順に出力するプログラム san2.c を作成せよ.
// n=77 を入力したときの出力をテキストファイルに保存し, 下記の期待値を保存したファイル san2-exp.txt と
// 内容が一致することを確認せよ.

#include <stdio.h>

int main(void)
{
    int i, n;

    while (1)
    {
        fprintf(stderr, "nを入力して下さい: ");
        scanf("%d", &n);
        if ((n >= 1) && (n <= 99))
            break;
    }

    for (i = 1; i <= n; i++)
    {
        if ((i % 3 == 0) || (i % 10 == 3) || (i / 10 == 3))
            printf("%d\n", i);
    }
}