#include <stdio.h>

void triple(int *p, int *q)
/* 2数の番地を受け取り, その番地の内容を3倍する */
{
    *p = 3 * *p;
    *q = 3 * *q;
}

int main(void)
{
    int x = 1, y = 2;

    triple(&x, &y); /* 変数 x, y ではなく, その番地 (ポインタ) を渡す */

    printf("x = %d, y = %d\n", x, y);

    return 0;
}