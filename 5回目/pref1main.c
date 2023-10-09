#include <stdlib.h>
#include "pref.h"

int main(void)
{
    pref_t *a = NULL;
    pref_t *b = NULL;
    pref_t *c = NULL;

    a = pref_new("Tokyo", 2187.65, 12988797);
    b = pref_new("Osaka", 1898.01, 8840372);
    c = pref_new("Hyogo", 8395.89, 5599359);

    pref_print(a);
    pref_print(b);
    pref_print(c);

    free(a);
    free(b);
    free(c);
    a = NULL;
    b = NULL;
    c = NULL;

    return 0;
}