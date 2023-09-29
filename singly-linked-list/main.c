#include <stdio.h>
#include <stdlib.h>

#include "slist.h"

void print_list(slist_t *list) {
    snode_t *node = list->head;
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {

    slist_t slist;
    slist_init2(&slist);

    slist_insert_next(&slist, NULL, 10);
    slist_insert_next(&slist, NULL, 20);
    slist_insert_end2(&slist, 30);

    print_list(&slist);

    slist_free2(&slist);

    return 0;
}