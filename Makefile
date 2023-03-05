CC = gcc
CFLAGS = -Wall -g -pedantic
SRC_DIR = ./src
BIN_DIR = ./bin
OBJ_DIR = ./obj
DATA_DIR = ./data
MAIN_DEPENDENCIES = $(SRC_DIR)/Menu/menu.h \
	$(SRC_DIR)/main.c $(OBJ_DIR)/menu.o $(OBJ_DIR)/file.o $(OBJ_DIR)/task.o $(OBJ_DIR)/utils.o $(OBJ_DIR)/linked_list.o \
	$(OBJ_DIR)/node.o


build: create_obj_dir create_bin_dir $(BIN_DIR)/main
	@echo Building...

$(BIN_DIR)/main: $(MAIN_DEPENDENCIES)
	@$(CC) $(CFLAGS) -o $(BIN_DIR)/main $(OBJ_DIR)/menu.o $(OBJ_DIR)/file.o $(OBJ_DIR)/task.o $(OBJ_DIR)/utils.o \
 	$(OBJ_DIR)/linked_list.o $(OBJ_DIR)/node.o $(SRC_DIR)/main.c

$(OBJ_DIR)/menu.o: $(SRC_DIR)/Menu/menu.h $(SRC_DIR)/File/file.h $(SRC_DIR)/Task/task.h $(SRC_DIR)/Utils/utils.h \
	$(SRC_DIR)/Menu/menu.c
	@$(CC) $(CFLAGS) -o $(OBJ_DIR)/menu.o -c $(SRC_DIR)/Menu/menu.c

$(OBJ_DIR)/file.o: $(SRC_DIR)/Utils/utils.h $(SRC_DIR)/File/file.h $(SRC_DIR)/File/file.c
	@$(CC) $(CFLAGS) -o $(OBJ_DIR)/file.o -c $(SRC_DIR)/File/file.c

$(OBJ_DIR)/task.o: $(SRC_DIR)/Task/task.h $(SRC_DIR)/LinkedList/linked_list.h $(SRC_DIR)/Task/task.c \
	$(SRC_DIR)/LinkedList/Node/node.h
	@$(CC) $(CFLAGS) -o $(OBJ_DIR)/task.o -c $(SRC_DIR)/Task/task.c

$(OBJ_DIR)/utils.o: $(SRC_DIR)/Utils/utils.h $(SRC_DIR)/Utils/utils.c
	@$(CC) $(CFLAGS) -o $(OBJ_DIR)/utils.o -c $(SRC_DIR)/Utils/utils.c

$(OBJ_DIR)/linked_list.o: $(SRC_DIR)/LinkedList/linked_list.h $(SRC_DIR)/Task/task.h $(SRC_DIR)/LinkedList/Node/node.h \
	$(SRC_DIR)/LinkedList/linked_list.c $(OBJ_DIR)/node.o
	@$(CC) $(CFLAGS) -o $(OBJ_DIR)/linked_list.o -c $(SRC_DIR)/LinkedList/linked_list.c

$(OBJ_DIR)/node.o: $(SRC_DIR)/LinkedList/Node/node.h $(SRC_DIR)/Task/task.h $(SRC_DIR)/LinkedList/Node/node.c
	@$(CC) $(CFLAGS) -o $(OBJ_DIR)/node.o -c $(SRC_DIR)/LinkedList/Node/node.c

# Build dirs
create_bin_dir:
	$(shell mkdir -p $(BIN_DIR))

create_obj_dir:
	$(shell mkdir -p $(OBJ_DIR))

.PHONY: clean_obj clean_data clean_bin clean clean_all
clean_obj:
	rm -rf $(OBJ_DIR)/*

clean_data:
	rm -rf $(DATA_DIR)/*

clean_bin:
	rm -rf $(BIN_DIR)/*

clean: clean_bin clean_obj

clean_all: clean clean_data
