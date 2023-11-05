#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINELEN 1000

int main(void)
{

    char *line[LINELEN];
    char s[LINELEN];
    int num = 0;

    while (fgets(s, LINELEN, stdin) != NULL)
    {
        line[num] = malloc(strlen(s) + 1);
        strcpy(line[num], s);
        // strncpy(line[num],s,strlen(s)+1);
        num++;
    }

    for (int i = num - 1; i >= 0; i--)
    {
        printf("%s", line[i]);
        free(line[i]);
    }

    return 0;
}