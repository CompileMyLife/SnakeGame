#ifndef __SNAKE_WORLD_H
#define __SNAKE_WORLD_H
#include <stdlib.h>

#include <ncurses.h>

#include "stack.h"
#include "world.h"

#define INIT_SNAKE_LEN 1

void isWin(WINDOW* win, Snake_t* snake, short displayPoints);

void isCollide(WINDOW* win, Snake_t* snake, short displayPoints);

#endif // __SNAKE_WORLD_H
