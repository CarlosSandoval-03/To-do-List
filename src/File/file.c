#include <stdio.h>
#include <stdlib.h>
#include "../Utils/utils.h"
#include "file.h"

FILE *open_file(char *path_to_file, char *mode) {
  FILE *file = fopen(path_to_file, mode);
  if (file == NULL) {
	raise_error("FILE: An error ocurred while opening the file\n");
  }
  return file;
}

void write_buffer(FILE *file, char *buffer, int num_elements) {
  size_t process_validator = fwrite(buffer, sizeof(char), num_elements, file);
  if (process_validator < num_elements) {
	raise_error("WRITE: An error occurred while writing buffer to the file\n");
  }
  clean_buffer(buffer, num_elements);
}
