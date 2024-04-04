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

    snake->body[snake->top].x = snake->head.x;
    snake->body[snake->top].y = snake->head.y;

    if (snake->top != 0) {
        for (int i = 0; i < snake->top - 1; i++) {
            snake->body[i].x = snake->body[i + 1].x;
            snake->body[i].y = snake->body[i + 1].y;
            mvwaddch(win, snake->body[i].y, snake->body[i].x, '*');
        }
    }

    else { 
        mvwaddch(win, snake->body[snake->top].y, snake->body[snake->top].x, '*');
    }

    mvwaddch(win, snake->head.y, snake->head.x, '@');
    int8_t curr_hx = snake->head.x;
    int8_t curr_hy = snake->head.y; 

    switch (curr_dir) {
        case UP:

            curr_hy - 1 == 0 ? curr_hy = HEIGHT - 2 : curr_hy--;
            //for (int i = 0; i < snake->top + 1; i++) {
            //    snake->body[i].y = (curr_hy + i + 1);
            //} 
            break;
        case DOWN:

            curr_hy + 1 == HEIGHT - 1 ? curr_hy = 1 : curr_hy++;

            //for (int i = 0; i < snake->top + 1; i++) {
            //    snake->body[i].y = (curr_hy + i + 1);
            //}
            break;
        case RIGHT:

            curr_hx + 1 == WIDTH - 1 ? curr_hx = 1 : curr_hx++;
            //for (int i = 0; i < snake->top + 1; i++) {
            //    snake->body[i].x = (curr_hx + i + 1);
            //}
            break;
        case LEFT:

            curr_hx - 1 == 0 ? curr_hx = WIDTH - 2 : curr_hx--;
            //for (int i = 0; i < snake->top + 1; i++) {
            //    snake->body[i].x = (curr_hx - i - 1);
            //}
            break;
        default:
            break;
    }

    
    snake->head.x = curr_hx;
    snake->head.y = curr_hy;

    if ((snake->head.x == apple->x) && (snake->head.y == apple->y)) {
        mv_apple(apple, player_points);
        StackPush(snake, snake->head.x, snake->head.y);  
    }
    
    //for (int i = 0; i < snake->top + 1; i++) {
     //   mvwaddch(win, snake->body[i].y, snake->body[i].x, '*');
    //}

    box(win, 0, 0);

    wrefresh(win);

    return 0;
}
