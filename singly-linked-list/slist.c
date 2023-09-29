#include <stdio.h>
#include <stdlib.h>

#include "slist.h"

slist_t* slist_init() {
    slist_t *s = NULL;
    s = (slist_t*) malloc(sizeof(slist_t));

    if (s != NULL) {
        s->size = 0;
        s->head = NULL;
        s->tail = NULL;
    }
    
    return s;
}

void slist_init2(slist_t *slist) {
    if (slist != NULL) {
        slist->size = 0;
        slist->head = NULL;
        slist->tail = NULL;
    }
}

snode_t* create_node(int data) {
    snode_t *snode = NULL;
    snode = (snode_t*) malloc(sizeof(snode_t));

    if (snode != NULL) {
        snode->data = data;
        snode->next = NULL;
    }

    return snode;
}

void slist_free(slist_t *slist) {

    if (slist == NULL) {
        return;
    }

    snode_t *aux = NULL;
    aux = slist->head;
    snode_t *temp;

    while (aux != NULL) {
        temp = aux;
        aux = aux->next;
        free(temp);
    }

    free(slist);
}

void slist_free2(slist_t *slist) {

    if (slist == NULL) {
        return;
    }

    snode_t *aux = NULL;
    aux = slist->head;
    snode_t *temp;

    while (aux != NULL) {
        temp = aux;
        aux = aux->next;
        free(temp);
    }

    free(slist);
}

int slist_insert_next(slist_t *slist, snode_t *snode, int data) {
    snode_t *new_node = create_node(data);

    if (slist == NULL) {
        return EXIT_FAILURE;
    }

    if (snode == NULL) {

        if (slist->size == 0) {
            slist->tail = new_node;
        }

        new_node->next = slist->head;
        slist->head = new_node;

    } else {

        if (snode->next == NULL) {
            slist->tail = new_node;
        }

        new_node->next = snode->next;
        snode->next = new_node;
    }

    slist->size++;

    return EXIT_SUCCESS;
} 


int slist_insert_begin(slist_t *slist, int data) {
    return slist_insert_next(slist, NULL, data);
}

int slist_insert_end(slist_t *slist, int data) {
    return slist_insert_next(slist, slist->tail, data);
}

int slist_insert_next2(slist_t *slist, snode_t *snode, int data) {
    snode_t *new_node = create_node(data);

    if (slist ==  NULL) {
        return EXIT_FAILURE;
    }

    if (snode == NULL) {
        new_node->next = slist->head;
        slist->head = new_node;
    } else {
        new_node->next = snode->next;
        snode->next = new_node;
    }

    slist->size++;

    return EXIT_SUCCESS;
}

int slist_insert_end2(slist_t *slist, int data) {
    snode_t *aux = slist->head;

    while (aux->next != NULL) {
        aux = aux->next;
    }

    return slist_insert_next2(slist, aux, data);
}
