#include <stdio.h>
#include "iata_db.h"

int main(void)
{
    db_t db;
    char key[KEY_LEN + 1];
    char *data;

    db_init(&db);
    db_load(&db);

    /* 空港コードを入力するとデータを出力; EOFまで繰り返し実行 */
    for (;;)
    {
        fprintf(stderr, "key = ");
        if (scanf(KEY_FMT, key) == EOF)
        {
            break;
        }
        data = db_linear_search(&db, key);
        if (data == NULL)
        {
            printf("NO RECORD\n");
        }
        else
        {
            printf("%s => %s\n", key, data);
        }
    }

    db_delete(&db);
    return 0;
}