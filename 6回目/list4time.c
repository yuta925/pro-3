#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "myrand.h"
#include <time.h>

int main(void)
{
    list_node_t *head_p = create_node(0);
    clock_t clk_start, clk_end;
    int n, i;

    // (0) 標準入力から正整数nを入力する
    printf("n=");
    scanf("%d", &n);

    // (1) 乱数をn個発生させ、それをlist_insert_uniqで順次リストに挿入する
    clk_start = clock();
    myrand_init();
    for (i = 1; i <= n; i++)
        list_insert_uniq(head_p, myrand());
    clk_end = clock();
    printf("cpu = %g [sec]\n", (double)(clk_end - clk_start) / CLOCKS_PER_SEC);

    // (2) (1)と同じ乱数をn個発生させ、list_findでそのデータをリスト中に検索する
    clk_start = clock();
    myrand_init();
    for (i = 1; i <= n; i++)
        list_find(head_p, myrand());
    clk_end = clock();
    printf("cpu = %g [sec]\n", (double)(clk_end - clk_start) / CLOCKS_PER_SEC);

    // (3) (1)と異なる乱数をn個発生させ、list_findでそのデータをリスト中に検索する
    clk_start = clock();
    for (i = 1; i <= n; i++)
        list_find(head_p, myrand());
    clk_end = clock();
    printf("cpu = %g [sec]\n", (double)(clk_end - clk_start) / CLOCKS_PER_SEC);
}