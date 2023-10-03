#include <stdio.h>

#define NM_LEN 31
#define NM_FMT "%31s"

typedef struct
{
    char name[NM_LEN + 1]; /* 品物の名前 */
    int price;             /* 価格 */
    double weight;         /* 重量 */
} item_t;

int item_scan(item_t *x)
{
    fprintf(stderr, "name = ");
    if (scanf(NM_FMT, x->name) == EOF)
    {
        return EOF;
    }
    fprintf(stderr, "price = ");
    if (scanf("%d", &x->price) == EOF)
    {
        return EOF;
    }
    fprintf(stderr, "weight = ");
    if (scanf("%lf", &x->weight) == EOF)
    {
        return EOF;
    }
    return 1;
}

void item_double_price(item_t *x)
{
    x->price = x->price * 2;
}

void item_print(item_t *x)
{
    printf("%s", x->name);
    printf(",%d", x->price);
    printf(",%0.2f", x->weight);
    printf("\n");
}

int main(void)
{
    item_t a;
    for (;;)
    {
        if (item_scan(&a) == EOF)
        {
            break;
        }
        item_double_price(&a);
        item_print(&a);
    }
    return 0;
}