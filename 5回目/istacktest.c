#include <stdio.h>
#include <assert.h>
#include "istack.h"

#define ISTACK_SIZE 4

#define PRINT 1
#define NO_PRINT 0

void istack_print(istack_t *s)
{
    int i;
    assert(s != NULL);
    assert(s->data != NULL);
    printf("(size = %d, sp = %d, data = [", s->size, s->sp);
    for (i = 0; i < s->sp; i++)
    {
        printf(" %d", s->data[i]);
    }
    printf(" ])\n");
}

void repeat_istack_push(istack_t *s, int n, int do_print)
/* push を n 回行うテスト */
{
    int i;
    for (i = 0; i < n; i++)
    {
        int d = i * i;
        if (do_print)
        {
            printf("E=%d, F=%d; ", istack_empty(s), istack_full(s));
            printf(" push(s,%d); ", d);
        }
        istack_push(s, d);
        if (do_print)
        {
            istack_print(s);
        }
    }
}

void repeat_istack_pop(istack_t *s, int n, int do_print)
/* pop を n 回行うテスト */
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (do_print)
        {
            printf("E=%d, F=%d; ", istack_empty(s), istack_full(s));
        }
        int d;
        istack_pop(s, &d);
        if (do_print)
        {
            printf(" pop(s) = %d; ", d);
            istack_print(s);
        }
    }
}

int main(void)
{
    istack_t *s, *s2;
    int i, d;

    s = istack_new(ISTACK_SIZE);
    repeat_istack_push(s, ISTACK_SIZE, PRINT);
    repeat_istack_pop(s, ISTACK_SIZE / 2, PRINT);
    repeat_istack_push(s, ISTACK_SIZE / 2, PRINT);
    repeat_istack_pop(s, ISTACK_SIZE * 3 / 2, PRINT);
    repeat_istack_push(s, ISTACK_SIZE * 3, PRINT);
    repeat_istack_pop(s, ISTACK_SIZE, PRINT);
    repeat_istack_push(s, ISTACK_SIZE * 10, NO_PRINT);
    repeat_istack_pop(s, ISTACK_SIZE / 2, PRINT);
    repeat_istack_pop(s, ISTACK_SIZE * 10, NO_PRINT);
    repeat_istack_push(s, ISTACK_SIZE / 2, PRINT);
    repeat_istack_pop(s, ISTACK_SIZE / 2, PRINT);

    s2 = istack_new(ISTACK_SIZE);
    repeat_istack_push(s2, ISTACK_SIZE, PRINT);
    repeat_istack_pop(s2, ISTACK_SIZE, PRINT);

    istack_delete(s2);
    istack_delete(s);

    return 0;
}