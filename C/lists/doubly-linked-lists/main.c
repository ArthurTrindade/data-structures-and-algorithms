#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct symbol_t {
  int type;
  char *lexeme;
} symbol_t;

symbol_t *new_symbol(int type, char *lexema) {
  symbol_t *symbol = (symbol_t *)malloc(sizeof(symbol_t));
  symbol->type = type;
  symbol->lexeme = lexema;

  return symbol;
}

void free_symbol(symbol_t *symbol) { free(symbol); }

void print_symbol(symbol_t *s) {
  printf("Type: %d\nLexeme: %s\n", s->type, s->lexeme);
}

symbol_t *get_symbol(list_t *list, char *lexeme) {
  symbol_t *s;
  node_t *aux = list_head(list);

  for (int i = 0; i <= list_size(list); i++) {
    s = list_data(aux);

    if (strcmp(s->lexeme, lexeme) == 0) {
      return s;
    }

    aux = aux->next;
  }

  return NULL;
}

int main() {

  list_t list;
  list_init(&list, free);

  symbol_t *s1 = new_symbol(1, "x");
  symbol_t *s2 = new_symbol(1, "y");

  printf("List size: %d\n", list_size(&list));

  list_insert_begin(&list, s1);

  printf("List size: %d\n", list_size(&list));

  list_insert_begin(&list, s2);

  printf("List size: %d\n", list_size(&list));

  /* list_remove(&list, list.head); */

  /* printf("List size: %d\n", list_size(&list)); */

  print_symbol(list_data(list.head));

  print_symbol(list_data(list.head->next));

  printf("\n");

  symbol_t *s3 = get_symbol(&list, "y");

  print_symbol(s3);

  list_destroy(&list);

  printf("List size: %d\n", list_size(&list));

  return 0;
}
