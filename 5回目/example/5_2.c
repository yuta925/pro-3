#include <stdio.h>
#include <stdlib.h>
#define SLEN 126
#define SFMT "%126s"

char *strclone(char s[]);

int main(void)
{
    char s[SLEN + 1];
    char *s2 = NULL;

    for (;;)
    {
        fprintf(stderr, "s = ");
        if (scanf(SFMT, s) == EOF)
        {
            break;
        }
        s2 = strclone(s);
        printf("s2 = %s\n", s2);
        free(s2);
        s2 = NULL;
    }

    return 0;
}