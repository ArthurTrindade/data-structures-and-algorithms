#include <stdio.h>

#include "dlist.h"

void print_list(dlist_t *list) {
    dnode_t *node = list->head;
    printf("NULL");
    while (node != NULL) {
        printf(" <- %d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {

    dlist_t *list = dlist_init();

    dlist_insert_begin(list, 10);
    dlist_insert_begin(list, 20);
    dlist_insert_begin(list, 30);

    dlist_insert_end(list, 40);

    dlist_remove_begin(list);
    dlist_remove_end(list);

    print_list(list);

    dlist_destroy(list);

    return 0;
}