#ifndef __STACK_H
#define __STACK_H

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

// Coordinates
typedef struct {
    int8_t  x;
    int8_t  y;
} Part_t, *PartPtr;

// Stack
typedef struct {
    int8_t   top;
    uint8_t  capacity;
    Part_t   head;
    Part_t*  body;
} Snake_t, *SnakePtr;

// Create the Snake Stack
Snake_t* CreateStack(uint8_t capacity, int8_t head_x_pos, int8_t head_y_pos);

// Return the current Snake Stack's length
uint8_t StackCapacity(Snake_t* snake);

// Return TRUE IF the Snake Stack's index is same as capacity ELSE FALSE
bool StackIsFull(Snake_t* snake);

// Return TRUE IF the Snake Stack's index is -1 ELSE FALSE
bool StackIsEmpty(Snake_t* snake);

// Push onto the Snake Stack with coordinates
void StackPush(Snake_t* snake, int8_t x, int8_t y);

// Pop from the Snake Stack
Part_t StackPop(Snake_t* snake);

// Delete the Snake Stack
void DeleteStack(Snake_t* snake);

#endif // __STACK_H
