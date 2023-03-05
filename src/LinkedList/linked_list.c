#include <stdio.h>
#include <stdlib.h>
#include "../Task/task.h"
#include "./Node/node.h"
#include "./linked_list.h"

list_t *new_list() {
  list_t *list = malloc(sizeof(list_t));
  list->size = 0;
  return list;
}

int is_empty(list_t *list) {
  return list->size == 0;
}

void print_list(list_t *list) {
  if (is_empty(list)) {
	printf("ERROR: EMPTY LIST");
	return;
  }

  node_t *data = list->head;
  for (int i = 0; i < list->size; i++) {
	printf("%s\n", get_description(data->task));
  }
}

void push_front(list_t *list, node_t *data) {
  data->next = list->head;
  list->head = data;

  if (list->tail == NULL) {
	list->tail = list->head;
  }
  list->size++;
}

node_t *top_front(list_t *list) {
  return list->head;
}

void pop_front(list_t *list) {
  if (is_empty(list)) {
	return;
  }
  list->head = list->head->next;

  if (list->head == NULL) {
	list->tail = NULL;
  }
  list->size--;
}

void push_back(list_t *list, node_t *data) {
  if (list->tail == NULL) {
	list->tail = data;
	list->head = list->tail;
  } else {
	list->tail->next = data;
	data->prev = list->tail;
	list->tail = data;
  }
  list->size++;
}

node_t *top_back(list_t *list) {
  return list->tail;
}

void pop_back(list_t *list) {
  if (is_empty(list)) {
	return;
  }

  if (list->head == list->tail) {
	list->head = NULL;
	list->tail = list->head;
  } else {
	list->tail = list->tail->prev;
  }
  list->size--;
}

void delete_list(list_t *list) {
  while (list->size > 0) {
	node_t *node_ptr = top_back(list);
	delete_node(node_ptr);
	pop_back(list);
  }
  free(list);
}
