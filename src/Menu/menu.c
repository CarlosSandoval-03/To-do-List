#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Utils/utils.h"
#include "../Task/task.h"
#include "../File/file.h"
#include "menu.h"

void main_menu() {
  int option;
  do {
	printf("Select an option:\n1.Add task\n2.Mark as completed\n3.Remove Task\n4.Edit task\n5.Exit\nOption: ");
	scanf("%d", &option);

	while (getchar() != '\n'); // Clear buffer
	printf("\n");
  } while (option < 1 || option > 5);

  switch (option) {
	case 1: add_task_menu();
	  break;
	case 2:
	  remove_task();
	  break;
	case 3: break;
	case 4: break;
	case 5: return;
	default: raise_error("MENU: Non-existent option");
	  break;
  }
}

void add_task_menu() {
  char status = '0';
  char description[DESCRIPTION_SIZE];
  task_t *task_ptr = new_task();

  printf("Enter the description of the task: ");
  fgets(description, DESCRIPTION_SIZE, stdin);
  description[strcspn(description, "\r\n")] = 0; // Clear \n

  set_status(task_ptr, status);
  set_description(task_ptr, description);

  FILE *file = open_file("./data/data.txt", "a");
  write_task(task_ptr, file);
  fclose(file);
  printf("Added task\n");

  main_menu(); // Return to main menu
}

void remove_task() {
  FILE *file = open_file("./data/data.txt", "r");

  list_tasks(file);

  fclose(file);
}
