#include <iostream>
#include <unistd.h>

#include "GameTXT.h"

void txtShow(WindowTXT& win, Game& game){
    const Enemy& enemy = game.getConstEnemy();
    const TowerArcher& towerArch = game.getConstTowerArcher();
    const Map& map = game.getConstMap();
    const Projectile& arrow = game.getConstProjectile();

    win.clear();

    for(int x = 0; x < map.getDimX(); ++x){
        for(int y = 0; y < map.getDimY(); ++y){
            win.print(x, y, map.getXY(x, y));
        }
    }

    win.print(enemy.getConstPosX(), enemy.getConstPosY(), 'X');

    win.print(towerArch.getConstPosX(), towerArch.getConstPosY(), 'O');

    win.print(arrow.getConstPosX(), arrow.getConstPosY(), '.');

    if(enemy.getConstPosX() == win.getConstDimX() - 1){
        win.erase(enemy.getConstPosX(), enemy.getConstPosY(), ' ');
        game.appear();
        win.print(enemy.enemies->front().getConstPosX(), enemy.enemies->front().getConstPosY(), 'X');
    }

    win.draw();
}

void txtLoop(Game& game){
    WindowTXT win (game.getConstMap().getDimX(), game.getConstMap().getDimY());

    bool quit = false;
    int ch;

    do{
        txtShow(win, game);

        usleep(100000);

        game.autoEvents();

        ch = win.getCh();
        switch(ch){
            case 'q':
                quit = true; break;
        }
    }while(!quit);
}

