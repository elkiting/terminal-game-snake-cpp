#include "menu.h"

#include <cstdio>
#include <cstring>
#include <ncurses.h>

namespace {

void drawMenu(const char* title, const char* const options[], int optionCount, int selected,
              const char* footer) {
    int height;
    int width;
    getmaxyx(stdscr, height, width);
    clear();

    const int titleY = height / 2 - optionCount - 4;
    mvprintw(titleY, (width - static_cast<int>(strlen(title))) / 2, "%s", title);
    for (int i = 0; i < optionCount; ++i) {
        const int y = titleY + 3 + i;
        if (i == selected) {
            attron(A_REVERSE);
        }
        mvprintw(y, (width - static_cast<int>(strlen(options[i]))) / 2, "%s", options[i]);
        if (i == selected) {
            attroff(A_REVERSE);
        }
    }
    if (footer != nullptr) {
        mvprintw(height - 2, (width - static_cast<int>(strlen(footer))) / 2, "%s", footer);
    }
    refresh();
}

int selectOption(const char* title, const char* const options[], int optionCount, int initialSelection,
                 const char* footer) {
    int selected = initialSelection;
    while (true) {
        drawMenu(title, options, optionCount, selected, footer);
        const int key = getch();
        if (key == KEY_UP) {
            selected = (selected + optionCount - 1) % optionCount;
        } else if (key == KEY_DOWN) {
            selected = (selected + 1) % optionCount;
        } else if (key == '\n' || key == KEY_ENTER || key == '\r') {
            return selected;
        } else if (key == 27) {
            return -1;
        }
    }
}

} // namespace

MenuAction showMainMenu(int highScore) {
    const char* options[] = {"Mulai", "High Score", "Keluar"};
    char scoreLine[64];
    snprintf(scoreLine, sizeof(scoreLine), "High Score: %d", highScore);
    const int selected = selectOption("SNAKE", options, 3, 0, scoreLine);
    if (selected == -1) {
        return MenuAction::Quit;
    }
    if (selected == 1) {
        return MenuAction::HighScore;
    }
    if (selected == 2) {
        return MenuAction::Quit;
    }
    return MenuAction::Start;
}

Difficulty chooseDifficulty() {
    const char* options[] = {"Easy", "Normal", "Hard"};
    const int selected = selectOption("PILIH LEVEL", options, 3, 0, "Enter: pilih  |  Esc: kembali");
    if (selected == 0) {
        return Difficulty::Easy;
    }
    if (selected == 1) {
        return Difficulty::Normal;
    }
    if (selected == 2) {
        return Difficulty::Hard;
    }
    return Difficulty::Back;
}

void showHighScore(int highScore) {
    clear();
    int height;
    int width;
    getmaxyx(stdscr, height, width);

    const char* title = "HIGH SCORE";
    mvprintw(height / 2 - 2, (width - static_cast<int>(strlen(title))) / 2, "%s", title);
    char scoreLine[64];
    snprintf(scoreLine, sizeof(scoreLine), "Skor tertinggi: %d", highScore);
    mvprintw(height / 2, (width - static_cast<int>(strlen(scoreLine))) / 2, "%s", scoreLine);
    const char* prompt = "Tekan tombol apa saja untuk kembali";
    mvprintw(height / 2 + 2, (width - static_cast<int>(strlen(prompt))) / 2, "%s", prompt);
    refresh();
    getch();
}

const char* difficultyName(Difficulty difficulty) {
    switch (difficulty) {
    case Difficulty::Easy:
        return "Easy";
    case Difficulty::Normal:
        return "Normal";
    case Difficulty::Hard:
        return "Hard";
    case Difficulty::Back:
        return "";
    }
    return "";
}