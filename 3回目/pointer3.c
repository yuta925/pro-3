#include <stdio.h>

int main(void)
{
    int a = 1234;
    int b = 6666;
    double x = 3.1415;
    double y = 2.7182;

    int *p;
    double *q;

    printf("aの番地 = %p\n", &a);
    printf("bの番地 = %p\n", &b);
    printf("xの番地 = %p\n", &x);
    printf("yの番地 = %p\n", &y);

    p = &b;
    *p += 4;

    q = &x;
    *q *= 2;

    /* 入力した番地の内容を表示 */
    for (;;)
    {
        printf("番地を入力 : ");
        scanf("%p", &q);
        if (q == 0)
            break;
        printf("%p 番地の内容は %0.4f\n", q, *q);
    }

    return 0;
}