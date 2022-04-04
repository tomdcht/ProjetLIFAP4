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

    if (enemy.enemies.front()->isDead() == false) {
        win.print((int)enemy.enemies.front()->getConstPosX(), (int)enemy.enemies.front()->getConstPosY(), 'X');

        if (arrow.isInRange() == true) {
            win.print((int)arrow.getConstPosX(), (int)arrow.getConstPosY(), '.');
        }
    }


    if (enemy.enemies.front()->isDead() == true) {
        win.print((int)enemy.enemies.front()->getConstPosX(), (int)enemy.enemies.front()->getConstPosY(), ' ');
        // enemy.enemies.front()->setIsDead(false);

        if (arrow.isInRange() == false) {
            win.print((int)arrow.getConstPosX(), (int)arrow.getConstPosY(), ' ');
        }

    }


    // std::cout << std::endl;
    // std::cout << std::endl;
    // std::cout << std::endl;
    // std::cout << std::endl;
    // std::cout << "PosX : " << (int)enemy.enemies.front()->getConstPosX() << ",PosY : " << (int)enemy.enemies.front()->getConstPosY() << std::endl;
    // std::cout << "IsDead ? " << enemy.enemies.front()->isDead() << std::endl;


    // if(enemy.enemies.front()->getConstPosX() == win.getConstDimX() - 1){
    //     win.erase(enemy.enemies.front()->getConstPosX(), enemy.enemies.front()->getConstPosY(), ' ');
    //     // game.appear();
    //     win.print(enemy.enemies.front()->getConstPosX(), enemy.enemies.front()->getConstPosY(), 'X');
    // }

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

        switch(ch){
            case 'q':
                quit = true; break;

        }
    }while(!quit);
}

