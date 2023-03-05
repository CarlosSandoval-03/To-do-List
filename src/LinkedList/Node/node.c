#include <stdio.h>
#include <stdlib.h>
#include "./node.h"

node_t *new_node() {
  return malloc(sizeof(node_t));
}

void delete_node(node_t *node_ptr) {
  free(node_ptr);
}
