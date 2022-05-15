#include <iostream>
#include <unistd.h>

#include "GameTXT.h"

void txtShow(WindowTXT& win, Game& game){

    const Map& map = game.getConstMap();
    const Castle& castle = game.getConstCastle();
    const Ressources& gold = game.getConstRessources();


    

    win.clear();

    // -------------------------------------- Affichage de la map --------------------------------------
        for(int x = 0; x < map.getDimX(); ++x){
            for(int y = 0; y < map.getDimY(); ++y){
                win.print(x, y, map.getXY(x, y));
            }
        }
    // -------------------------------------------------------------------------------------------------
    

    // ------------------------------ Déclaration de la taille des listes -------------------------------
        const int sizeEnemies = game.enemies.size();
        const int sizeTowers = game.towers.size();
        const int sizeProjectiles1 = game.projectiles1.size();
        const int sizeProjectiles2 = game.projectiles2.size();
        const int sizeProjectiles3 = game.projectiles3.size();
        const int sizeProjectiles4 = game.projectiles4.size();
        const int sizeProjectiles5 = game.projectiles5.size();
    // --------------------------------------------------------------------------------------------------
    

    int countTower = game.getCountTower();

    int n = 0;


    // ----------------------------------------------------------------------- Affichage des tours ---------------------------------------------------------------
        for (n = 0; n < sizeTowers ; n++) {
            win.print((int)game.getItTower(game.towers, n)-> getConstPosX(), (int)game.getItTower(game.towers, n)->getConstPosY(), 'O');
        }
    // -----------------------------------------------------------------------------------------------------------------------------------------------------------



    // --------------------------------------------------------------- Affichage des Projectiles -------------------------------------------------------------------
        for (n = 0; n < sizeProjectiles1 ; n++) {
            win.print((int)game.getItProjectile(game.projectiles1, n)-> getConstPosX(), (int)game.getItProjectile(game.projectiles1, n)->getConstPosY(), '.');
        }
        for (n = 0; n < sizeProjectiles2 ; n++) {
            win.print((int)game.getItProjectile(game.projectiles2, n)-> getConstPosX(), (int)game.getItProjectile(game.projectiles2, n)->getConstPosY(), '.');
        }
        for (n = 0; n < sizeProjectiles3 ; n++) {
            win.print((int)game.getItProjectile(game.projectiles3, n)-> getConstPosX(), (int)game.getItProjectile(game.projectiles3, n)->getConstPosY(), '.');
        }
        for (n = 0; n < sizeProjectiles4 ; n++) {
            win.print((int)game.getItProjectile(game.projectiles4, n)-> getConstPosX(), (int)game.getItProjectile(game.projectiles4, n)->getConstPosY(), '.');
        }
        for (n = 0; n < sizeProjectiles5 ; n++) {
            win.print((int)game.getItProjectile(game.projectiles5, n)-> getConstPosX(), (int)game.getItProjectile(game.projectiles5, n)->getConstPosY(), '.');
        }
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------


    // ----------------------------------------------------------------------- Affichage des ennemies ------------------------------------------------------------
        for (n = 0; n < sizeEnemies ; n++) {
            win.print((int)game.getItEnemy(game.enemies, n)-> getConstPosX(), (int)game.getItEnemy(game.enemies, n)->getConstPosY(), 'X');

            if (game.getItEnemy(game.enemies, n)->isDead() == true) {
                win.print((int)game.getItEnemy(game.enemies, n)->getConstPosX(), (int)game.getItEnemy(game.enemies, n)->getConstPosY(), ' ');

            }
        }
    // ------------------------------------------------------------------------------------------------------------------------------------------------------------

    

    // --------------------------------------------------------- Affichage gold, PV chateau, nombre de tours et level -------------------------------------------------
        std::string numGoldString = std::to_string(gold.getGold());
        const char* numGold = numGoldString.c_str();

        std::string PVCastleString = std::to_string(castle.getPV());
        const char* PVCastle = PVCastleString.c_str();

        std::string countCastleString = std::to_string(countTower);
        const char* countCastleAff = countCastleString.c_str();


        win.print(97,6, PVCastle);
        win.print(17,6, numGold);

        win.print(33,37, countCastleAff);
    //-----------------------------------------------------------------------------------------------------------------------------------------------------------------

    
    win.draw();

}



void txtLoop(Game& game){

    WindowTXT win (game.getConstMap().getDimX(), game.getConstMap().getDimY());

    //game.coordTowersFonction(game.coordTowersTXT[5]);

    bool quit = false;
    int ch;

    do{
        
        txtShow(win, game);

        usleep(300000);

        game.autoEvents();

        ch = win.getCh();

        switch(ch){
            case 'q':
                quit = true; break;
            case 'p' :
                std::cout << "                               Jeu en Pause ... Appuyer sur 'p' pour Reprendre" << std::endl;
                std::cin.get();
                break;
            case 'b' :
                game.addTowerBomb(); break;
            case 'n' :
                game.addTowerMagic(); break;
            case 'v' :
                game.addTowerArch(); break;
        }
    }while(!quit);
}

