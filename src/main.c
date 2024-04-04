#include <stdio.h>

#include <ncurses.h>
#include "world.h" 
#include "stack.h"
#include "snake_world.h"
#include "snake_parts.h" 

short playerPoints;

int main(void) {
    WINDOW* snake_world;

    uint8_t offsetx, offsety;
    int ch;
   
    playerPoints = 0;

    initscr();

    noecho();

    cbreak();

    keypad(stdscr, TRUE);

    refresh();

    getch();

    clear();

    timeout(TICK);

    offsetx = (COLS - WIDTH) / 2;
    offsety = (LINES - HEIGHT) / 2;

    snake_world = newwin(HEIGHT, WIDTH, offsety, offsetx);

    Part_t apple;
    SnakePtr snake = CreateStack(INIT_SNAKE_LEN, (WIDTH - INIT_SNAKE_LEN) / 2, (HEIGHT - 1) / 2);

    apple.x = rand() % (WIDTH - 4);
    apple.y = rand() % (HEIGHT - 4);
    
    int snake_begx = (WIDTH - INIT_SNAKE_LEN) / 2 - 1;
    int snake_begy = (HEIGHT - 1) / 2;

    for (int i = INIT_SNAKE_LEN; i > 0; i--) {
        snake->body[i].x = snake_begx - i - 1;
        snake->body[i].y = snake_begy;
    }

    Direction curr_dir = RIGHT;

    while((ch = getch()) != 'q') {
        
        mvprintw(0, 1, "\nApples:%d", playerPoints);

        mv_snake(snake_world, curr_dir, snake, &apple, playerPoints);

        isCollide(snake_world, snake, playerPoints);

        isWin(snake_world, snake, playerPoints);

        if(ch != ERR) {

            switch(ch) {
                case 'w':
                case 'W':
                case KEY_UP:
                

                    if(snake->head.y - 1 == snake->body[snake->top].y){
                        break;
                    }
                    curr_dir = UP;
                    break;
                
                case 's':
                case 'S':
                case KEY_DOWN:
                

                    if(snake->head.y + 1 == snake->body[snake->top].y){
                        break;
                    }
                    curr_dir = DOWN;
                    break;

                case 'a':
                case 'A':
                case KEY_LEFT:
               

                    if(snake->head.x - 1 == snake->body[snake->top].x){
                        break;
                    }
                    curr_dir = LEFT;
                    break;

                case 'd':
                case 'D':
                case KEY_RIGHT:
                

                    if(snake->head.x + 1 == snake->body[snake->top].x){
                        break;
                    }
                    curr_dir = RIGHT;
                    break;

                default:
                    break;
            }
        }
    }

    delwin(snake_world);

    endwin();

    DeleteStack(snake);

    return 0;
}
