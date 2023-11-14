#define STRLEN 63
#define STRFMT "%63s"

typedef struct
{
    char name[STRLEN + 1];
    int age;
    double height;
} record_t;

void str_sort(int n, record_t *a);