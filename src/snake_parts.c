#include "snake_parts.h"

// Move the apple randomly within boundaries of width and height
void mv_apple(Part_t* apple, short player_points) {
    apple->x = rand() % (WIDTH - 4);
    apple->y = rand() % (HEIGHT - 4);
    
    player_points++;
}

// Move the snake with respect to the direction
int8_t mv_snake(WINDOW *win, Direction curr_dir, Snake_t* snake, Part_t* apple, short player_points) {
    wclear(win);

    mvwaddch(win, apple->y, apple->x, 'o');

    mvwaddch(win, snake->head.y, snake->head.x, '@');


    for (int i = 0; i < StackCapacity(snake); i++) {
        mvwaddch(win, snake->body[i].y, snake->body[i].x, '*');
    }


    int curr_x = snake->body[snake->top].x;
    int curr_y = snake->body[snake->top].y; 

    switch (curr_dir) {
        case UP:

            curr_y - 1 == 0 ? curr_y = HEIGHT - 2 : curr_y--;
            break;
        case DOWN:

            curr_y + 1 == HEIGHT - 1 ? curr_y = 1 : curr_y++;
            break;
        case RIGHT:

            curr_x + 1 == WIDTH - 1 ? curr_x = 1 : curr_x++;
            break;
        case LEFT:

            curr_x - 1 == 0 ? curr_x = WIDTH - 2 : curr_x--;
            break;
        default:
            break;
    }

    
    snake->body[snake->top].x = curr_x;
    snake->body[snake->top].y = curr_y;


    if ((snake->head.x == apple->x) && (snake->head.y == apple->y))
        mv_apple(apple, player_points);


    mvwaddch(win, snake->body[snake->top].y, snake->body[snake->top].x, '*');

    box(win, 0, 0);

    wrefresh(win);

    return 0;
}
