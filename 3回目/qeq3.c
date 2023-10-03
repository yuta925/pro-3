#include <stdio.h>
#include <math.h>
#include "qeq3.h"

int qeq(double a, double b, double c, double *x1, double *x2)
{
    double D = b * b - 4 * a * c;
    double s1 = (-b - sqrt(D)) / (2 * a);
    double s2 = (-b + sqrt(D)) / (2 * a);

    if (D > 0)
    {
        if (s1 < s2)
        {
            *x1 = s1;
            *x2 = s2;
        }
        else
        {
            *x1 = s2;
            *x2 = s1;
        }

        return 2;
    }
    else if (D == 0)
    {
        *x1 = s1;
        return 1;
    }

    else
        return 0;
}