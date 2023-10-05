#include <stdio.h>

#define LINELEN 128

int main(void)
{
    char *line[LINELEN + 1];
    char s[LINELEN + 1];
    while (fgets(s, LINELEN, stdin) != NULL)
    {
        printf("%s", s);
    }
    return 0;
}