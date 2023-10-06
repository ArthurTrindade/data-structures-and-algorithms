#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

bst_t* 
bst_new() {
    bst_t *b = NULL;
    b = (bst_t*) malloc(sizeof(bst_t));

    if (b != NULL) {
        b->root = NULL;
    }

    return b;
}

bnode_t* 
create_node(int data) {
    bnode_t *bnode = NULL;
    bnode = (bnode_t*) malloc(sizeof(bnode_t));

    if (bnode != NULL) {
        bnode->data = data;
        bnode->left = NULL;
        bnode->right = NULL;
    }

    return bnode;
}

void 
bst_insert_interative(bst_t *bst, int data) {
    bnode_t *root = bst->root;
    bnode_t *prev = NULL;

    bnode_t *new_node = create_node(data);

    while (root != NULL) {
        prev = root;
        if (data < root->data) {
            root = root->left;
        } else {
            root = root->right;
        }
    }

    if (prev == NULL) {
        bst->root = new_node;
    } else if (data < prev->data) {
        prev->left = new_node;
    } else {
        prev->right = new_node;
    }
}

void 
bst_insert_recursive(bnode_t *root, int data) {
    if (root == NULL) {
        root = create_node(data);
    } else if (data < root->data) {
        bst_insert_recursive(root->left, data);
    } else {
        bst_insert_recursive(root->right, data);
    }
}

void bst_postorder(bnode_t *root) {
    if (root != NULL) {
        bst_postorder(root->left);
        printf("%d ", root->data);
        bst_postorder(root->right);
    }
}