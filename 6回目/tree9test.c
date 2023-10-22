#include <stdio.h>
#include "tree.h"

int main(void)
{
    tree_node_t *root = NULL;

    for (;;)
    {
        int data;
        fprintf(stderr, "input = ");
        if (scanf("%d", &data) == EOF)
        {
            break;
        }
        root = tree_insert_uniq(root, data);
        printf("[");
        tree_print(root);
        printf(" ]\n");
    }

    tree_delete(root);
    return 0;
}