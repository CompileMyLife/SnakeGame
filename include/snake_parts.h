#ifndef __SNAKE_PARTS_H
#define __SNAKE_PARTS_H

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#include <ncurses.h>

#include "stack.h"
#include "snake_world.h"
#include "world.h"

// Keyboard Arrow Directions from 0-3
typedef enum _direction {UP, DOWN, LEFT, RIGHT} Direction;

// Move the apple randomly within boundaries of width and height
void mv_apple(Part_t* apple, short player_points);

// Move the snake with respect to the direction
int8_t mv_snake(WINDOW *win, Direction curr_dir, Snake_t* snake, Part_t* apple, short player_points);

#endif //__SNAKE_PARTS_H
