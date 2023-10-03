#include <stdio.h>
#include <math.h>
#include "ave5.h"

double arithmetic_mean(double x, double y) /* 関数の定義 (本体) */
{
    double a = (x + y) / 2;
    return a;
}

double geometric_mean(double x, double y) /* 関数の定義 (本体) */
{
    double a = sqrt(x * y);
    return a;
}