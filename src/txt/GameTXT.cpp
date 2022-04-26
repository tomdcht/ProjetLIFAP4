#include <iostream>
#include <unistd.h>

#include "GameTXT.h"

void txtShow(WindowTXT& win, Game& game){

    const TowerArcher& towerArch = game.getTowerArcher();
    const Projectile& arrow = game.getConstProjectile();
    const Map& map = game.getConstMap();
    const Castle& castle = game.getConstCastle();
    const Ressources& gold = game.getConstRessources();
    

    win.clear();

    for(int x = 0; x < map.getDimX(); ++x){
        for(int y = 0; y < map.getDimY(); ++y){
            win.print(x, y, map.getXY(x, y));
        }
    }
    
    int size = game.enemies.size();

    win.print((int)towerArch.getConstPosX(), (int)towerArch.getConstPosY(), 'O');

    

    for (int n = 0; n < size ; n++) {
        win.print((int)game.getItEnemy(game.enemies, n)-> getConstPosX(), (int)game.getItEnemy(game.enemies, n)->getConstPosY(), 'X');

        if (game.getItEnemy(game.enemies, n)->isDead() == true) {
            win.print((int)game.getItEnemy(game.enemies, n)->getConstPosX(), (int)game.getItEnemy(game.enemies, n)->getConstPosY(), ' ');
            
            if (arrow.isInRange() == false) {
                win.print((int)arrow.getConstPosX(), (int)arrow.getConstPosY(), ' ');
            }
        }

    }


    if (arrow.isInRange() == true) {
        win.print((int)arrow.getConstPosX(), (int)arrow.getConstPosY(), '.');
    }

    


    std::string numGoldString = std::to_string(gold.getGold());
    const char* numGold = numGoldString.c_str();

    std::string PVCastleString = std::to_string(castle.getPV());
    const char* PVCastle = PVCastleString.c_str();

    win.print(37,1, PVCastle);
    win.print(37,2, numGold);


    
    

    
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

