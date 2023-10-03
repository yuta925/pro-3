#include <stdio.h>

int main(void)
{
    int a = 1234;
    int b = 6666;
    int c = 9876;

    int *p;

    printf("aの番地 = %p\n", &a);
    printf("bの番地 = %p\n", &b);
    printf("cの番地 = %p\n", &c);

    /* ポインタ変数 p を用いた a の読み書き */
    p = &a;                     /* a の番地を p に格納 */
    printf("a内容 = %d\n", *p); /* *p は p 番地の内容 (つまり a) */
    *p = *p + 1;                /* p 番地の内容 (つまり a) を 1 増やす */
    printf("a内容 = %d\n", *p);

    /* 入力した番地の内容を表示 */
    for (;;)
    {
        printf("番地を入力 : ");
        scanf("%p", &p);
        if (p == 0)
        {
            break;
        }
        printf("%p 番地の内容は %d\n", p, *p);
    }

    return 0;
}