#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task.h"
#include "../LinkedList/linked_list.h"
#include "../LinkedList/Node/node.h"

struct task {
  char status;
  char description[DESCRIPTION_SIZE];
};

task_t *new_task() {
  return malloc(sizeof(task_t));
}

void delete_task(task_t *task) {
  free(task);
}

void set_status(task_t *task, char status) {
  task->status = status;
}

void set_description(task_t *task, char *description) {
  strncpy(task->description, description, DESCRIPTION_SIZE);
}

char get_status(task_t *task) {
  return task->status;
}

char *get_description(task_t *task) {
  return task->description;
}

void write_task(task_t *task, FILE *file) {
  if (task->status == '0') {
	fputs("[ ] ", file);
  } else {
	fputs("[x] ", file);
  }

  fwrite(task->description, sizeof(char), DESCRIPTION_SIZE, file);
  fputc('\n', file);
}

void get_status_from_file(task_t *task_ptr, FILE *file) {
  char buffer[5];
  fgets(buffer, 5, file);
  char status;
  if (strcmp(buffer, "[X] ")) {
	status = '1';
  } else {
	status = '0';
  }
  set_status(task_ptr, status);
}

void get_description_from_file(task_t *task_ptr, FILE *file) {
  char buffer[DESCRIPTION_SIZE];
  fgets(buffer, DESCRIPTION_SIZE, file);

  set_description(task_ptr, buffer);
}

task_t *get_tasks_from_file(FILE *file) {
  task_t *task_ptr = new_task();

  get_status_from_file(task_ptr, file);
  get_description_from_file(task_ptr, file);

  return task_ptr;
}

void list_tasks(FILE *file) {
  list_t *list_ptr = new_list();

  while (!feof(file)) {
	node_t *node_ptr = new_node();
	task_t *task_ptr = get_tasks_from_file(file);

	node_ptr->task = task_ptr;
	push_back(list_ptr, node_ptr);
  }
  printf("Size: %d\n", list_ptr->size);
  print_list(list_ptr);
}
