#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define MAX_LEN 200

int main() {
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(FALSE);
    nodelay(stdscr, TRUE); 
    srand(time(NULL)); 

    int w = 40, h = 15;
    int x = 20, y = 7; 

    int ularX[MAX_LEN];
    int ularY[MAX_LEN];
    int panjangUlar = 1;
    ularX[0] = x;
    ularY[0] = y;

    int arah = 0;
    int skor = 0;
    bool gameOver = false;
    int tick = 0;

    int makanX = rand() % (w - 1) + 1;
    int makanY = rand() % (h - 1) + 1;

    while (!gameOver) {
        int ch = getch();
        if (ch == 'q') break;

        if (ch == KEY_UP && arah != 2) arah = 1;
        if (ch == KEY_DOWN && arah != 1) arah = 2;
        if (ch == KEY_LEFT && arah != 4) arah = 3;
        if (ch == KEY_RIGHT && arah != 3) arah = 4;

        bool bolehJalan = (arah == 3 || arah == 4) || ((arah == 1 || arah == 2) && (tick % 2 == 0));

        if (arah != 0 && bolehJalan) {
            int nextX = x;
            int nextY = y;
            if (arah == 1) nextY--;
            if (arah == 2) nextY++;
            if (arah == 3) nextX--;
            if (arah == 4) nextX++;

            if (nextX <= 0 || nextX >= w || nextY <= 0 || nextY >= h) {
                gameOver = true;
            }

            if (!gameOver) {
                for (int i = 0; i < panjangUlar; i++) {
                    if (ularX[i] == nextX && ularY[i] == nextY) {
                        gameOver = true;
                        break;
                    }
                }
            }
            if (gameOver) break;

            for (int i = panjangUlar - 1; i > 0; i--) {
                ularX[i] = ularX[i - 1];
                ularY[i] = ularY[i - 1];
            }
            x = nextX;
            y = nextY;
            ularX[0] = x;
            ularY[0] = y;

            if (x == makanX && y == makanY) {
                skor += 10;
                if (panjangUlar < MAX_LEN) {
                    panjangUlar++;
                }

                bool posisiValid;
                do {
                    makanX = rand() % (w - 1) + 1;
                    makanY = rand() % (h - 1) + 1;
                    posisiValid = true;

                    for (int i = 0; i < panjangUlar; i++) {
                        if (ularX[i] == makanX && ularY[i] == makanY) {
                            posisiValid = false;
                            break;
                        }
                    }
                } while (!posisiValid);
            }
        }
        clear();

        for (int i = 0; i <= w; i++) {
            mvprintw(0, i, "#");
            mvprintw(h, i, "#");
        }
        for (int i = 0; i <= h; i++) {
            mvprintw(i, 0, "#");
            mvprintw(i, w, "#");
        }

        mvprintw(makanY, makanX, "*");
        mvprintw(ularY[0], ularX[0], "O");
        for (int i = 1; i < panjangUlar; i++) {
            mvprintw(ularY[i], ularX[i], "o");
        }

        mvprintw(h + 1, 0, "Skor: %d  |  Tekan 'Q' untuk keluar", skor);
        refresh();

        tick++;
        usleep(100000);
    }

    nodelay(stdscr, FALSE);
    clear();
    mvprintw(h / 2 - 1, (w / 2) - 5, "GAME OVER!");
    mvprintw(h / 2,     (w / 2) - 7, "Skor Akhir: %d", skor);
    mvprintw(h / 2 + 2, (w / 2) - 13, "Tekan tombol apa saja...");
    refresh();
    getch();

    endwin();
    return 0;
}