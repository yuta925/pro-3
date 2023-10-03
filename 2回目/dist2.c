#include <stdio.h>
#include <math.h>

#define REPEAT 3

double dist(double, double, double, double);

int main(void)
{

    double x1, x2, y1, y2, length;

    for (;;)
    {
        fprintf(stderr, "4つの実数 x1, y1, x2, y2 を入力して下さい: ");
        if (scanf("%lf", &x1) == EOF)
            break;
        if (scanf("%lf", &y1) == EOF)
            break;
        if (scanf("%lf", &x2) == EOF)
            break;
        if (scanf("%lf", &y2) == EOF)
            break;

        length = dist(x1, y1, x2, y2);
        printf("%0.4f\n", length);
    }

    return 0;
}

double dist(double x1, double y1, double x2, double y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}