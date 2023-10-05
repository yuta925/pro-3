/* この課題において関数の名前はどうするのか bmp_coolのままでいいのか*/
#include <stdio.h>
#include "image1.h"

/* 画像全体を「涼しげ」にする関数 */
void bmp_cool(bmp_header_t *hd, pixel_t img[MAX_Y][MAX_X]);

int main(void)
{
    bmp_header_t hd;
    pixel_t img[MAX_Y][MAX_X];

    bmp_read("in.bmp", &hd, img);
    bmp_frame(&hd, img);
    bmp_write("out.bmp", &hd, img);

    return 0;
}

void bmp_frame(bmp_header_t *hd, pixel_t img[MAX_Y][MAX_X])
{
    int i, j;
    int average = 0;
    int temp;

    for (i = 0; i < hd->biHeight; i++)
    {
        for (j = 0; j < hd->biWidth; j++)
        {
            if (i <= 8 || i >= hd->biHeight - 8)
            {
                img[i][j].r = 255;
                img[i][j].g = 192;
                img[i][j].b = 203;
            }
            else if (j <= 8 || j >= hd->biWidth - 8)
            {
                img[i][j].r = 255;
                img[i][j].g = 192;
                img[i][j].b = 203;
            }
        }
    }
}