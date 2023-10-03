#include <stdio.h>

int main(void)
{
    int a = 1;
    int b = 2;
    double x = 1.1;
    double y = 2.2;

    printf("a の番地は %p\n", &a);
    printf("b の番地は %p\n", &b);
    printf("x の番地は %p\n", &x);
    printf("y の番地は %p\n", &y);

    printf("\n");
    printf("a の値 = %d\n", *((int *)0x16db7ae88));
    printf("b の値 = %d\n", *((int *)0x16db7ae88));
    printf("x の値 = %d\n", *((double *)0x16db7ae88));
    printf("y の値 = %d\n", *((double *)0x16db7ae88));

    *((int *)0x16f4c6e78) = 1111;
    *((int *)0x16f4c6e74) = 2010;
    *((int *)0x16f4c6e70) = 5628;

    return 0;
}