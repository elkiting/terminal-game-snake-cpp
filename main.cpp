#include <ncurses.h>

int main() {
    initscr();
    noecho();
    keypad(stdscr, TRUE); 
    curs_set(FALSE);

    int w = 40, h = 15;
    int x = 20, y = 7;

    while (true) {
        clear();

        for (int i = 0; i <= w; i++) { mvprintw(0, i, "#"); mvprintw(h, i, "#"); }
        for (int i = 0; i <= h; i++) { mvprintw(i, 0, "#"); mvprintw(i, w, "#"); }

        mvprintw(y, x, "O");
        refresh();

        int ch = getch();
        if (ch == 'q') break;
        if (ch == KEY_UP && y > 1) y--;
        if (ch == KEY_DOWN && y < h - 1) y++;
        if (ch == KEY_LEFT && x > 1) x--;
        if (ch == KEY_RIGHT && x < w - 1) x++;
    }

    endwin();
    return 0;
}