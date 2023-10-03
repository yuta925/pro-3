#include <stdio.h>

int main(void)
{
    int a = 1234;
    int b = 6666;
    int c = 9876;

    printf("a の番地は %p\n", &a);
    printf("b の番地は %p\n", &b);
    printf("c の番地は %p\n", &c);

    return 0;
}