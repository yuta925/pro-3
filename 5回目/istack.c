#include <stdio.h>
#include <stdlib.h>
#include "istack.h"

istack_t *istack_new(int size)
{
    istack_t *p = NULL;
    p = (istack_t *)malloc(sizeof(istack_t));
    if (p == NULL)
    {
        fprintf(stderr, "Error: mollocの失敗\n");
        exit(1);
    }
    p->size = size;
    p->sp = 0;
    int *a = NULL;
    a = (int *)malloc(sizeof(size));
    if (a == NULL)
    {
        fprintf(stderr, "Error: mollocの失敗\n");
        exit(1);
    }
    p->data = a;
    return p;
}

void istack_delete(istack_t *s)
{
    free(s->data);
    free(s);
}

void istack_push(istack_t *s, int d)
{
    if (s->sp < s->size)
    {
        s->sp++;
        s->data[s->sp - 1] = d;
    }
    else if (s->sp == s->size)
    {
        s->size *= 2;
        s->data = realloc(s->data, s->size * sizeof(int));
        s->sp++;
        s->data[s->sp - 1] = d;
    }
}

void istack_pop(istack_t *s, int *d)
{
    if (s->sp > 0)
    {
        *d = s->data[s->sp - 1];
        s->sp--;
    }
    else if (s->sp == 0)
        *d = 0;
}

int istack_empty(istack_t *s)
{
    if (s->sp == 0)
        return 1;
    else
        return 0;
}

int istack_full(istack_t *s)
{
    if (s->sp == s->size)
        return 1;
    else
        return 0;
}