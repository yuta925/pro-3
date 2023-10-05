#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "image1.h"

/*******************************************************
   24ビット-ビットマップデータ (BMPファイル) のファイル入出力
   (制限)
     - 画像の横幅は４の倍数であること
     - リトルエンディアンにのみ対応
********************************************************/

void bmp_read(
    char filename[FILENAME_MAX],
    bmp_header_t *hd,
    pixel_t img[MAX_Y][MAX_X])
{
    FILE *fp;
    int i, j;

    /* ファイルオープン */
    if ((fp = fopen(filename, "rb")) == NULL)
    {
        fprintf(stderr, "read_bmp: failed to open \"%s\"\n", filename);
        exit(1);
    }
    fprintf(stderr, "input file = \"%s\"\n", filename);

    /* ヘッダ情報の読み込み */
    fread(&hd->bfType, sizeof(hd->bfType), 1, fp);
    fread(&hd->bfSize, sizeof(hd->bfSize), 1, fp);
    fread(&hd->bfReserved1, sizeof(hd->bfReserved1), 1, fp);
    fread(&hd->bfReserved2, sizeof(hd->bfReserved2), 1, fp);
    fread(&hd->bfOffBits, sizeof(hd->bfOffBits), 1, fp);
    fread(&hd->biSize, sizeof(hd->biSize), 1, fp);
    fread(&hd->biWidth, sizeof(hd->biWidth), 1, fp);
    fread(&hd->biHeight, sizeof(hd->biHeight), 1, fp);
    fread(&hd->biPlanes, sizeof(hd->biPlanes), 1, fp);
    fread(&hd->biBitCount, sizeof(hd->biBitCount), 1, fp);
    fread(&hd->biCompression, sizeof(hd->biCompression), 1, fp);
    fread(&hd->biSizeImage, sizeof(hd->biSizeImage), 1, fp);
    fread(&hd->biXPelsPerMeter, sizeof(hd->biXPelsPerMeter), 1, fp);
    fread(&hd->biYPelsPerMeter, sizeof(hd->biYPelsPerMeter), 1, fp);
    fread(&hd->biClrUsed, sizeof(hd->biClrUsed), 1, fp);
    fread(&hd->biClrImportant, sizeof(hd->biClrImportant), 1, fp);

    assert(hd->biHeight <= MAX_Y);
    assert(hd->biWidth <= MAX_X);

    /* ビットマップデータの読み込み */
    for (i = 0; i < hd->biHeight; i++)
    {
        for (j = 0; j < hd->biWidth; j++)
        {
            fread(&img[i][j].b, 1, 1, fp);
            fread(&img[i][j].g, 1, 1, fp);
            fread(&img[i][j].r, 1, 1, fp);
        }
    }

    /* ファイルクローズ */
    fclose(fp);
}

void bmp_write(
    char filename[FILENAME_MAX],
    bmp_header_t *hd,
    pixel_t img[MAX_Y][MAX_X])
{
    FILE *fp;
    int i, j;

    assert(hd->biHeight <= MAX_Y);
    assert(hd->biWidth <= MAX_X);

    /* ファイルオープン */
    if ((fp = fopen(filename, "wb")) == NULL)
    {
        fprintf(stderr, "write_bmp: failed to open \"%s\"\n", filename);
        exit(1);
    }
    fprintf(stderr, "output file = %s\n", filename);

    /* ヘッダ情報の書き出し */
    fwrite(&hd->bfType, sizeof(hd->bfType), 1, fp);
    fwrite(&hd->bfSize, sizeof(hd->bfSize), 1, fp);
    fwrite(&hd->bfReserved1, sizeof(hd->bfReserved1), 1, fp);
    fwrite(&hd->bfReserved2, sizeof(hd->bfReserved2), 1, fp);
    fwrite(&hd->bfOffBits, sizeof(hd->bfOffBits), 1, fp);
    fwrite(&hd->biSize, sizeof(hd->biSize), 1, fp);
    fwrite(&hd->biWidth, sizeof(hd->biWidth), 1, fp);
    fwrite(&hd->biHeight, sizeof(hd->biHeight), 1, fp);
    fwrite(&hd->biPlanes, sizeof(hd->biPlanes), 1, fp);
    fwrite(&hd->biBitCount, sizeof(hd->biBitCount), 1, fp);
    fwrite(&hd->biCompression, sizeof(hd->biCompression), 1, fp);
    fwrite(&hd->biSizeImage, sizeof(hd->biSizeImage), 1, fp);
    fwrite(&hd->biXPelsPerMeter, sizeof(hd->biXPelsPerMeter), 1, fp);
    fwrite(&hd->biYPelsPerMeter, sizeof(hd->biYPelsPerMeter), 1, fp);
    fwrite(&hd->biClrUsed, sizeof(hd->biClrUsed), 1, fp);
    fwrite(&hd->biClrImportant, sizeof(hd->biClrImportant), 1, fp);

    /* ビットマップデータの書き出し */
    for (i = 0; i < hd->biHeight; i++)
    {
        for (j = 0; j < hd->biWidth; j++)
        {
            fwrite(&img[i][j].b, 1, 1, fp);
            fwrite(&img[i][j].g, 1, 1, fp);
            fwrite(&img[i][j].r, 1, 1, fp);
        }
    }

    /* ファイルクローズ */
    fclose(fp);
}