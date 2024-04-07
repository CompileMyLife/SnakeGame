# Snake Game using ncurses library
This Snake Game is built upon René Hansen's Snakey Template found from [rhardih.io](https://rhardih.io/tag/xcode/)

## Features and Details
This Classic game brings improvements upon René's design of Snake. The snake
itself has two parts, a head, and a body. These are defined clearly in the
`include/stack.h` header file. Once the snake eats an apple, grows the body by
one as it progresses. There is a score of how many apples are eaten. The user
can use `W, A, S, D` or the arrow keys for going up, down, left, and right.

## System and Software Requirements
The source code was built and tested on `Ubuntu 20.04.06 LTS` and `macOS
Catalina 10.15.7` along with the following tools:
* gcc 9.4.0      / clang 12.0.0
* GNU Make 4.2.1 / GNU Make 3.8.1
* glibc 2.31
* libncurses5-dev and libncursesw5-dev

## Source:
 - `include/`:
    * `snake_parts.h`: Moving the snake/apple using the `Snake_t` stack type
    * `snake_world.h`: Checking for collision of snake to its body and win the game
    * `stack.h`: Define the `Snake_t` stack
    * `world.h`: Global definitions used throughout game files

 - `src/`:
    * `snake_parts.c`: Implementation of moving snake/apple using `Snake_t`
    * `snake_world.c`: Implementation of collision and win game checking
    * `stack.c`: Implementation of the `Snake_t` and stack API
