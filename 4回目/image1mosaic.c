#include <stdio.h>
#include "image1.h"

void bmp_mosaic(bmp_header_t *hd, pixel_t img[MAX_Y][MAX_X]);

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
    int i, j, k, l;
    int sum_r = 0, sum_g = 0, sum_b = 0;
    int average_r = 0, average_g = 0, average_b = 0;

    for (i = 0; i < hd->biHeight; i += 16)
    {
        for (j = 0; j < hd->biWidth / 2; j += 16)
        {
            for (k = i; k < 16; k++)
            {
                for (l = j; l < 16; l++)
                {
                    sum_r += img[k][l].r;
                    sum_g += img[k][l].g;
                    sum_b += img[k][l].b;
                }
            }

            average_r = sum_r;
            average_g = sum_g;
            average_b = sum_b;

            for (k = i; k < 16; k++)
            {
                for (l = j; l < 16; l++)
                {
                    img[k][l].r = average_r;
                    img[k][l].g = average_g;
                    img[k][l].b = average_b;
                }
            }
        }
    }
}
