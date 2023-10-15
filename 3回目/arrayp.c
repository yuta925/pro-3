#include <stdio.h>

int main(void)
{
    int x[] = {0, 10, 20, 30, 40}; /* x[0]=0, x[1]=10, x[2]=20, x[3]=30, x[4]=40 と初期化される */

    int i;

    // 1.sizeof 演算子を用いて配列 x[ ] の要素数を求めて k に代入し, それを出力せよ
    int k;
    k = sizeof(x) / sizeof(x[0]);
    printf("%d\n", k);

    // 2.x[0], x[1], …, x[k-1] のアドレスを出力せよ (printf の書式指定には %p を用いよ)
    for (i = 0; i < k; i++)
        printf("x[%d]のアドレス:%p\n", i, &x[i]);

    // 3.x の値 (アドレス) を表示せよ
    printf("xのアドレス:%p\n", &x);

    // 4.x+0, x+1, …, x+k-1 の値 (アドレス) を表示せよ
    for (i = 0; i < k; i++)
        printf("x+%dのアドレス:%p\n", i, x + i);

    // 5.アドレス x+0, x+1, …, x+k-1 に格納されているデータの値を表示せよ
    for (i = 0; i < k; i++)
        printf("x+%dの値:%d\n", i, *(x + i));

    // 6.nt 型を指すポインタ変数 p を宣言し, p に x[2] のアドレスを代入せよ. このとき，p+2 の値 (アドレス) と p[2] の値を表示せよ
    int *p;
    p = &x[2];
    printf("p+2の値(アドレス):%p \n", p + 2);
    printf("p+2の値:%d \n", p[2]);
}