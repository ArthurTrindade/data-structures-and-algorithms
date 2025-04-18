#include "dlist.h"
#include <stdlib.h>
#include <string.h>

void dlist_init(dlist_t *list, void (*destroy)(void *)) {
  list->size = 0;
  list->destroy = destroy;
  list->head = NULL;
  list->tail = NULL;

  return;
}

void dlist_destroy(dlist_t *list) {
  /* void *data; */
  dnode_t *aux = dlist_head(list);

  while (dlist_size(list) > 0) {
    if (dlist_remove(list, aux) == 0) {
      aux = aux->next;
    }
  }

  /* while (dlist_size(list) > 0) { */
  /*   if (dlist_remove(list, dlist_tail(list)) == 0 && list->destroy != NULL) {
   */
  /*     list->destroy(data); */
  /*   } */
  /* } */

  memset(list, 0, sizeof(dlist_t));

  return;
}

int dlist_insert_next(dlist_t *list, dnode_t *element, const void *data) {
  dnode_t *new_element;

  if (element == NULL && dlist_size(list) != 0)
    return -1;

  if ((new_element = (dnode_t *)malloc(sizeof(dnode_t))) == NULL)
    return -1;

  new_element->data = (void *)data;

  if (dlist_size(list) == 0) {
    list->head = new_element;
    list->head->prev = NULL;
    list->head->next = NULL;
    list->tail = NULL;
  } else {
    new_element->next = element->next;
    new_element->prev = element;

    if (element->next == NULL) {
      list->tail = new_element;
    } else {
      element->next->prev = new_element;
    }

    element->next = new_element;
  }

  list->size++;

  return 0;
}

int dlist_insert_prev(dlist_t *list, dnode_t *element, const void *data) {
  dnode_t *new_element;

  if (element == NULL && dlist_size(list) != 0)
    return -1;

  if ((new_element = (dnode_t *)malloc(sizeof(dnode_t))) == NULL)
    return -1;

  new_element->data = (void *)data;

  if (dlist_size(list) == 0) {
    list->head = new_element;
    list->head->prev = NULL;
    list->head->next = NULL;
    list->tail = NULL;
  } else {
    new_element->next = element;
    new_element->prev = element->prev;

    if (element->prev == NULL) {
      list->head = new_element;
    } else {
      element->prev->next = new_element;
    }

    element->prev = new_element;
  }

  list->size++;

  return 0;
}

int dlist_remove(dlist_t *list, dnode_t *element) {

  if (element == NULL || dlist_size(list) == 0)
    return -1;

  void *data = element->data;

  if (element == list->head) {
    list->head = element->next;
    if (list->head == NULL)
      list->tail = NULL;
    else
      element->next->prev = NULL;
  } else {
    element->prev->next = element->next;

    if (element->next == NULL)
      list->tail = element->prev;
    else
      element->next->prev = element->prev;
  }

  list->destroy(data);

  free(element);

  list->size--;

  return 0;
}

int dlist_insert_begin(dlist_t *list, void *data) {
  return dlist_insert_prev(list, list->head, data);
}

int dlist_insert_end(dlist_t *list, void *data) {
  return dlist_insert_next(list, list->tail, data);
}

int dlist_remove_begin(dlist_t *list) { return dlist_remove(list, list->head); }

int dlist_remove_last(dlist_t *list) { return dlist_remove(list, list->tail); }
