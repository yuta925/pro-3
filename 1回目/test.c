#include <stdio.h>

int fib(int n)
{
    if (n == 0 || n == 1)
        return n;
    return fib(n - 2) + fib(n - 1);
}

int main(void)
{
    int n = 11;
    int result;

    result = fib(n);
    printf("%d\n", result);

    return 0;
}