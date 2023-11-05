#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024 // 1行あたりの最大文字数
#define MAX_LINE 10

int main(void)
{
    char *line[MAX_LINE];
    char buffer[BUFFER_SIZE]; // 標準入力から読み込むためのバッファ
    int i = 0, count = 0;

    while (fgets(buffer, BUFFER_SIZE, stdin) != NULL)
    {
        // 必要なメモリを割り当てる
        line[count] = malloc(strlen(buffer) + 1);
        strcpy(line[count], buffer);
        count++;
        if (count > MAX_LINE - 1)
        {
            printf("Error\n");
            break;
        }
    }

    for (i = count - 1; i >= 0; i--)
    {
        printf("%s", line[i]);
        free(line[i]);
    }

    return 0;
}

// line は char 型へのポインタの配列
// 1行のデータ (文字列) を読み込む毎に,
// そのデータをちょうど格納できるサイズの文字配列を割り当てて
// そこに読み込んだ文字列データをコピーし,
// その文字配列の先頭を指すポインタを
// line[0], line[1], …, line[n-1] に格納する