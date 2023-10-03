#include <stdio.h>
#include <math.h>

double arithmetic_mean(double, double); /* 関数のプロトタイプ宣言 */
double geometric_mean(double, double);  /* 関数のプロトタイプ宣言 */

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
        ave_a = arithmetic_mean(a, b); /* 関数の呼び出し */
        ave_m = geometric_mean(a, b);  /* 関数の呼び出し */
        printf("%0.3f %0.3f\n", ave_a, ave_m);
    }

    return 0;
}

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