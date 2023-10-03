#include <stdio.h>
#include <math.h>
#include "dist5.h"

int point_scan(point_t *p)
{
    fprintf(stderr, "x=");
    if (scanf("%lf", &p->x) == EOF)
        return EOF;
    fprintf(stderr, "y=");
    if (scanf("%lf", &p->y) == EOF)
        return EOF;
    return 1;
}

double dist(point_t *p1, point_t *p2)
{
    return sqrt((p2->x - p1->x) * (p2->x - p1->x) + (p2->y - p1->y) * (p2->y - p1->y));
}