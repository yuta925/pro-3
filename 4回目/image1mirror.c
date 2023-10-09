/* この課題において関数の名前はどうするのか bmp_coolのままでいいのか*/
#include <stdio.h>
#include "image1.h"

/* 画像全体を「涼しげ」にする関数 */
void bmp_mirror(bmp_header_t *hd, pixel_t img[MAX_Y][MAX_X]);

int main(void)
{
    bmp_header_t hd;
    pixel_t img[MAX_Y][MAX_X];

    bmp_read("in.bmp", &hd, img);   /* in.bmp から読み込む */
    bmp_mirror(&hd, img);           /* 処理の呼び出し */
    bmp_write("out.bmp", &hd, img); /* out.bmp への書き出し */

    return 0;
}

/* 画像処理の関数の本体 */
void bmp_mirror(bmp_header_t *hd, pixel_t img[MAX_Y][MAX_X])
{
    int i, j;
    int average = 0;
    int temp;

    /**** 以下 (現状は画像を全体に暗くする処理になっている) を書き換えて完成させよ ****/

    for (j = 0; j < hd->biWidth; j++)
    { /* biHeight は画像の高さ */
        for (i = 0; i < hd->biHeight / 2; i++)
        { /* biWidth  は画像の幅 */
            temp = img[i][j].r;
            img[i][j].r = img[hd->biHeight - i][j].r;
            img[hd->biHeight - i][j].r = temp;

            temp = img[i][j].g;
            img[i][j].g = img[hd->biHeight - i][j].g;
            img[hd->biHeight - i][j].g = temp;

            temp = img[i][j].b;
            img[i][j].b = img[hd->biHeight - i][j].b;
            img[hd->biHeight - i][j].b = temp;
        }
    }
    /************** ここまで *************************************************/
}