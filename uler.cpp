#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 22
#define MAX_SNAKE 100


typedef struct {
    int x;
    int y;
} Point;

int main() {
    Point snake[MAX_SNAKE];
    int snake_len = 3;
    
    
    snake[0].x = WIDTH / 2;     snake[0].y = HEIGHT / 2;
    snake[1].x = (WIDTH / 2)-1; snake[1].y = HEIGHT / 2;
    snake[2].x = (WIDTH / 2)-2; snake[2].y = HEIGHT / 2;

    int foodX, foodY;
    int dirX = 1, dirY = 0;
    int score = 0;
    int ch;
    
    
    int base_delay = 200000;
    int current_delay = base_delay;

    srand(time(NULL));
    foodX = rand() % (WIDTH - 2) + 1;
    foodY = rand() % (HEIGHT - 2) + 1;


    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    curs_set(0);


    if (has_colors()) {
        start_color();
        init_pair(1, COLOR_GREEN, COLOR_BLACK);
        init_pair(2, COLOR_RED, COLOR_BLACK);
        init_pair(3, COLOR_CYAN, COLOR_BLACK);
        init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    }

    while (1) {
        
        ch = getch();
        if (ch == KEY_UP && dirY == 0)    { dirX = 0; dirY = -1; }
        if (ch == KEY_DOWN && dirY == 0)  { dirX = 0; dirY = 1;  }
        if (ch == KEY_LEFT && dirX == 0)  { dirX = -1; dirY = 0; }
        if (ch == KEY_RIGHT && dirX == 0) { dirX = 1; dirY = 0;  }
        if (ch == 'q' || ch == 'Q') break;

        
        int newX = snake[0].x + dirX;
        int newY = snake[0].y + dirY;

        
        if (newX <= 0 || newX >= WIDTH - 1 || newY <= 0 || newY >= HEIGHT - 1) break;

        
        int self_collision = 0;
        for (int i = 0; i < snake_len; i++) {
            if (snake[i].x == newX && snake[i].y == newY) {
                self_collision = 1;
                break;
            }
        }
        if (self_collision) break;

        
        if (newX == foodX && newY == foodY) {
            score += 10;
            if (snake_len < MAX_SNAKE) snake_len++;
            
            foodX = rand() % (WIDTH - 2) + 1;
            foodY = rand() % (HEIGHT - 2) + 1;

            
            current_delay = base_delay - (score * 1000);
            if (current_delay < 50000) current_delay = 50000;
        }

        
        for (int i = snake_len - 1; i > 0; i--) {
            snake[i] = snake[i - 1];
        }
        snake[0].x = newX;
        snake[0].y = newY;

        
        clear();

        
        attron(COLOR_PAIR(3));
        for (int i = 0; i < WIDTH; i++) {
            mvprintw(0, i, "=");
            mvprintw(HEIGHT - 1, i, "=");
        }
        for (int i = 0; i < HEIGHT; i++) {
            mvprintw(i, 0, "|");
            mvprintw(i, WIDTH - 1, "|");
        }
        attroff(COLOR_PAIR(3));

        
        attron(COLOR_PAIR(2) | A_BOLD);
        mvprintw(foodY, foodX, "X");
        attroff(COLOR_PAIR(2) | A_BOLD);

        
        attron(COLOR_PAIR(1));
        for (int i = 1; i < snake_len; i++) {
            mvprintw(snake[i].y, snake[i].x, "o");
        }
        attroff(COLOR_PAIR(1));

        
        attron(COLOR_PAIR(4) | A_BOLD);
        mvprintw(snake[0].y, snake[0].x, "O");
        attroff(COLOR_PAIR(4) | A_BOLD);

        
        attron(COLOR_PAIR(4));
        int speed_level = (base_delay - current_delay) / 10000 + 1;
        mvprintw(0, 3, " [ SKOR: %d | SPEED: Lvl %d ] ", score, speed_level);
        attroff(COLOR_PAIR(4));

        refresh();
        usleep(current_delay);
    }

    
    clear();
    attron(COLOR_PAIR(2) | A_BOLD);
    mvprintw(HEIGHT / 2 - 1, (WIDTH / 2) - 6, "GAME OVER!");
    attroff(COLOR_PAIR(2) | A_BOLD);
    
    attron(COLOR_PAIR(4));
    mvprintw(HEIGHT / 2, (WIDTH / 2) - 8, "Skor Akhir: %d", score);
    mvprintw(HEIGHT / 2 + 1, (WIDTH / 2) - 12, "Tekan Sembarang Tombol...");
    attroff(COLOR_PAIR(4));
    
    refresh();
    nodelay(stdscr, FALSE);
    getch();

    endwin();
    return 0;
}