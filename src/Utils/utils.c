#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void raise_error(char *message) {
  fprintf(stderr, "%s", message);
  exit(EXIT_FAILURE);
}

void clean_buffer(char *buffer, int buffer_size) {
  strncpy(buffer, "", buffer_size);
}
