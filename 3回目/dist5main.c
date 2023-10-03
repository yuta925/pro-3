#include <stdio.h>
#include <math.h>
#include "dist5.h"

int main(void)
{
    point_t p1, p2;
    for (;;)
    {
        if (point_scan(&p1) == EOF)
        {
            break;
        }
        if (point_scan(&p2) == EOF)
        {
            break;
        }
        printf("%0.4f\n", dist(&p1, &p2));
    }
    return 0;
}