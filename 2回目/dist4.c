#include <stdio.h>
#include <math.h>
#include "dist4.h"

double dist(point_t p1, point_t p2)
{
    return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}