#include <stdio.h>
#include <math.h>

void qeq(double, double, double);

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