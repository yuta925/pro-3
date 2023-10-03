#include <stdio.h>
#include <math.h>
#include "qeq2.h"

int main(void)
{
    double a, b, c;
    for (;;)
    {
        fprintf(stderr, "実数a,b,cを入力してください:");
        scanf("%lf", &a);
        scanf("%lf", &b);
        scanf("%lf", &c);
        if (a == 0)
            break;
        qeq(a, b, c);
    }
}