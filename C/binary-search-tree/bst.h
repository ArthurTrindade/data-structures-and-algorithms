#ifndef BST_H
#define BST_H

typedef struct bnode_t {
    int data;   
    struct bnode_t *left;
    struct bnode_t *right;
} bnode_t;

typedef struct bst_t {
    bnode_t *root;
} bst_t;

bst_t* bst_new();
bnode_t* create_node(int data);
void bst_insert_interative(bst_t *bst, int data);
void bst_insert_recursive(bnode_t *root, int data);
void bst_postorder(bnode_t *root);

#endif
