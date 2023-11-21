#include <stdio.h>
#include "iata_db.h"

int main(void)
{
    db_t db;
    char code[KEY_LEN + 1];
    char *data;

    db_init(&db);
    db_hash_load(&db);

    /* 空港コードを入力するとデータを出力; EOFまで繰り返し実行 */
    for (;;)
    {
        fprintf(stderr, "code = ");
        if (scanf(KEY_FMT, code) == EOF)
        {
            break;
        }
        data = db_hash_search(&db, code);
        if (data == NULL)
        {
            printf("NO RECORD\n");
        }
        else
        {
            printf("%s => %s\n", code, data);
        }
    }

    db_delete(&db);
    return 0;
}