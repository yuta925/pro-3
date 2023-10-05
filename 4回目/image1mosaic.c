#include <stdio.h>
#include "image1.h"

/* 画像全体を「涼しげ」にする関数 */
void bmp_cool(bmp_header_t *hd, pixel_t img[MAX_Y][MAX_X]);

int main(void)
{
    bmp_header_t hd;
    pixel_t img[MAX_Y][MAX_X];

    bmp_read("in.bmp", &hd, img);
    bmp_mosaic(&hd, img);
    bmp_write("out.bmp", &hd, img);

    return 0;
}

void bmp_mosaic(bmp_header_t *hd, pixel_t img[MAX_Y][MAX_X])
{
    int i, j;

    for (i = 0; i < hd->biHeight; i++)
    {
        for (j = 0; j < hd->biWidth; j++)
        {
            img[i][j].r = img[i][j].r * 0.8;
        }
    }
}