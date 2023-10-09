#include <stdio.h>

int main(void)
{
    int a = 2023;
    int b = 9999;
    double x = 3.14;
    double y = 2.71;

    printf("a の番地は %p\n", &a);
    printf("b の番地は %p\n", &b);
    printf("x の番地は %p\n", &x);
    printf("y の番地は %p\n", &y);
}