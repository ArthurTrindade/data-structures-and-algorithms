#ifndef SLIST_H
#define SLIST_H

typedef struct snode_t {
    int data;
    struct snode_t *next;
} snode_t;

typedef struct slist_t {
    int size;
    snode_t *head;
    snode_t *tail;
} slist_t;

slist_t* slist_init();
void slist_init2(slist_t *slist);
snode_t* create_node(int data);
void slist_free(slist_t *slist);
int slist_insert_next(slist_t *slist, snode_t *snode, int data);
int slist_insert_next2(slist_t *slist, snode_t *snode, int data);
int slist_insert_begin(slist_t *slist, int data);
int slist_insert_end(slist_t *slist, int data);
int slist_insert_end2(slist_t *slist, int data);


#endif