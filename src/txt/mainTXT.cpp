#include "GameTXT.h"

int main(void) {

    WindowTXT win(60, 100);
    win.termClear();
    Game game;
    txtLoop(game);
    win.termClear();
    return 0;
}