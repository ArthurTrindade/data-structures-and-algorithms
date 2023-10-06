#include <stdio.h>

#include "bst.h"

int main() {

    bst_t *b = bst_new();

    bst_insert_recursive(b->root, 10);

    bst_postorder(b->root);

    // printf("%d\n", b->root->data);

    return 0;
}