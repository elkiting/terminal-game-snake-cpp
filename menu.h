#ifndef MENU_H
#define MENU_H

enum class MenuAction {
    Start,
    HighScore,
    Quit
};

enum class Difficulty {
    Easy,
    Normal,
    Hard,
    Back
};

MenuAction showMainMenu(int highScore);
Difficulty chooseDifficulty();
void showHighScore(int highScore);
const char* difficultyName(Difficulty difficulty);

#endif