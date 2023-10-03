#include <stdio.h>

int main(void)
{
    int a = 1234;
    int b = 6666;
    int c = 9876;

    printf("a の番地は %p\n", &a);
    printf("b の番地は %p\n", &b);
    printf("c の番地は %p\n", &c);

    printf("\n");
    printf("a の値 = %d\n", *((int *)0x16f4c6e78)); /* 0x804c番地 (a) の内容を出力 */
    printf("b の値 = %d\n", *((int *)0x16f4c6e74)); /* 0x8048番地 (b) の内容を出力 */
    printf("c の値 = %d\n", *((int *)0x16f4c6e70)); /* 0x8044番地 (c) の内容を出力 */

    *((int *)0x16f4c6e78) = 1111; /* 0x804c番地 (a) に1111を書き込む */
    *((int *)0x16f4c6e74) = 2010; /* 0x8048番地 (b) に2010を書き込む */
    *((int *)0x16f4c6e70) = 5628; /* 0x8044番地 (c) に5628を書き込む */

    printf("\n");
    printf("a の値 = %d\n", a);
    printf("b の値 = %d\n", b);
    printf("c の値 = %d\n", c);

    return 0;
}