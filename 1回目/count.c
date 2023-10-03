#include <stdio.h>
#include <assert.h>
#define MAX_I 4 /* 入力する整数の最大値 */

int main(void)
{
    int i;
    int c[MAX_I + 1]; /* c[i] は iの出現回数 */

    /* カウンタの初期化 */
    for (i = 0; i <= MAX_I; i++)
    {
        c[i] = 0;
    }

    /* 入力とカウント */
    for (;;)
    {
        fprintf(stderr, "0〜4 の整数を入力: ");
        if (scanf("%d", &i) == EOF)
            break;
        assert(0 <= i && i <= MAX_I); /* i が 0〜4 の範囲かどうかチェック */
        c[i]++;                       /* i の出現回数を1増やす */
    }

    for (i = 0; i <= MAX_I; i++)
        printf("%d %d\n", i, c[i]);

    return 0;
}