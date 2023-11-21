#include <stdio.h>
#include "iata_db.h"
#include <time.h> /* 時間計測に必要 */

int main(void)
{
    db_t db;
    char key[KEY_LEN + 1];
    char *data;

    clock_t clk_start, clk_end;

    db_init(&db);
    db_hash_load(&db);

    /* 空港コードを入力するとデータを出力; EOFまで繰り返し実行 */
    for (;;)
    {
        fprintf(stderr, "key = ");
        if (scanf(KEY_FMT, key) == EOF)
        {
            break;
        }
        clk_start = clock();
        for (int i = 0; i < 100000; i++)
            data = db_hash_search(&db, key);
        clk_end = clock();

        if (data == NULL)
        {
            printf("NO RECORD\n");
            printf("cpu = %11.6f [sec]\n", (double)(clk_end - clk_start) / CLOCKS_PER_SEC);
        }
        else
        {
            printf("%s => %s\n", key, data);
            printf("cpu = %11.6f [sec]\n", (double)(clk_end - clk_start) / CLOCKS_PER_SEC);
        }
    }

    db_delete(&db);
    return 0;
}