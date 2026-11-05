#include <ncurses.h>

int main() {

    initscr();                      

    printw("Lau sape mpruy\n");
    
    refresh();                      

    getch();                        

    endwin();                       

    return 0;
}
