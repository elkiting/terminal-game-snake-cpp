#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fstream> // Tambahkan ini untuk menyimpan & membaca file
#include "menu.h"

#define MAX_LEN 200
#define HIGHSCORE_FILE "highscore.txt"

// Membaca high score dari file saat game baru dijalankan
int loadHighScore() {
    std::ifstream file(HIGHSCORE_FILE);
    int score = 0;
    if (file.is_open()) {
        file >> score;
        file.close();
    }
    return score;
}

// Menyimpan high score baru ke file
void saveHighScore(int score) {
    std::ofstream file(HIGHSCORE_FILE);
    if (file.is_open()) {
        file << score;
        file.close();
    }
}

int playGame(Difficulty difficulty) {
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

    int delay = 100000;
    if (difficulty == Difficulty::Easy) {
        delay = 150000;
    } else if (difficulty == Difficulty::Hard) {
        delay = 60000;
    }

    int makanX = rand() % (w - 1) + 1;
    int makanY = rand() % (h - 1) + 1;

    nodelay(stdscr, TRUE);

    while (!gameOver) {
        int ch = getch();
        if (ch == 'q' || ch == 'Q') break;

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

        mvprintw(h + 1, 0, "Skor: %d  |  Level: %s  |  'Q' keluar", skor, difficultyName(difficulty));
        refresh();

        tick++;
        usleep(delay);
    }

    nodelay(stdscr, FALSE);
    clear();
    mvprintw(h / 2 - 1, (w / 2) - 5, "GAME OVER!");
    mvprintw(h / 2,     (w / 2) - 7, "Skor Akhir: %d", skor);
    mvprintw(h / 2 + 2, (w / 2) - 13, "Tekan tombol apa saja...");
    refresh();
    getch();

    return skor;
}

int main() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(FALSE);
    srand(time(NULL));

    // Ambil high score terakhir yang tersimpan di file
    int highScore = loadHighScore();
    bool running = true;

    while (running) {
        nodelay(stdscr, FALSE);
        MenuAction action = showMainMenu(highScore);

        if (action == MenuAction::Start) {
            Difficulty level = chooseDifficulty();
            if (level != Difficulty::Back) {
                int lastScore = playGame(level);
                if (lastScore > highScore) {
                    highScore = lastScore;
                    saveHighScore(highScore); // Simpan rekor baru ke file!
                }
            }
        } else if (action == MenuAction::HighScore) {
            showHighScore(highScore);
        } else if (action == MenuAction::Quit) {
            running = false;
        }
    }

    endwin();
    return 0;
}