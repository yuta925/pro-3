#include <stdio.h>
#include <math.h>w
#include "qeq2.h"

void qeq(double a, double b, double c)
{
    double D = b * b - 4 * a * c;
    double x1 = (-b - sqrt(D)) / (2 * a);
    double x2 = (-b + sqrt(D)) / (2 * a);
    if (D > 0)
    {
        if (x1 < x2)
            printf("%0.5f %0.5f\n", x1, x2);
        else
            printf("%0.5f %0.5f\n", x2, x1);
    }
    else if (D == 0)
        printf("%0.5f\n", x1);
    else
        printf("\n");
}