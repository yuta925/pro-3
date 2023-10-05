#include <stdio.h>
#include "image1.h"

void bmp_cool(bmp_header_t *hd, pixel_t img[MAX_Y][MAX_X]);

int main(void)
{
    bmp_header_t hd;
    pixel_t img[MAX_Y][MAX_X];

    bmp_read("in.bmp", &hd, img);
    bmp_collapse(&hd, img);
    bmp_write("out.bmp", &hd, img);

    return 0;
}

void bmp_collapse(bmp_header_t *hd, pixel_t img[MAX_Y][MAX_X])
{
    int i, j;
    int average = 0;
    int temp;

    for (i = 0; i < hd->biHeight; i++)
    {
        for (j = 0; j < hd->biWidth; j++)
        {
            w
        }
    }
}
