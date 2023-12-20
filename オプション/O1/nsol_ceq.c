#include <stdio.h>
#include <math.h>

int calc_solution(double a, double b, double c, double d)
{
    double a1 = 3 * a;
    double b1 = 2 * b;
    double c1 = c;

    double D = b1 * b1 - 4 * a1 * c1;

    double x1 = (-b1 + sqrt(D)) / (2 * a1);
    double x2 = (-b1 - sqrt(D)) / (2 * a1);

    double f1 = a * x1 * x1 * x1 + b * x1 * x1 + c * x1 + d;
    double f2 = a * x2 * x2 * x2 + b * x2 * x2 + c * x2 + d;

    if (f1 < f2)
    {
        double tmp = f1;
        f1 = f2;
        f2 = tmp;
    }

    if (D <= 0)
        return 1;
    else if (D > 0)
    {
        if ((f1 < 0 && f2 > 0) || (f1 > 0 && f2 < 0))
            return 3;
        else if (f1 * f2 == 0 && f1 != f2)
            return 2;
        else if (f1 * f2 > 0)
            return 1;
    }
}

int main(void)
{
    double a, b, c, d;
    printf("三次方程式 ax^3 + bx^2 + cx + d = 0 の係数を入力して下さい\n");
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    int result = calc_solution(a, b, c, d);
    printf("実数解の個数は%d個です\n", result);
}