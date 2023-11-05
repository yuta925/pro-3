#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pref.h"

pref_t *pref_new(char *name, double area, int population)
{
    pref_t *p = NULL;

    p = (pref_t *)malloc(sizeof(pref_t));

    strncpy(p->name, name, NAMELEN);
    p->area = area;
    p->population = population;

    return p;
}

void pref_print(pref_t *p)
{
    printf("%-10s %.2f %9d\n", p->name, p->area, p->population);
}

pref_t *pref_new_scan()
{
    pref_t *p;
    p = (pref_t *)malloc(sizeof(pref_t));

    if (scanf("%s %lf %d", p->name, &p->area, &p->population) == EOF)
        return NULL;
    else
        return p;
}