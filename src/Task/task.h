#ifndef _TASK_H_
#define _TASK_H_

typedef struct task task_t;

#include <stdio.h>
#define DESCRIPTION_SIZE 1024

task_t *new_task();
void delete_task(task_t *task);
void set_status(task_t *task, char status);
void set_description(task_t *task, char *description);
char get_status(task_t *task);
char *get_description(task_t *task);
void write_task(task_t *task, FILE *file);
void list_tasks(FILE *file);
void get_status_from_file(task_t *task_ptr, FILE *file);
void get_description_from_file(task_t *task_ptr, FILE *file);
task_t *get_tasks_from_file(FILE *file);
void list_tasks(FILE *file);

#endif // _TASK_H_
