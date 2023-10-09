#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMELEN 15

typedef struct
{
    char name[NAMELEN + 1]; /* 県名 */
    double area;            /* 面積 (km2)*/
    int population;         /* 人口 (人) */
} pref_t;

int main(void)
{
    /* 構造体へのポインタを格納する変数 */
    pref_t *a = NULL;
    pref_t *b = NULL;
    pref_t *c = NULL;

    /* 動的割当て */
    a = (pref_t *)malloc(sizeof(pref_t));
    b = (pref_t *)malloc(sizeof(pref_t));
    c = (pref_t *)malloc(sizeof(pref_t));

    /* 値の代入 */
    strncpy(a->name, "Tokyo", NAMELEN);
    a->area = 2187.65;
    a->population = 12988797;
    strncpy(b->name, "Osaka", NAMELEN);
    b->area = 1898.01;
    b->population = 8840372;
    strncpy(c->name, "Hyogo", NAMELEN);
    c->area = 8395.89;
    c->population = 5599359;

    /* 出力 */
    printf("%-10s %9.2f %9d\n", a->name, a->area, a->population);
    printf("%-10s %9.2f %9d\n", b->name, b->area, b->population);
    printf("%-10s %9.2f %9d\n", c->name, c->area, c->population);

    /* 解放 */
    free(a);
    free(b);
    free(c);
    a = NULL;
    b = NULL;
    c = NULL;

    return 0;
}