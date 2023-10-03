#include <stdio.h>
#include <math.h>
#include "ave6.h"

void ave(double a, double b, double *p_a, double *p_m)
{
    *p_a = (a + b) / 2;
    *p_m = sqrt(a * b);
}