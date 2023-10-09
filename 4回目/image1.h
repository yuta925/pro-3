#define MAX_Y 512 /* 最大画像サイズ (横方向) */
#define MAX_X 512 /* 最大画像サイズ (縦方向) */

#define LEVEL 256 /* 画素の階調 */
#define HIGH 255  /* 画素の輝度の最大値 */
#define LOW 0     /* 画素の輝度の最小値 */

typedef struct
{
    unsigned short bfType;
    unsigned int bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int bfOffBits;
    unsigned int biSize;
    unsigned int biWidth;
    unsigned int biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned int biCompression;
    unsigned int biSizeImage;
    unsigned int biXPelsPerMeter;
    unsigned int biYPelsPerMeter;
    unsigned int biClrUsed;
    unsigned int biClrImportant;
} bmp_header_t;

typedef struct
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
} pixel_t;

void bmp_read(char filename[], bmp_header_t *header, pixel_t image[MAX_Y][MAX_X]);
void bmp_write(char filename[], bmp_header_t *header, pixel_t image[MAX_Y][MAX_X]);
