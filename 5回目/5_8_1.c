#include <stdio.h>
#include <stdlib.h>
#include "istack.h"

// istack_new/istack_delete のテスト

#define ISTACK_SIZE 8

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
    istack_delete(s);
    s = NULL;
    return 0;
}