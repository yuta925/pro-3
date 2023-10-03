#include <stdio.h>
#include "ave5.h"

int main(void)
{
    int r;
    double a;
    double b;
    double ave_a; /* 相加平均 */
    double ave_m; /* 相乗平均 */

    for (;;)
    {
        fprintf(stderr, "2つの実数 a, b を入力して下さい: ");
        if (scanf("%lf", &a) == EOF)
        {
            break;
        }
        if (scanf("%lf", &b) == EOF)
        {
            break;
        }
        ave_a = arithmetic_mean(a, b);
        ave_m = geometric_mean(a, b);
        printf("%0.3f %0.3f\n", ave_a, ave_m);
    }

    return 0;
}