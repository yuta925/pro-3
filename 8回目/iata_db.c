#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "iata_db.h"

/* c が改行記号かどうか判定するマクロ */
#define IS_EOL(c) ((c) == '\n' || (c) == '\r')

/* iata_db.c の内部だけで使用する関数 */
static char *fgetss(char *line, int len, FILE *fp);
static void extract_data(char line[], char key[], char data[]);
static void record_set(record_t *r, char key[], char data[]);

void db_init(db_t *db)
/* db_t 型変数の初期化 */
{
    int i;
    db->n = 0;
    for (i = 0; i < MAX_RECORDS; i++)
    {
        strcpy(db->record[i].key, "");
        db->record[i].data = NULL;
    }
}

void db_load(db_t *db)
/* db_t 型変数にファイル IATA_F からデータを読み込む */
{
    FILE *fp;
    char line[LINE_LEN + 1];
    char key[KEY_LEN + 1];
    char data[DATA_LEN + 1];

    /* ファイルのオープン */
    if ((fp = fopen(IATA_F, "r")) == NULL)
    {
        fprintf(stderr, "ファイル (%s) が開けません\n", IATA_F);
        exit(1);
    }

    /* データの読み込み */
    while (fgetss(line, LINE_LEN, fp) != NULL)
    {
        /* 入力データ数が収容可能最大レコード数を超えたらエラー */
        if (MAX_RECORDS <= db->n)
        {
            fprintf(stderr, "MAX_RECORDS(%d) <= n(%d)\n", MAX_RECORDS, db->n);
            exit(1);
        }
        /* line から key と data を切り出す */
        extract_data(line, key, data);
        /* db->n 番目のレコードに key と data を格納し, db->n を1増やす */
        record_set(&db->record[db->n], key, data);
        db->n++;
    }
    fclose(fp);
}

void db_delete(db_t *db)
/* db_t 型変数の領域を解放 */
{
    int i;
    for (i = 0; i < (db->n); i++)
    {
        free(db->record[i].data);
        db->record[i].data = NULL;
    }
}

static void record_set(record_t *r, char key[], char data[])
/* r の指すレコードに key と data を書き込む (data は動的割当て) */
{
    assert(r != NULL);
    assert(key != NULL);
    assert(data != NULL);
    /* key */
    assert(strlen(key) <= KEY_LEN);
    strcpy(r->key, key);
    /* data */
    assert(strlen(data) <= DATA_LEN);
    r->data = (char *)malloc(sizeof(char) * (strlen(data) + 1));
    strcpy(r->data, data);
}

static char *fgetss(char *line, int len, FILE *fp)
{
    int ll = 0;
    int c;
    for (;;)
    {
        c = fgetc(fp);
        if ((c == '\n') || feof(fp))
        {
            break;
        }
        if (ll < len)
        {
            line[ll++] = c;
        }
    }
    if (feof(fp) && (ll == 0))
    {
        return NULL;
    }
    else
    {
        line[ll++] = '\n';
        line[ll++] = '\0';
        return line;
    }
}

static void extract_data(char line[], char key[], char data[])
/* line から key と data を抽出する*/
{
    assert(line != NULL);
    assert(key != NULL);
    assert(data != NULL);
    int k;

    /*  ファイルの1行が長過ぎて line に収容できていないことがないかのチェック */
    /*  line の末尾が改行でない → 1行が長過ぎるのでエラー */
    if (!IS_EOL(line[strlen(line) - 1]))
    {
        fprintf(stderr, "line length exceeded line size\n");
        fprintf(stderr, "line = \"%s\"\n", line);
        exit(1);
    }

    /* 先頭の KEY_LEN 文字が key */
    int p_key = 0;
    for (k = 0; k < KEY_LEN; k++)
    {
        key[k] = line[p_key + k];
    }
    key[k] = '\0';

    /* KEY_LEN+1 文字目以降改行記号までが data */
    int p_data = KEY_LEN + 1;
    for (k = 0; k < DATA_LEN; k++)
    {
        if (IS_EOL(line[p_data + k]))
        {
            break;
        }
        data[k] = line[p_data + k];
    }
    data[k] = '\0';
}

void db_dump(db_t *db)
/* db_t 型変数の全データを出力する */
{
    /* 課題 (8-1) : この関数を完成させよ*/
    int i;
    for (i = 0; i < MAX_RECORDS; i++)
    {
        if (db->record[i].data == NULL)
            printf("[  %d] \n", i);
        else
            printf("[  %d]%s %s\n", i, db->record[i].key, db->record[i].data);
    }
}

char *db_linear_search(db_t *db, char key[])
/* 線形探索 */
{
    int i;
    for (i = 0; i < MAX_RECORDS; i++)
        if (strcmp(db->record[i].key, key) == 0)
            return db->record[i].data;
    return NULL;
}

char *db_binary_search(db_t *db, char key[])
/* 二分探索 */
{
    int low = 0;
    int high = db->n - 1;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (strcmp(db->record[mid].key, key) == 0)
            return db->record[mid].data;
        else if (strcmp(db->record[mid].key, key) < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return NULL;
}

int db_hash_f(char key[])
/* ハッシュ関数 */
{
    int i;
    int v = 0;
    for (i = 0; key[i] != '\0'; i++)
    {
        v = (v << 5) + (key[i] - 'A');
    }
    return v % MAX_RECORDS;
}

void db_hash_load(db_t *db)
/* データを読み込む (ハッシュ用) */
{
    FILE *fp;
    char line[LINE_LEN + 1];
    char key[KEY_LEN + 1];
    char data[DATA_LEN + 1];

    /* ファイルのオープン */
    if ((fp = fopen(IATA_F, "r")) == NULL)
    {
        fprintf(stderr, "ファイル (%s) が開けません\n", IATA_F);
        exit(1);
    }

    /* データの読み込み */
    while (fgetss(line, LINE_LEN, fp) != NULL)
    {
        /* 入力データ数が収容可能最大レコード数を超えたらエラー */
        if (MAX_RECORDS <= db->n)
        {
            fprintf(stderr, "MAX_RECORDS(%d) <= n(%d)\n", MAX_RECORDS, db->n);
            exit(1);
        }
        /* line から key と data を切り出す */
        extract_data(line, key, data);
        /*  n 番目 (db->n 番目) の要素を db->record の h 番目に格納し配列の h 番目に既にデータが格納されていれば, 空きが見つかるまで 1 ずつ増やす */
        int h = db_hash_f(key);
        while (strcmp(db->record[h].key, "") != 0)
        {
            h++;
            if (h == MAX_RECORDS)
                h = 0;
        }
        record_set(&db->record[h], key, data);
        db->n++;
    }
    fclose(fp);
}

char *db_hash_search(db_t *db, char key[])
/* ハッシュによる探索 */
{
    int h = db_hash_f(key);
    while (strcmp(db->record[h].key, "") != 0)
    {
        if (strcmp(db->record[h].key, key) == 0)
            return db->record[h].data;
        h++;
        if (h == MAX_RECORDS)
            h = 0;
    }
    return NULL;
}