#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main(void)
{
    list_node_t *head_p = create_node(0); /* ヘッダ (ダミー) */

    for (;;)
    {
        int val;
        fprintf(stderr, "input = ");
        if (scanf("%d", &val) == EOF)
        {
            break;
        }
        list_insert_uniq(head_p, val);
        list_print(head_p);
    }
    list_delete(head_p);

    free(head_p);
    return 0;
}