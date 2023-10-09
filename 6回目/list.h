typedef struct list_node_s
{
    int val;
    struct list_node_s *next;
} list_node_t;

void list_print(list_node_t *list);
list_node_t *create_node(int val);
list_node_t *list_insert(list_node_t *list, int val);
list_node_t *list_find(list_node_t *list, int val);
list_node_t *list_insert_uniq(list_node_t *list, int val);
list_node_t *list_insert_delete_dup(list_node_t *list, int val);
list_node_t *list_insert_delete_dup2(list_node_t *list, int val);
list_node_t *list_sorted_insert_uniq(list_node_t *list, int val);
list_node_t *list_sorted_insert_uniq2(list_node_t *list, int val);
list_node_t *list_sorted_find(list_node_t *list, int val);
void list_delete(list_node_t *head_p);