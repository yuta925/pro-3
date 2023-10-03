// 課題 (1-5)
// 標準入力から科目の成績の素点 (0〜100 までの整数) を入力してその GP (grade point; 下表参照) を
// 小数点以下 1 桁で出力する, という動作をデータがなくなるまで (scanf が EOF を返すまで) 繰り返し,
// 最後に GP の平均値を小数点以下3桁で出力するプログラム gpa.c を作成せよ.

#include <stdio.h>

int main(void)
{
    int i, score, count = 0;
    double GP[8] = {4.0, 3.5, 3.0, 2.5, 2.0, 1.5, 1.0, 0.0};
    double total = 0, average;

    for (;; count++)
    {
        fprintf(stderr, "科目の成績の素点 (0〜100 までの整数）を入力して下さい: ");
        if (scanf("%d", &score) == EOF)
            break;

        if (score >= 90 && score <= 100)
        {
            printf("%0.1f\n", GP[0]);
            total += GP[0];
        }
        else if (score >= 85 && score <= 89)
        {
            printf("%0.1f\n", GP[1]);
            total += GP[1];
        }
        else if (score >= 80 && score <= 84)
        {
            printf("%0.1f\n", GP[2]);
            total += GP[2];
        }
        else if (score >= 75 && score <= 79)
        {
            printf("%0.1f\n", GP[3]);
            total += GP[3];
        }
        else if (score >= 70 && score <= 74)
        {
            printf("%0.1f\n", GP[4]);
            total += GP[4];
        }
        else if (score >= 65 && score <= 69)
        {
            printf("%0.1f\n", GP[5]);
            total += GP[5];
        }
        else if (score >= 60 && score <= 64)
        {
            printf("%0.1f\n", GP[6]);
            total += GP[6];
        }
        else
        {
            printf("%0.1f\n", GP[7]);
            total += GP[7];
        }
    }

    // 平均を求める
    average = total / count;
    printf("%0.3f\n", average);
}