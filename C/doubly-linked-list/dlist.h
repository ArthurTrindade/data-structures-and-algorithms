#include <stdlib.h>

typedef struct dnode {
    int data;
    struct dnode *next;
    struct dnode *prev;
} dnode_t;

typedef struct dlist {
    size_t size;
    dnode_t *head;
    dnode_t *tail;
} dlist_t;

dlist_t* dlist_init();
void dlist_destroy(dlist_t *dlist);
dnode_t* dnode_create(int data);
int dlist_insert_next(dlist_t *dlist, dnode_t *node, int data);
int dlist_insert_prev(dlist_t *dlist, dnode_t *node, int data);
int dlist_insert_begin(dlist_t *dlist, int data);
int dlist_insert_end(dlist_t *dlist, int data);
int dlist_remove(dlist_t *dlist, dnode_t *node);
int dlist_remove_begin(dlist_t *dlist);
int dlist_remove_end(dlist_t *dlist);
