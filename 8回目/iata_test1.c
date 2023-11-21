#include <stdio.h>
#include "iata_db.h"

int main(void)
{
    db_t db;
    db_init(&db);   /* db の初期化 */
    db_load(&db);   /* iata_mini.csv からデータを読み込む */
    db_dump(&db);   /* 読み込んでいるデータを出力する */
    db_delete(&db); /* db の破棄 */
    return 0;
}