#include <stdio.h>
#include "image1.h"

void bmp_collapse(bmp_header_t *hd, pixel_t img[MAX_Y][MAX_X]);

int main(void)
{
    bmp_header_t hd;
    pixel_t img[MAX_Y][MAX_X];

    bmp_read("in.bmp", &hd, img);
    bmp_collapse(&hd, img);
    hd.biHeight /= 2;
    bmp_write("out.bmp", &hd, img);

    return 0;
}

void bmp_collapse(bmp_header_t *hd, pixel_t img[MAX_Y][MAX_X])
{
    int i, j;

    for (i = 0; i < hd->biHeight / 2; i++)
    {
        for (j = 0; j < hd->biWidth; j++)
        {
            img[i][j].r = (img[i * 2][j].r + img[i * 2 + 1][j].r) / 2;
            img[i][j].g = (img[i * 2][j].g + img[i * 2 + 1][j].g) / 2;
            img[i][j].b = (img[i * 2][j].b + img[i * 2 + 1][j].b) / 2;
        }
    }
}
