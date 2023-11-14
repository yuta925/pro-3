#include <stdio.h>
#include <stdlib.h>
#include <time.h> /* 時間計測に必要 */
#include <assert.h>

#define MIN_N 2 /* 完成後にもっと大きくする */
#define MAX_N 8 /* 完成後にもっと大きくする */
#define N_TEST 8

void sort(int n, double *a);

void array_set_rand(int n, double *a)
{
    /* a[0]〜a[n-1] に乱数のデータをセットする */
    int i;
    double ransu;
    for (i = 0; i < n; i++)
    {
        ransu = rand();
        a[i] = ransu;
    }
}

void array_set_sorted(int n, double *a)
{
    /* a[0]〜a[n-1] に正順のデータをセットする */
    int i;
    for (i = 0; i < n; i++)
        a[i] = i;
}

void array_set_reverse(int n, double *a)
{
    /* a[0]〜a[n-1] に逆順のデータをセットする */
    int i;
    for (i = 0; i < n; i++)
        a[i] = n - 1 - i;
}

void array_copy(int n, double *a, double *r)
{
    /* r[0]〜r[n-1] から a[0]〜a[n-1] にデータコピーする */
    int i;
    for (i = 0; i < n; i++)
        a[i] = r[i];
}

void sort_check(int n, double *a)
{
    int i;
    for (i = 0; i < n - 1; i++)
    {
        if (a[i] <= a[i + 1])
        {
            ; /* OK */
        }
        else
        {
            /* データが (a[i] と a[i+1] が) 昇順に並んでいない */
            fprintf(stderr, "sort error (a[%d]=%0.10f, a[%d]=%0.10f)\n", i, a[i], i + 1, a[i + 1]);
            exit(1);
        }
    }
}

void sort_cpu(double *r)
{
    int n;
    int i;
    double *a;
    int t0, t1;
    clock_t clk_start, clk_end;

    /* 初期データがちゃんと生成されているかの確認用 */
    for (i = 0; i < N_TEST; i++)
    {
        printf("%18.5f\n", r[i]);
    }

    /** ここを埋めて関数を完成させよ **/
    double *b = malloc(sizeof(double) * MAX_N);
    a = b;
    for (n = MIN_N; n <= MAX_N; n *= 2)
    {
        printf("n = %d\n", n);
        array_copy(n, a, r);
        clk_start = clock();
        sort(n, a);
        clk_end = clock();
        sort_check(n, a);
        printf("cpu = %11.6f [sec]\n", (double)(clk_end - clk_start) / CLOCKS_PER_SEC);
    }
    free(a);
}

int main(void)
{
    double *r;
    int i;

    r = (double *)malloc(sizeof(double) * MAX_N);
    if (r == NULL)
    {
        fprintf(stderr, "malloc に失敗 (MAX_N = %d\n", MAX_N);
        exit(1);
    }

    printf("乱数\n");
    array_set_rand(MAX_N, r);
    sort_cpu(r);

    printf("正順\n");
    array_set_sorted(MAX_N, r);
    sort_cpu(r);

    printf("逆順\n");
    array_set_reverse(MAX_N, r);
    sort_cpu(r);

    free(r);
    r = NULL;

    return 0;
}