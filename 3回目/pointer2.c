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
    printf("a の値 = %d\n", *((int *)0x7ffffcc2c));
    printf("b の値 = %d\n", *((int *)0x7ffffcc28));
    printf("x の値 = %0.1f\n", *((double *)0x7ffffcc20));
    printf("y の値 = %0.1f\n", *((double *)0x7ffffcc18));

    *((int *)0x7ffffcc2c) = 2;
    *((int *)0x7ffffcc28) = 1;
    *((int *)0x7ffffcc20) = 2.2;
    *((int *)0x7ffffcc18) = 1.1;

    printf("a の値 = %d\n", a);
    printf("b の値 = %d\n", b);
    printf("x の値 = %0.1f\n", x);
    printf("y の値 = %0.1f\n", y);

    return 0;
}