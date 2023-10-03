#include <stdio.h>
#include <string.h>

#define W_LEN 31     /* 文字列 w の最大文字数 */
#define W_FMT "%31s" /* 文字列 w を読み込むフォーマット */

int main(void)
{
    int i;
    char w[W_LEN + 1];

    for (;;)
    {

        fprintf(stderr, "英単語を入力して下さい (qq で終了): ");
        scanf(W_FMT, w);
        if (strcmp(w, "qq") == 0)
            break;
        for (i = 0; w[i] != '\0'; i++)
        {
            if (w[i] != 'a' && w[i] != 'i' && w[i] != 'u' && w[i] != 'e' && w[i] != 'o')
                w[i] = '*';
        }

        for (i = 0; w[i] != '\0'; i++)
            printf("%c", w[i]);
        printf("\n");
    }

    return 0;
}