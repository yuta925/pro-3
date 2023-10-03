#include <stdio.h>
#include <string.h>

#define NM_LEN 31
#define N_FMT "%31s"

typedef struct
{
    char name[NM_LEN + 1]; /* 名前 */
    double stature;        /* 身長 [cm] */
    double weight;         /* 重量 [kg] */
    double bmi;            /* BMI値 */
} body_index_t;

void body_index_print(body_index_t);
double bmi(body_index_t);

int main(void)
{
    body_index_t p;
    for (;;)
    {
        fprintf(stderr, "名前を入力して下さい (qで終了): ");
        scanf(N_FMT, p.name);
        if (strcmp(p.name, "qq") == 0)
            break;
        fprintf(stderr, "身長を入力してください");
        if (scanf("%lf", &p.stature) == EOF)
            break;
        fprintf(stderr, "体重を入力してください");
        if (scanf("%lf", &p.weight) == EOF)
            break;
        p.bmi = bmi(p);
        body_index_print(p);
    }
}

void body_index_print(body_index_t x)
{
    printf("name: %s\n", x.name);
    printf("stature: %0.1fcm\n", x.stature);
    printf("weight: %0.1fkg\n", x.weight);
    printf("BMI: %0.1f\n", x.bmi);
}

double bmi(body_index_t x)
{
    return x.weight / ((x.stature / 100) * (x.stature / 100));
}