#ifndef DLIST_H
#define DLIST_H

#include <stdio.h>

typedef struct dnode_t {
  void *data;
  struct dnode_t *prev;
  struct dnode_t *next;
} dnode_t;

typedef struct dlist_t {
  int size;
  int (*match)(const void *key1, const void *key2);
  void (*destroy)(void *data);
  dnode_t *head;
  dnode_t *tail;
} dlist_t;

/**
 * Inicializa uma lista duplamente ligada especificada de lista
 * o arg destroy providencia uma maneira de liberar dinamicamente a memoria
 * quando dlist_destroy for chamada
 * return NONE
 */
void dlist_init(dlist_t *list, void (*destroy)(void *data));

/**
 * Destroi a lista duplamente ligada, usando a função destry

 */
void dlist_destroy(dlist_t *list);

/*
 *
 * return 0 se a element foi inserido com sucesso, ou -1 caso contrário
 * */
int dlist_insert_next(dlist_t *list, dnode_t *element, const void *data);

/*
 * return 0 se o elemento foi inserido com sucesso, ou -1 caso contrário
 * */
int dist_insert_prev(dlist_t *list, dnode_t *element, const void *data);

/**
 * return 0 se o elemento foi removido com sucesso, ou -1 caso contrário
 */
int dlist_remove(dlist_t *list, dnode_t *element);

int dlist_insert_begin(dlist_t *list, void *data);

int dlist_insert_end(dlist_t *list, void *data);

int dlist_remove_begin(dlist_t *list);

int dlist_remove_last(dlist_t *list);

#define dlist_size(list) ((list)->size)
#define dlist_head(list) ((list)->head)
#define dlist_tail(list) ((list)->tail)
#define dlist_is_head(element) ((element)->prev == NULL ? 1 : 0)
#define dlist_is_tail(element) ((element)->next == NULL ? 1 : 0)
#define dlist_data(element) ((element)->data)
#define dlist_next(element) ((element)->next)
#define dlist_prev(element) ((element)->prev)

#endif // !DLIST_H
