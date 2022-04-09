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
    
    int size = enemy.enemies.size();

    win.print((int)towerArch.getConstPosX(), (int)towerArch.getConstPosY(), 'O');

    for (int n = 0; n < size ; n++) {
        win.print((int)game.getIt(enemy.enemies, n)-> getConstPosX(), (int)game.getIt(enemy.enemies, n)->getConstPosY(), 'X');

        if (game.getIt(enemy.enemies, n)->isDead() == true) {
            win.print((int)game.getIt(enemy.enemies, n)->getConstPosX(), (int)game.getIt(enemy.enemies, n)->getConstPosY(), ' ');
            
            if (arrow.isInRange() == false) {
                win.print((int)arrow.getConstPosX(), (int)arrow.getConstPosY(), ' ');
            }
        }

    }


    if (arrow.isInRange() == true) {
        win.print((int)arrow.getConstPosX(), (int)arrow.getConstPosY(), '.');
    }

    win.print(37,1,'0');
    win.print(38,1,'1');

    
    win.draw();

}

void txtLoop(Game& game){
    WindowTXT win (game.getConstMap().getDimX(), game.getConstMap().getDimY());

    bool quit = false;
    int ch;

    do{
        
        txtShow(win, game);

        usleep(400000);

        game.autoEvents();

        ch = win.getCh();

        switch(ch){
            case 'q':
                quit = true; break;

        }
    }while(!quit);
}

