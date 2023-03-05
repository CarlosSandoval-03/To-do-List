#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include "./Node/node.h"

typedef struct linked_list {
  node_t *head;
  node_t *tail;
  int size;
} list_t;

list_t *new_list();
int is_empty(list_t *list);
void print_list(list_t *list);
void push_front(list_t *list, node_t *data);
node_t *top_front(list_t *list);
void pop_front(list_t *list);
void push_back(list_t *list, node_t *data);
node_t *top_back(list_t *list);
void pop_back(list_t *list);
void delete_list(list_t *list);

#endif // _LINKED_LIST_H_
