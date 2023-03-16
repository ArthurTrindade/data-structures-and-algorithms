#include <stdlib.h>

#include "dlist.h"

dlist_t* 
dlist_init() {
    dlist_t *dlist = NULL;

    dlist = (dlist_t*) malloc(sizeof(dlist_t));

    if (dlist != NULL) {
        dlist->size = 0;
        dlist->head = NULL;
        dlist->tail = NULL;
    }

    return dlist;
}

void
dlist_destroy(dlist_t *dlist) {

    if (dlist == NULL) {
        return;
    }

    dnode_t *node = NULL;
    dnode_t *temp; 
    node = dlist->head;

    while (node != NULL) {
        temp = node;
        node = node->next;
        free(temp);
    }

    free(dlist);
}

dnode_t* dnode_create(int data) {
    dnode_t *dnode = NULL;

    dnode = (dnode_t*) malloc(sizeof(dnode_t));

    if (dnode!= NULL) {
        dnode->data = data;
        dnode->next = NULL;
        dnode->prev = NULL;
    }

    return dnode;
}

int dlist_insert_next(dlist_t *dlist, dnode_t *node, int data) {

    dnode_t *new_node = dnode_create(data);

    if (dlist == NULL) {
        return -1;
    }

    if (dlist->size == 0) {
        dlist->head = new_node;
        dlist->tail = new_node;

    } else {
        new_node->next = node->next;
        new_node->prev = node;

        if (node->next == NULL) {
            dlist->tail = new_node;
        } else {
            node->next->prev = new_node;
        }

        node->next = new_node;
    }

    dlist->size++;

    return 0;
}

int dlist_insert_prev(dlist_t *dlist, dnode_t *node, int data) {

    dnode_t *new_node = dnode_create(data);

    if (dlist == NULL) {
        return -1;
    }

    if (dlist->size == 0) {
        dlist->head = new_node;
        dlist->tail = new_node;
        
    } else {
        new_node->next = node;
        new_node->prev = node->prev;

        if (node->prev == NULL) {
            dlist->head = new_node;
        } else {
            node->prev->next = new_node;
        }

        node->prev = new_node;
    }

    dlist->size++;

    return 0;
}

int dlist_remove(dlist_t *dlist, dnode_t *node) {

    if (node == NULL || dlist->size == 0) {
        return -1;
    }

    if (node == dlist->head) {
        dlist->head = node->next;

        if (dlist->head == NULL) {
            dlist->tail = NULL;
        } else {
            node->next->prev = NULL;
        }

    } else {
        node->prev->next = node->next;

        if (node->next == NULL) {
            dlist->tail = node->prev;
        } else {
            node->next->prev = node->prev;
        }
    }

    free(node);

    dlist->size--;

    return 0;
}

int dlist_insert_begin(dlist_t *dlist, int data) {
    return dlist_insert_prev(dlist, dlist->head, data);
}

int dlist_insert_end(dlist_t *dlist, int data) {
    return dlist_insert_next(dlist, dlist->tail, data);
}

int dlist_remove_begin(dlist_t *dlist) {
    return dlist_remove(dlist, dlist->head);
}

int dlist_remove_end(dlist_t *dlist) {
    return dlist_remove(dlist, dlist->tail);
}