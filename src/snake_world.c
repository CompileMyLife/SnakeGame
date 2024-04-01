#include "snake_world.h"

void isWin(WINDOW* win, Snake_t* snake, short displayPoints) {
    //Integer for character value
    int ch;
    //If the player points == the required number of points to win
    if (displayPoints >= 10){
      //Clear the current game
      clear();
      //Display winning message
      mvprintw(HEIGHT/2, WIDTH/2, "**--You Won! Congratulations Player for winning Classic Snake!--**");
      mvprintw(HEIGHT/2+1, WIDTH/2, "**--Score: %d", displayPoints);
      mvprintw(HEIGHT/2+2, WIDTH/2,"**--Press 'q' to quit--**");
      //Asks for user input to quit the game
      while ((ch = getch())!='q') {
        getch();
      }
      //Deletes the window and closes the ncurses library
      delwin(win);
      endwin();

      DeleteStack(snake);

      //Exits the program
      exit(1);
    }
}

void isCollide(WINDOW* win, Snake_t* snake, short displayPoints) {
    int ch;

    for (int i = 0; i < snake->top; i++) {
        if ((snake->head.x == snake->body[i].x) &&
            (snake->head.y == snake->body[i].y)) {
            //Clears the game
            clear();
            //refreshes the window
            wrefresh(win);
            //Prints text to screen about losing the game and asks for q to be entered
            mvprintw(HEIGHT/2, WIDTH/2, "**--GAME OVER--**");
            mvprintw(HEIGHT/2+1, WIDTH/2, "**--You lose! :( --**");
            mvprintw(HEIGHT/2+2, WIDTH/2, "**--Score: %d", displayPoints);
            mvprintw(HEIGHT/2+3, WIDTH/2, "**--Press 'q' to quit--**");
            //Waits for user to enter 'q' to exit program
            while ((ch = getch())!='q') {
              getch();
            }
            //Deletes the window and ends the program
            delwin(win);
            endwin();

            DeleteStack(snake);

            //Exits the program
            exit(1);
        }
    }
}
