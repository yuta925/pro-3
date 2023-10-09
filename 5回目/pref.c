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
    printf("%-10s %9.2f %9d\n", p->name, p->area, p->population);
}

pref_t *pref_new_scan()
{
    char *name;
    double area;
    int population;

    fprintf(stderr, "name:");
    fscanf("%s", name);
    fprintf(stderr, "area:");
    scanf("%9.2f", &area);
    fprintf(stderr, "population:");
    scanf("%9d", &population);

    pref_t *p = NULL;

    p = (pref_t *)malloc(sizeof(pref_t));

    strncpy(p->name, name, NAMELEN);
    p->area = area;
    p->population = population;

    return p;
}