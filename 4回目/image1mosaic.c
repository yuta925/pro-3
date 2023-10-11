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
    int x, y, mx, my;

    for (y = 0; y < hd->biHeight; y += 16)
    {
        for (x = 0; x < hd->biWidth / 2; x += 16)
        {
            int sumR = 0, sumG = 0, sumB = 0;
            int avgR = 0, avgG = 0, avgB = 0;

            for (my = 0; my < 16; my++)
            {
                for (mx = 0; mx < 16; mx++)
                {
                    sumR += img[y + my][x + mx].r;
                    sumG += img[y + my][x + mx].g;
                    sumB += img[y + my][x + mx].b;
                }
            }

            avgR = sumR / 256;
            avgG = sumG / 256;
            avgB = sumB / 256;

            for (my = 0; my < 16; my++)
            {
                for (mx = 0; mx < 16; mx++)
                {
                    img[y + my][x + mx].r = avgR;
                    img[y + my][x + mx].g = avgG;
                    img[y + my][x + mx].b = avgB;
                }
            }
        }
    }
}
