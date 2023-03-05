#ifndef _FILE_H_
#define _FILE_H_

#include <stdio.h>

FILE *open_file(char *path_to_file, char *mode);
void write_buffer(FILE *file, char *buffer, int num_elements);

#endif // _FILE_H_
