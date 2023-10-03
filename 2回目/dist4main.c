#include <stdio.h>
#include <math.h>
#include "dist4.h"

#define REPEAT 3

int main(void)
{
    point_t p1, p2;
    int r;
    for (r = 0; r < REPEAT; r++)
    {
        fprintf(stderr, "p1 と p2 の座標 (それぞれ x と y) をスペース区切りで : ");
        scanf("%lf %lf", &p1.x, &p1.y);
        fprintf(stderr, "p2 の座標 (x と y): ");
        scanf("%lf %lf", &p2.x, &p2.y);
        printf("%0.4f\n", dist(p1, p2));
    }
    return 0;
}