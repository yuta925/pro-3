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

/*
   1.fgetsで行を読み取る
   2.*lineに各文字列の先頭のポインタ変数を格納する
   3.逆順に並べる
*/