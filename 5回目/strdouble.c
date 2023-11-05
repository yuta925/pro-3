#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SLEN 126
#define SFMT "%126s"

char *strdouble(char s[])
{
    char *clone = NULL;
    int i, j;

    clone = (char *)malloc(sizeof(char) * (strlen(s) * 2 + 1)); // strlen関数の返り値はnullを除く配列のサイズ

    for (i = 0; s[i] != '\0'; i++)
        clone[i] = s[i];

    for (j = 0; s[j] != '\0'; j++)
        clone[j + i] = s[j];

    clone[i + j] = '\0';

    return clone;
}