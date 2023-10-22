typedef struct tree_node_s
{
    struct tree_node_s *left;
    struct tree_node_s *right;
    int data;
} tree_node_t;

void tree_print(tree_node_t *root);
tree_node_t *tree_insert(tree_node_t *root, int v);
tree_node_t *tree_insert_uniq(tree_node_t *root, int v);
tree_node_t *tree_find(tree_node_t *root, int v);
void tree_delete(tree_node_t *root);