// 課題(1 - 4)
// 標準入力から 4 つの実数 x1, y1, x2, y2 を入力し, 2 点(x1, y1) と(x2, y2) の距離を
// 標準出力に出力するプログラム dist.c を作成せよ.この動作を 3 回繰り返し,
// 計算結果は小数点以下4桁まで出力するようにせよ.

#include <stdio.h>
#include <math.h>

#define REPEAT 3

int main(void)
{
    int i;
    double x1, x2, y1, y2, length;

    for (i = 0; i < REPEAT; i++)
    {
        fprintf(stderr, "4つの実数 x1, y1, x2, y2 を入力して下さい: ");
        scanf("%lf", &x1);
        scanf("%lf", &y1);
        scanf("%lf", &x2);
        scanf("%lf", &y2);
        length = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        printf("%0.4f\n", length);
    }

    return 0;
}