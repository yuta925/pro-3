#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "image2.h"

/*******************************************************
   24ビット-ビットマップデータ (BMPファイル) のファイル入出力
   (制限)
     - 画像の横幅は４の倍数であること
     - リトルエンディアンにのみ対応
********************************************************/

void bmp_read(
    char filename[FILENAME_MAX],
    bmp_data_t *hd)
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
    fread(&hd->header.bfType, sizeof(hd->header.bfType), 1, fp);
    fread(&hd->header.bfSize, sizeof(hd->header.bfSize), 1, fp);
    fread(&hd->header.bfReserved1, sizeof(hd->header.bfReserved1), 1, fp);
    fread(&hd->header.bfReserved2, sizeof(hd->header.bfReserved2), 1, fp);
    fread(&hd->header.bfOffBits, sizeof(hd->header.bfOffBits), 1, fp);
    fread(&hd->header.biSize, sizeof(hd->header.biSize), 1, fp);
    fread(&hd->header.biWidth, sizeof(hd->header.biWidth), 1, fp);
    fread(&hd->header.biHeight, sizeof(hd->header.biHeight), 1, fp);
    fread(&hd->header.biPlanes, sizeof(hd->header.biPlanes), 1, fp);
    fread(&hd->header.biBitCount, sizeof(hd->header.biBitCount), 1, fp);
    fread(&hd->header.biCompression, sizeof(hd->header.biCompression), 1, fp);
    fread(&hd->header.biSizeImage, sizeof(hd->header.biSizeImage), 1, fp);
    fread(&hd->header.biXPelsPerMeter, sizeof(hd->header.biXPelsPerMeter), 1, fp);
    fread(&hd->header.biYPelsPerMeter, sizeof(hd->header.biYPelsPerMeter), 1, fp);
    fread(&hd->header.biClrUsed, sizeof(hd->header.biClrUsed), 1, fp);
    fread(&hd->header.biClrImportant, sizeof(hd->header.biClrImportant), 1, fp);

    assert(hd->header.biHeight <= MAX_Y);
    assert(hd->header.biWidth <= MAX_X);

    /* ビットマップデータの読み込み */
    for (i = 0; i < hd->header.biHeight; i++)
    {
        for (j = 0; j < hd->header.biWidth; j++)
        {
            fread(&hd->img[i][j].b, 1, 1, fp);
            fread(&hd->img[i][j].g, 1, 1, fp);
            fread(&hd->img[i][j].r, 1, 1, fp);
        }
    }

    /* ファイルクローズ */
    fclose(fp);
}

void bmp_write(
    char filename[FILENAME_MAX],
    bmp_data_t *hd)
{
    FILE *fp;
    int i, j;

    assert(hd->header.biHeight <= MAX_Y);
    assert(hd->header.biWidth <= MAX_X);

    /* ファイルオープン */
    if ((fp = fopen(filename, "wb")) == NULL)
    {
        fprintf(stderr, "write_bmp: failed to open \"%s\"\n", filename);
        exit(1);
    }
    fprintf(stderr, "output file = %s\n", filename);

    /* ヘッダ情報の書き出し */
    fwrite(&hd->header.bfType, sizeof(hd->header.bfType), 1, fp);
    fwrite(&hd->header.bfSize, sizeof(hd->header.bfSize), 1, fp);
    fwrite(&hd->header.bfReserved1, sizeof(hd->header.bfReserved1), 1, fp);
    fwrite(&hd->header.bfReserved2, sizeof(hd->header.bfReserved2), 1, fp);
    fwrite(&hd->header.bfOffBits, sizeof(hd->header.bfOffBits), 1, fp);
    fwrite(&hd->header.biSize, sizeof(hd->header.biSize), 1, fp);
    fwrite(&hd->header.biWidth, sizeof(hd->header.biWidth), 1, fp);
    fwrite(&hd->header.biHeight, sizeof(hd->header.biHeight), 1, fp);
    fwrite(&hd->header.biPlanes, sizeof(hd->header.biPlanes), 1, fp);
    fwrite(&hd->header.biBitCount, sizeof(hd->header.biBitCount), 1, fp);
    fwrite(&hd->header.biCompression, sizeof(hd->header.biCompression), 1, fp);
    fwrite(&hd->header.biSizeImage, sizeof(hd->header.biSizeImage), 1, fp);
    fwrite(&hd->header.biXPelsPerMeter, sizeof(hd->header.biXPelsPerMeter), 1, fp);
    fwrite(&hd->header.biYPelsPerMeter, sizeof(hd->header.biYPelsPerMeter), 1, fp);
    fwrite(&hd->header.biClrUsed, sizeof(hd->header.biClrUsed), 1, fp);
    fwrite(&hd->header.biClrImportant, sizeof(hd->header.biClrImportant), 1, fp);

    /* ビットマップデータの書き出し */
    for (i = 0; i < hd->header.biHeight; i++)
    {
        for (j = 0; j < hd->header.biWidth; j++)
        {
            fwrite(&hd->img[i][j].b, 1, 1, fp);
            fwrite(&hd->img[i][j].g, 1, 1, fp);
            fwrite(&hd->img[i][j].r, 1, 1, fp);
        }
    }

    /* ファイルクローズ */
    fclose(fp);
}