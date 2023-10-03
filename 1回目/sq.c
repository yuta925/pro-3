#include <stdio.h>

#define N 10

int main(void)
{
    int i;
    for (i = 1; i <= N; i++)
    {
        printf("%d %d\n", i, i * i);
    }

    return 0;
}