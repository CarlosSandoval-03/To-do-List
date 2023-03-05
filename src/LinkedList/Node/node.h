#ifndef _NODE_H_
#define _NODE_H_

#include "../../Task/task.h"

typedef struct node {
  task_t *task;
  struct node *prev;
  struct node *next;
} node_t;

node_t *new_node();
void delete_node(node_t *node_ptr);

#endif // _NODE_H_
