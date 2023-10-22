#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main(void)
{
    list_node_t *head_p = create_node(0); /* ヘッダ (ダミー) */
    int n;

    fprintf(stderr, "n: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        list_insert_uniq(head_p, myrand_init());
    }
}