#include <stdio.h>
#include "image1.h"

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

void bmp_mirror(bmp_header_t *hd, pixel_t img[MAX_Y][MAX_X])
{
    int i, j;
    int temp;

    for (j = 0; j < hd->biWidth; j++)
    {
        for (i = 0; i <= hd->biHeight / 2; i++)
        {
            temp = img[i][j].r;
            img[i][j].r = img[hd->biHeight - 1 - i][j].r;
            img[hd->biHeight - 1 - i][j].r = temp;

            temp = img[i][j].g;
            img[i][j].g = img[hd->biHeight - 1 - i][j].g;
            img[hd->biHeight - 1 - i][j].g = temp;

            temp = img[i][j].b;
            img[i][j].b = img[hd->biHeight - 1 - i][j].b;
            img[hd->biHeight - 1 - i][j].b = temp;
        }
    }
}