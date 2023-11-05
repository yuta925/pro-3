#include <stdio.h>

int main(void)
{
    int i, point;
    double GP = 0, average;

    for (i = 0;; i++)
    {
        fprintf(stderr, "point: ");
        if (scanf("%d", &point) == EOF)
            break;

        if ((point >= 90) && (point <= 100))
        {
            printf("4.0\n");
            GP += 4.0;
        }
        else if ((point >= 85) && (point <= 89))
        {
            printf("3.5\n");
            GP += 3.5;
        }

        else if ((point >= 80) && (point <= 84))
        {
            printf("3.0\n");
            GP += 3.0;
        }
        else if ((point >= 75) && (point <= 79))
        {
            printf("2.5\n");
            GP += 2.5;
        }
        else if ((point >= 70) && (point <= 74))
        {
            printf("2.0\n");
            GP += 2.0;
        }
        else if ((point >= 65) && (point <= 69))
        {
            printf("1.5\n");
            GP += 1.5;
        }
        else if ((point >= 60) && (point <= 64))
        {
            printf("1.0\n");
            GP += 1.0;
        }
        else
        {
            printf("0.0\n");
            GP += 0.0;
        }
    }
    average = GP / i;
    printf("%0.3f\n", average);
}