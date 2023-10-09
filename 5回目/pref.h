#define NAMELEN 15

typedef struct
{
    char name[NAMELEN + 1]; /* 県名 */
    double area;            /* 面積 (km2)*/
    int population;         /* 人口 (人) */
} pref_t;

pref_t *pref_new(char *name, double area, int population);
void pref_print(pref_t *p);
pref_t *pref_new_scan();
