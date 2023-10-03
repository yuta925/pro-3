typedef struct
{
    double x; /* x座標 */
    double y; /* y座標 */
} point_t;

int point_scan(point_t *p);
double dist(point_t *p1, point_t *p2);