#include <stdio.h>
#include <stdlib.h>
#include "istack.h"

// istack_empty/istack_full のテスト

#define ISTACK_SIZE 4

void istack_print(istack_t *s)
{
    int i;
    printf("(size = %d, sp = %d, data = [", s->size, s->sp);
    for (i = 0; i < s->sp; i++)
    {
        printf(" %d", s->data[i]);
    }
    printf(" ])\n");
}

int main(void)
{
    istack_t *s = istack_new(ISTACK_SIZE);
    istack_print(s);
    // (size = 4, sp = 0, data = [ ])
    printf("empty = %d, full = %d\n", istack_empty(s), istack_full(s));
    // empty = 1, full = 0

    istack_push(s, 5);
    istack_push(s, 6);
    istack_print(s);
    // (size = 4, sp = 2, data = [ 5 6 ])
    printf("empty = %d, full = %d\n", istack_empty(s), istack_full(s));
    // empty = 0, full = 0

    istack_push(s, 2);
    istack_push(s, 8);
    istack_print(s);
    // (size = 4, sp = 4, data = [ 5 6 2 8 ])
    printf("empty = %d, full = %d\n", istack_empty(s), istack_full(s));
    // empty = 0, full = 1

    int d;
    istack_pop(s, &d);
    istack_pop(s, &d);
    istack_print(s);
    // (size = 4, sp = 2, data = [ 5 6 ])
    printf("empty = %d, full = %d\n", istack_empty(s), istack_full(s));
    // empty = 0, full = 0

    istack_pop(s, &d);
    istack_pop(s, &d);
    istack_print(s);
    // (size = 4, sp = 0, data = [ ])
    printf("empty = %d, full = %d\n", istack_empty(s), istack_full(s));
    // empty = 1, full = 0

    istack_delete(s);
    s = NULL;
    return 0;
}