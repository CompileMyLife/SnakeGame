CC = gcc
CFLAGS = -std=gnu99 -Wall -ggdb
LDFLAGS = -lncurses

# Directories
SRC_DIR = ./src
INC_DIR = ./include
OBJ_DIR = ./obj

# If any files names 'all', 'default', and/or 'clean', make will ignore and use
# the below targets instead
.PHONY = all default clean

all: ClassicSnake

help:
	@echo "Options:"
	@echo ""
	@echo "all:              Executes all targets"
	@echo "ClassicSnake:     Game executable"
	@echo "clean:            Clean up"

ClassicSnake: $(SRC_DIR)/main.c $(OBJ_DIR)/stack.o $(OBJ_DIR)/snake_parts.o $(OBJ_DIR)/snake_world.o
	$(CC) $(CFLAGS) -I $(INC_DIR) $^ -o $@ $(LDFLAGS)

$(OBJ_DIR)/snake_parts.o: $(SRC_DIR)/snake_parts.c $(INC_DIR)/snake_parts.h $(INC_DIR)/stack.h $(INC_DIR)/snake_world.h
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(OBJ_DIR)/snake_world.o: $(SRC_DIR)/snake_world.c $(INC_DIR)/snake_world.h
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(OBJ_DIR)/stack.o: $(SRC_DIR)/stack.c $(INC_DIR)/stack.h
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@
clean:
	rm -rf ./ClassicSnake ./ClassicSnake.dSYM/ $(OBJ_DIR)/*.o 
