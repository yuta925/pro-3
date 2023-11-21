#include <stdio.h>
#include "iata_db.h"

int main(void)
{
    db_t db;

    db_init(&db);
    db_hash_load(&db);
    db_dump(&db);
    db_delete(&db);

    return 0;
}