#include "myrand.h"

static unsigned long myrand_r;

#define R_INIT 53402397UL
#define A 65539UL
#define B 125654UL
#define MASK 0x7fffffffUL

void myrand_init(void)
{
    myrand_r = R_INIT;
}

int myrand(void)
{
    myrand_r = (myrand_r * A + B) & MASK;
    return (int)myrand_r;
}