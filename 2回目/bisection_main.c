#include <stdio.h>
#include <math.h>
#include "bisection.h"
#define MAX_REPEAT 10

int main(void)
{
    int i;
    for (i = 0; i < MAX_REPEAT; i++)
    {
        double a, b, c, x1, x2, eps;
        fprintf(stderr, "a, b, c, x1, x2, eps を入力 : ");
        if (scanf("%lf %lf %lf %lf %lf %lf",
                  &a, &b, &c, &x1, &x2, &eps) == EOF)
        {
            break;
        }
        fprintf(stderr, "\n");
        double x = bisection(x1, x2, a, b, c, eps);
        printf("%0.8f\n", x);
    }
    return 0;
}