#include "GameTXT.h"

int main(void) {

    WindowTXT win(50, 50);
    win.termClear();
    Game game;
    txtLoop(game);
    win.termClear();
    return 0;
}