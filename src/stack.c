#include "stack.h"

// Create the Snake Stack
Snake_t* CreateStack(uint8_t capacity, int8_t head_x_pos, int8_t head_y_pos) {
    Snake_t* snake = (Snake_t*) malloc(sizeof(Snake_t));

    // Check IF memory allocation failed
    if (!snake)
        return NULL;

    snake->top      = -1;
   
    if (capacity == 0) {
        snake->top      = -1;
        snake->capacity = capacity;
        return snake;
    }


    for (int i = 0; i < capacity; i++) 
        snake->top += 1;

    snake->capacity = capacity;
    snake->body     = (Part_t*) malloc(capacity * sizeof(Part_t));

    // Check IF memory allocation failed
    if (!snake->body)
        return NULL;

    snake->head.x = head_x_pos;
    snake->head.y = head_y_pos;

    return snake;
}

// Return the current Snake Stack's length
uint8_t StackCapacity(Snake_t* snake) {
    return (snake->top + 1);
}

// Return TRUE IF the Snake Stack's index reached end of body ELSE FALSE
bool StackIsFull(Snake_t* snake) { 
    if (snake->top == (snake->capacity - 1))
        return true;
    else 
        return false;
}

// Return TRUE IF the Snake Stack's index is -1 ELSE FALSE
bool StackIsEmpty(Snake_t* snake) {
    if (snake->top == -1)
        return true;
    else
        return false;
}

// Push onto the Snake Stack with coordinates
void StackPush(Snake_t* snake, int8_t x, int8_t y) {
    if (StackIsFull(snake)) {
        snake->capacity++;
        snake->body = realloc(snake->body, snake->capacity * sizeof(Part_t));
    }
    snake->top++;
    snake->body[++snake->top].x = x;
    snake->body[++snake->top].y = y;
}

// Pop from the Snake Stack
Part_t StackPop(Snake_t* snake) {
       if (StackIsEmpty(snake)) return;

       else {
           snake->top--;
           return (snake->body[snake->top+1]);
       }
}

// Delete the Snake Stack
void DeleteStack(Snake_t* snake) {
    if (snake) {
        if (snake->body) {
            free(snake->body);
            free(snake);

            snake = NULL;
        }
    }
}
