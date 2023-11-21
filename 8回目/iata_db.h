/*
  次の行の __USE_MINI__ が定義されていると iata_mini.csv が,
  次の行がコメントアウトされていると iata_data.csv が使われる
*/
// #define __USE_MINI__

#ifdef __USE_MINI__
/* テスト版の定義 */
#define IATA_F "iata_mini.csv" /* 空港データのファイル */
#define MAX_RECORDS 16         /* レコード数の上限 */
#else
/* フルセット版の定義 */
#define IATA_F "iata_data.csv" /* 空港データのファイル */
#define MAX_RECORDS 6000       /* レコード数の上限 */
#endif

#define KEY_LEN 3                             /* 空港コード (キー) の文字数 */
#define KEY_FMT "%3s"                         /* 空港コード (キー) の入力用フォーマット */
#define DATA_LEN 127                          /* 空港データの最大文字数 */
#define LINE_LEN (KEY_LEN + 1 + DATA_LEN + 1) /* 1行の最大文字数 */

/* 1 レコードのデータ */
typedef struct
{
  char key[KEY_LEN + 1]; /* 空港コード (キー) */
  char *data;            /* 空港の詳細データ (文字配列) へのポインタ */
} record_t;

/* データベース (全データ) */
typedef struct
{
  int n;                        /* データ (レコード) 数 */
  record_t record[MAX_RECORDS]; /* データ (レコード) の配列 */
} db_t;

void db_init(db_t *db);   /* 初期化 */
void db_load(db_t *db);   /* ファイルからデータを読み込む */
void db_delete(db_t *db); /* データの破棄 */
void db_dump(db_t *db);   /* ダンプ (全データ出力) */

char *db_linear_search(db_t *db, char key[]); /* 線形探索 */
char *db_binary_search(db_t *db, char key[]); /* 二分探索 */

int db_hash_f(char key[]);                  /* ハッシュ関数 */
void db_hash_load(db_t *db);                /* データを読み込む (ハッシュ用) */
char *db_hash_search(db_t *db, char key[]); /* ハッシュによる探索 */