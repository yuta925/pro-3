#include <stdio.h>
#include <math.h>
#include "bisection.h"
#define MAX_REPEAT 10

double f(double x, double a, double b, double c)
{
    return a * x * x + b * x + c;
}

double bisection(double x1, double x2, double a, double b, double c, double eps)
{
    int i = 0;
    double solution = 0.0;
    double xmid;
    double f1 = f(x1, a, b, c);
    double f2 = f(x2, a, b, c);
    double fmid;

    while (1)
    {
        xmid = (x1 + x2) / 2;
        fmid = f(xmid, a, b, c);
        fprintf(stderr, "%d %0.8f %0.8f %0.8f %0.8f %0.8f %0.8f\n", i, x1, x2, xmid, f1, f2, fmid);

        if (fabs(f1) < eps)
            return x1;
        else if (fabs(f2) < eps)
            return x2;
        else if (fabs(x1 - x2) < eps)
            return x1;

        if (f1 * fmid < 0)
        {
            x2 = xmid;
            f2 = fmid;
        }
        else if (f2 * fmid < 0)
        {
            x1 = xmid;
            f1 = fmid;
        }
        i++;
    }
    fprintf(stderr, "%lf\n", solution);

    return solution;
}