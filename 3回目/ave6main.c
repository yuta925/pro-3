#include <stdio.h>
#include <math.h>
#include "ave6.h"

int main(void)
{
    double a;
    double b;
    double ave_a; /* 相加平均 */
    double ave_m; /* 相乗平均 */

    for (;;)
    {
        fprintf(stderr, "2つの実数 a, b を入力して下さい: ");
        if (scanf("%lf", &a) == EOF)
            break;
        if (scanf("%lf", &b) == EOF)
            break;
        ave(a, b, &ave_a, &ave_m);
        printf("%0.3f %0.3f\n", ave_a, ave_m);
    }

    return 0;
}