#include <iostream>
#include <unistd.h>

#include "GameTXT.h"

void txtShow(WindowTXT& win, Game& game){
    Enemy& enemy = game.getEnemy();
    const TowerArcher& towerArch = game.getConstTowerArcher();
    const Map& map = game.getConstMap();
    const Projectile& arrow = game.getConstProjectile();

    win.clear();

    for(int x = 0; x < map.getDimX(); ++x){
        for(int y = 0; y < map.getDimY(); ++y){
            win.print(x, y, map.getXY(x, y));
        }
    }

    win.print((int)towerArch.getConstPosX(), (int)towerArch.getConstPosY(), 'O');

    if (enemy.isDead() == false) {
        win.print((int)enemy.getConstPosX(), (int)enemy.getConstPosY(), 'X');

        if (arrow.isInRange() == true) {
            win.print((int)arrow.getConstPosX(), (int)arrow.getConstPosY(), '.');
        }
    }



    win.draw();
}

void txtLoop(Game& game){
    WindowTXT win (game.getConstMap().getDimX(), game.getConstMap().getDimY());

    bool quit = false;
    bool pause = false;
    int ch;
    int ch2;

    do{
        txtShow(win, game);

        usleep(500000);

        game.autoEvents();

        ch = win.getCh();
        ch2 = win.getCh();

        switch(ch){
            case 'q':
                quit = true; break;
            
        }
    }while(!quit);
}

