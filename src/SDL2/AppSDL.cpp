/**
* \file AppSDL.cpp
* \brief
* \version 1.0
* \date 22 Mars 2022
* \include AppSDL.h
*/

#include <iostream>
#include <fstream>
#include <unistd.h>


#include "AppSDL.h"
#include "../core/TowerArcher.h"
#include "../core/Enemy.h"
#include "../core/Castle.h"
#include "../core/Projectile.h"
#include "../core/Tower.h"
#include "../core/TowerBomb.h"




using namespace std;


AppSDL::AppSDL(){
}

AppSDL::~AppSDL(){
    SDLAffQuit();
}

void AppSDL::SDLAffInit(){

    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER | SDL_INIT_AUDIO) < 0){
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    if (TTF_Init() < 0){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
        SDL_Quit();
        exit(1);
    }

    window = SDL_CreateWindow("LifaPower Defense", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH_WINDOW, HEIGHT_WINDOW, SDL_WINDOW_FULLSCREEN );
    if(!window){
        cout << "Erreur lors de la création de la fenêtre ! " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer, 112, 114, 110, 255);
    SDL_RenderClear(renderer);
    if (renderer == NULL){
        cout << "Erreur lors de la création du renderer ! " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    background.loadFromFile("data/Map/PNG/game_background_1/game_background_1.png", renderer);

    castleImage1.loadFromFile("data/Castle/Castle01.png",renderer);
    castleImage2.loadFromFile("data/Castle/Castle02.png",renderer);
    castleImage3.loadFromFile("data/Castle/Castle03.png",renderer);

    PVCastle.loadFromFile("data/Menu/PVCastle.png",renderer);
    coins.loadFromFile("data/Menu/Coins.png",renderer);

    menuPrinc.loadFromFile("data/Menu_principal.png", renderer);
    menuPerdu.loadFromFile("data/Menu/MenuPerdu.png", renderer);
    quitButton.loadFromFile("data/Button/pauseButton.png", renderer);
    infoButton.loadFromFile("data/Button/infoButton.png", renderer);
    menuInfo.loadFromFile("data/Menu/MenuInfo.png", renderer);
    shopButton.loadFromFile("data/Button/shopButton.png", renderer);
    menuShop.loadFromFile("data/Menu/MenuShop.png", renderer);
    menuSettings.loadFromFile("data/Menu/MenuSettings.png", renderer);
    settingsButton.loadFromFile("data/Button/settingButton.png", renderer);

    MenuBuy.loadFromFile("data/Menu/MenuBuy.png", renderer);
    MenuUpgrade1.loadFromFile("data/Menu/MenuUpgrade1.png", renderer);
    MenuUpgrade2.loadFromFile("data/Menu/MenuUpgrade2.png", renderer);
    MenuUpgrade3.loadFromFile("data/Menu/MenuUpgrade3.png", renderer);
    MenuUpgradeMax.loadFromFile("data/Menu/MenuUpgradeMax.png", renderer);

    playSound(music, "sound/musicMenu.mp3");
}

void AppSDL::SDLAff() {

        Uint32 ticks = SDL_GetTicks();
        Uint32 time = ticks / 10;
        Uint32 spriteEnemy = time % 15;
        Uint32 spriteTowerArch = time % 5;

    if (game.newEnemy == true) {
        for(int n = 0 ; n < game.getSizeListEnemy(); n++){
            game.getItEnemy(game.enemies, n)->loadFromFile(game.getItEnemy(game.enemies, n)->path, renderer);
        }
        game.newEnemy = false;
    }
    

    if (game.newTower == true) {
        for(int n=0; n < game.getSizeListTower(); n++){
            game.getItTower(game.towers, n)->loadFromFile(game.getItTower(game.towers, n)->path, renderer);
        }
        game.newTower = false;
    }


    if (game.newProjectile1 == true) {
        for(int n = 0 ; n < game.getSizeListProjectile(1); n++){
            game.getItProjectile(game.projectiles1, n)->loadFromFile(game.getItProjectile(game.projectiles1, n)->path, renderer);
            cout << game.getItProjectile(game.projectiles1, n)->path << endl;
        }
        game.newProjectile1 = false; 
    }

    if (game.newProjectile2 == true) {
        for(int n = 0 ; n < game.getSizeListProjectile(2); n++){
            game.getItProjectile(game.projectiles2, n)->loadFromFile(game.getItProjectile(game.projectiles2, n)->path, renderer);
            cout << game.getItProjectile(game.projectiles2, n)->path << endl;

        }
        game.newProjectile2 = false; 
    }

    if (game.newProjectile3 == true) {
        for(int n = 0 ; n < game.getSizeListProjectile(3); n++){
            game.getItProjectile(game.projectiles3, n)->loadFromFile(game.getItProjectile(game.projectiles3, n)->path, renderer);
        }
        game.newProjectile3 = false; 
    }

    if (game.newProjectile4 == true) {
        for(int n = 0 ; n < game.getSizeListProjectile(4); n++){
            game.getItProjectile(game.projectiles4, n)->loadFromFile(game.getItProjectile(game.projectiles4, n)->path, renderer);
        }
        game.newProjectile4 = false; 
    }

    if (game.newProjectile5 == true) {
        for(int n = 0 ; n < game.getSizeListProjectile(5); n++){
            game.getItProjectile(game.projectiles5, n)->loadFromFile(game.getItProjectile(game.projectiles5, n)->path, renderer);
        }
        game.newProjectile5 = false; 
    }
    
    if (game.newProjectile6 == true) {
        for(int n = 0 ; n < game.getSizeListProjectile(6); n++){
            game.getItProjectile(game.projectiles6, n)->loadFromFile(game.getItProjectile(game.projectiles6, n)->path, renderer);
        }
        game.newProjectile6 = false;
    }

    if (game.newProjectile7 == true) {
        for(int n = 0 ; n < game.getSizeListProjectile(7); n++){
            game.getItProjectile(game.projectiles7, n)->loadFromFile(game.getItProjectile(game.projectiles7, n)->path, renderer);
        }
        game.newProjectile7 = false;
    }

    if (game.newProjectile8 == true) {
        for(int n = 0 ; n < game.getSizeListProjectile(8); n++){
            game.getItProjectile(game.projectiles8, n)->loadFromFile(game.getItProjectile(game.projectiles8, n)->path, renderer);
        } 
        game.newProjectile8 = false;
    }

    if (game.newProjectile9 == true) {
        for(int n = 0 ; n < game.getSizeListProjectile(9); n++){
            game.getItProjectile(game.projectiles9, n)->loadFromFile(game.getItProjectile(game.projectiles9, n)->path, renderer);
        }
        game.newProjectile9 = false;
    }



    background.draw(renderer, 0, 0, WIDTH_WINDOW, HEIGHT_WINDOW);

    for(int n = 0 ; n < game.getSizeListEnemy(); n++){
        game.getItEnemy(game.enemies, n)->draw(renderer, 370*spriteEnemy, 0, 341, 420, game.getItEnemy(game.enemies, n)->getPosX()-(WIDTH_ENEMY/2), game.getItEnemy(game.enemies, n)->getPosY()-(HEIGHT_ENEMY/2), WIDTH_ENEMY, HEIGHT_ENEMY);
    }
    for(int n = 0 ; n < game.getSizeListProjectile(1); n++){
        game.getItProjectile(game.projectiles1, n)->draw(renderer, game.getItProjectile(game.projectiles1, n)->getPosX()-(WIDTH_PROJECTILE/2), game.getItProjectile(game.projectiles1, n)->getPosY()-(HEIGHT_PROJECTILE/2), WIDTH_PROJECTILE, HEIGHT_PROJECTILE);
    }
    for(int n = 0 ; n < game.getSizeListProjectile(2); n++){
        game.getItProjectile(game.projectiles2, n)->draw(renderer, game.getItProjectile(game.projectiles2, n)->getPosX(), game.getItProjectile(game.projectiles2, n)->getPosY(), WIDTH_PROJECTILE, HEIGHT_PROJECTILE);
    }
    for(int n = 0 ; n < game.getSizeListProjectile(3); n++){
        game.getItProjectile(game.projectiles3, n)->draw(renderer, game.getItProjectile(game.projectiles3, n)->getPosX(), game.getItProjectile(game.projectiles3, n)->getPosY(), WIDTH_PROJECTILE, HEIGHT_PROJECTILE);
    }
    for(int n = 0 ; n < game.getSizeListProjectile(4); n++){
        game.getItProjectile(game.projectiles4, n)->draw(renderer, game.getItProjectile(game.projectiles4, n)->getPosX(), game.getItProjectile(game.projectiles4, n)->getPosY(), WIDTH_PROJECTILE, HEIGHT_PROJECTILE);
    }
    for(int n = 0 ; n < game.getSizeListProjectile(5); n++){
        game.getItProjectile(game.projectiles5, n)->draw(renderer, game.getItProjectile(game.projectiles5, n)->getPosX(), game.getItProjectile(game.projectiles5, n)->getPosY(), WIDTH_PROJECTILE, HEIGHT_PROJECTILE);
    }
    for(int n = 0 ; n < game.getSizeListProjectile(6); n++){
        game.getItProjectile(game.projectiles6, n)->draw(renderer, game.getItProjectile(game.projectiles6, n)->getPosX(), game.getItProjectile(game.projectiles6, n)->getPosY(), WIDTH_PROJECTILE, HEIGHT_PROJECTILE);
    }
    for(int n = 0 ; n < game.getSizeListProjectile(7); n++){
        game.getItProjectile(game.projectiles7, n)->draw(renderer, game.getItProjectile(game.projectiles7, n)->getPosX(), game.getItProjectile(game.projectiles7, n)->getPosY(), WIDTH_PROJECTILE, HEIGHT_PROJECTILE);
    }
    for(int n = 0 ; n < game.getSizeListProjectile(8); n++){
        game.getItProjectile(game.projectiles8, n)->draw(renderer, game.getItProjectile(game.projectiles8, n)->getPosX(), game.getItProjectile(game.projectiles8, n)->getPosY(), WIDTH_PROJECTILE, HEIGHT_PROJECTILE);
    }
    for(int n = 0 ; n < game.getSizeListProjectile(9); n++){
        game.getItProjectile(game.projectiles9, n)->draw(renderer, game.getItProjectile(game.projectiles9, n)->getPosX(), game.getItProjectile(game.projectiles9, n)->getPosY(), WIDTH_PROJECTILE, HEIGHT_PROJECTILE);
    }

    for(int n=0; n < game.getSizeListTower(); n++){
        game.getItTower(game.towers, n)->draw(renderer, 514*spriteTowerArch, 0, 514, 514, game.getItTower(game.towers, n)->getPosX()-(WIDTH_TOWER/2), game.getItTower(game.towers, n)->getPosY()-(HEIGHT_TOWER/2), WIDTH_TOWER, HEIGHT_TOWER);
    }

    if (game.castle.getPV() > 10) {
        castleImage1.draw(renderer, 1775, 615, WIDTH_CASTLE, HEIGHT_CASTLE);
    } else if(game.castle.getPV() > 5) {
        castleImage2.draw(renderer, 1775, 615, WIDTH_CASTLE, HEIGHT_CASTLE);
    } else {
        castleImage3.draw(renderer, 1775, 615, WIDTH_CASTLE, HEIGHT_CASTLE);
    }

    string gold = to_string(game.gold.getGold());
    const char* goldChar = gold.c_str();

    string PV = to_string(game.castle.getPV());
    const char* PVChar = PV.c_str();

    coins.draw(renderer, 20, 20, WIDTH_COINS, HEIGHT_COINS);
    PVCastle.draw(renderer, 250, 26, WIDTH_PVCASTLE, HEIGHT_PVCASTLE);

    textGold.write(renderer, goldChar , font, "font/futura/Futura Bold font.ttf", 100, color, 110, 35 ,100, 50);
    textPvCastle.write(renderer, PVChar, font, "font/futura/Futura Bold font.ttf", 100, color, 345, 35, 50, 50);

}

void AppSDL::SDLAffLoop(){
    SDL_Event events;
	bool quit = false;
    bool menu = true;
    bool play = false;
    bool end = false;
    bool pause = false;
    bool info = false;
    bool shop = false;
    bool settings = false;

    bool drawTower = false;
    int nbTower = NULL;
    int menuTowerPosX = 0;
    int menuTowerPosY = 0;

    int tower2level = 0;
    int tower3level = 0;
    int tower4level = 0;
    int tower5level = 0;
    int tower6level = 0;
    int tower7level = 0;
    int tower8level = 0;
    int tower9level = 0;


    while (!quit) {
        while(SDL_PollEvent(&events)){
            switch (events.type) {
                case SDL_KEYDOWN:
                    if(events.key.keysym.scancode == SDL_SCANCODE_ESCAPE){
                        cout << "Fermeture de la fenêtre" << endl;
                        SDLAffQuit();
                        quit = true; break;
                    }
                    break;

                case SDL_KEYUP:

                case SDL_WINDOWEVENT:
                    if (events.window.event == SDL_WINDOWEVENT_CLOSE){
                        quit = true; break;
                    }

                case SDL_MOUSEBUTTONDOWN:

                    if(events.button.button == SDL_BUTTON_LEFT){
                        if( events.button.x > 855 && events.button.x < 1060 && events.button.y > 546 && events.button.y < 599 && play == false){
                            menu = false;
                            play = true;
                            playSound(music, "sound/musicPlay.mp3");

                        }
                    // recupere les coordonnées du bouton "start" sur le menu principal

                        if( events.button.x > 855 && events.button.x < 1060 && events.button.y > 546 && events.button.y < 599 && play == false && menu == true ){
                            menu = false;
                            play = true;
                        }
                    //bouton quitter en haut à droite du menu principal

                        if( events.button.x > 1840 && events.button.x < 1890 && events.button.y > 30 && events.button.y < 78 && play == false && menu == true ){
                            quit = true; break;
                        }
                    //bouton shop sur le menu principal : affiche shopMenu
                        if( events.button.x > 1770 && events.button.x < 1840 && events.button.y > 30 && events.button.y < 78 && play == false && menu == true ){
                            shop = true;
                        }
                    //bouton fermer du menuShop
                        if( events.button.x > 1430 && events.button.x < 1500 && events.button.y > 240 && events.button.y < 310 && shop == true ){
                            shop = false;
                            menu = true;
                        }
                    //bouton des paramtres, quand on clique une premiere fois il se deroule si on reclique il se referme
                        if( events.button.x > 1770 && events.button.x < 1840 && events.button.y > 30 && events.button.y < 78 && play == true ){
                            if(settings == false){
                                settings = true;
                            }
                            else {
                                settings = false;
                                play = true;
                            }
                         
                        }

                        if(events.button.x > 851 && events.button.x < 970 && events.button.y > 747 && events.button.y < 861){
                            menu = true;
                            game.~Game();
                            run();
                        }
                        // ouvre le menu d'information
                        if( events.button.x > 1790 && events.button.x < 1820 && events.button.y > 150 && events.button.y < 180 && settings == true ){
                            info = true;
                            play = false;
                        }
                        //bouton en haut à droite qui ferme le menu d'information
                        if( events.button.x > 1430 && events.button.x < 1500 && events.button.y > 240 && events.button.y < 310 && info == true){
                           info = false;
                           play = true;
                        }
                        
                        
                        // Achat Tower
                          if( events.button.x > (menuTowerPosX+30) && events.button.x < (menuTowerPosX+154) && events.button.y > (menuTowerPosY-108) && events.button.y < (menuTowerPosY-69) && drawTower == true){
                            if(nbTower == 2 && tower2level == 0) {tower2level += 1; drawTower = false; game.addTowerArch(nbTower);}
                            if(nbTower == 3 && tower3level == 0) {tower3level += 1; drawTower = false; game.addTowerArch(nbTower);}
                            if(nbTower == 4 && tower4level == 0) {tower4level += 1; drawTower = false; game.addTowerArch(nbTower);}
                            if(nbTower == 5 && tower5level == 0) {tower5level += 1; drawTower = false; game.addTowerArch(nbTower);}
                            if(nbTower == 6 && tower6level == 0) {tower6level += 1; drawTower = false; game.addTowerArch(nbTower);}
                            if(nbTower == 7 && tower7level == 0) {tower7level += 1; drawTower = false; game.addTowerArch(nbTower);}
                            if(nbTower == 8 && tower8level == 0) {tower8level += 1; drawTower = false; game.addTowerArch(nbTower);}
                            if(nbTower == 9 && tower9level == 0) {tower9level += 1; drawTower = false; game.addTowerArch(nbTower);}
                        }
                        // Achat Bomb
                          if( events.button.x > (menuTowerPosX+180) && events.button.x < (menuTowerPosX+300) && events.button.y > (menuTowerPosY-108) && events.button.y < (menuTowerPosY-69) && drawTower == true){
                            if(nbTower == 2 && tower2level == 0) {tower2level += 1; drawTower = false; game.addTowerBomb(nbTower);}
                            if(nbTower == 3 && tower3level == 0) {tower3level += 1; drawTower = false; game.addTowerBomb(nbTower);}
                            if(nbTower == 4 && tower4level == 0) {tower4level += 1; drawTower = false; game.addTowerBomb(nbTower);}
                            if(nbTower == 5 && tower5level == 0) {tower5level += 1; drawTower = false; game.addTowerBomb(nbTower);}
                            if(nbTower == 6 && tower6level == 0) {tower6level += 1; drawTower = false; game.addTowerBomb(nbTower);}
                            if(nbTower == 7 && tower7level == 0) {tower7level += 1; drawTower = false; game.addTowerBomb(nbTower);}
                            if(nbTower == 8 && tower8level == 0) {tower8level += 1; drawTower = false; game.addTowerBomb(nbTower);}
                            if(nbTower == 9 && tower9level == 0) {tower9level += 1; drawTower = false; game.addTowerBomb(nbTower);}
                        }
                        // Achat Magic
                          if( events.button.x > (menuTowerPosX+330) && events.button.x < (menuTowerPosX+450) && events.button.y > (menuTowerPosY-108) && events.button.y < (menuTowerPosY-69) && drawTower == true){
                            if(nbTower == 2 && tower2level == 0) {tower2level += 1; drawTower = false; game.addTowerMagic(nbTower);}
                            if(nbTower == 3 && tower3level == 0) {tower3level += 1; drawTower = false; game.addTowerMagic(nbTower);}
                            if(nbTower == 4 && tower4level == 0) {tower4level += 1; drawTower = false; game.addTowerMagic(nbTower);}
                            if(nbTower == 5 && tower5level == 0) {tower5level += 1; drawTower = false; game.addTowerMagic(nbTower);}
                            if(nbTower == 6 && tower6level == 0) {tower6level += 1; drawTower = false; game.addTowerMagic(nbTower);}
                            if(nbTower == 7 && tower7level == 0) {tower7level += 1; drawTower = false; game.addTowerMagic(nbTower);}
                            if(nbTower == 8 && tower8level == 0) {tower8level += 1; drawTower = false; game.addTowerMagic(nbTower);}
                            if(nbTower == 9 && tower9level == 0) {tower9level += 1; drawTower = false; game.addTowerMagic(nbTower);}
                        }

                        // Upgrade
                        if( events.button.x > (menuTowerPosX+228) && events.button.x < (menuTowerPosX+263) && events.button.y > (menuTowerPosY-237) && events.button.y < (menuTowerPosY-207) && drawTower == true){
                            if(nbTower == 2 && tower2level >= 1 && tower2level <= 3) {tower2level += 1; drawTower = false;}
                            if(nbTower == 3 && tower3level >= 1 && tower3level <= 3) {tower3level += 1; drawTower = false;}
                            if(nbTower == 4 && tower4level >= 1 && tower4level <= 3) {tower4level += 1; drawTower = false;}
                            if(nbTower == 5 && tower5level >= 1 && tower5level <= 3) {tower5level += 1; drawTower = false;}
                            if(nbTower == 6 && tower6level >= 1 && tower6level <= 3) {tower6level += 1; drawTower = false;}
                            if(nbTower == 7 && tower7level >= 1 && tower7level <= 3) {tower7level += 1; drawTower = false;}
                            if(nbTower == 8 && tower8level >= 1 && tower8level <= 3) {tower8level += 1; drawTower = false;}
                            if(nbTower == 9 && tower9level >= 1 && tower9level <= 3) {tower9level += 1; drawTower = false;}
                        }



                        // Tour 2
                        if( events.button.x > 414 && events.button.x < 645 && events.button.y > 945 && events.button.y < 1035 && play == true && drawTower == false){
                            drawTower = true;
                            nbTower = 2;
                            menuTowerPosX = 414;
                            menuTowerPosY = 945;
                        }

                        // Tour 3
                        if( events.button.x > 743 && events.button.x < 902 && events.button.y > 629 && events.button.y < 701 && play == true && drawTower == false){
                            drawTower = true;
                            nbTower = 3;
                            menuTowerPosX = 743;
                            menuTowerPosY = 629;
                        }
                        // Tour 4
                        if( events.button.x > 975 && events.button.x < 1113 && events.button.y > 393 && events.button.y < 477 && play == true && drawTower == false){
                            drawTower = true;
                            nbTower = 4;
                            menuTowerPosX = 975;
                            menuTowerPosY = 393;
                        }
                        // Tour 5
                        if( events.button.x > 1133 && events.button.x < 1238 && events.button.y > 663 && events.button.y < 741 && play == true && drawTower == false){
                            drawTower = true;
                            nbTower = 5;
                            menuTowerPosX = 1133;
                            menuTowerPosY = 663;
                        }
                        // Tour 6
                        if( events.button.x > 1238 && events.button.x < 1390 && events.button.y > 956 && events.button.y < 1028 && play == true && drawTower == false){
                            drawTower = true;
                            nbTower = 6;
                            menuTowerPosX = 1238;
                            menuTowerPosY = 956;
                        }
                        // Tour 7
                        if( events.button.x > 1640 && events.button.x < 1800 && events.button.y > 956 && events.button.y < 1030 && play == true && drawTower == false){
                            drawTower = true;
                            nbTower = 7;
                            menuTowerPosX = 1440;
                            menuTowerPosY = 956;
                        }
                        // Tour 8
                        if( events.button.x > 1350 && events.button.x < 1515 && events.button.y > 353 && events.button.y < 432 && play == true && drawTower == false){
                            drawTower = true;
                            nbTower = 8;
                            menuTowerPosX = 1350;
                            menuTowerPosY = 353;
                        }
                        // Tour 9
                        if( events.button.x > 1674 && events.button.x < 1826 && events.button.y > 437 && events.button.y < 510 && play == true && drawTower == false){
                            drawTower = true;
                            nbTower = 9;
                            menuTowerPosX = 1440;
                            menuTowerPosY = 437;
                        }

                        // Quitter Upgrade
                        if( events.button.x > (menuTowerPosX+278) && events.button.x < (menuTowerPosX+323) && events.button.y > (menuTowerPosY-275) && events.button.y < (menuTowerPosY-250) && drawTower == true){
                            if(nbTower == 2 && tower2level >= 1) {drawTower = false;}
                            if(nbTower == 3 && tower3level >= 1) {drawTower = false;}
                            if(nbTower == 4 && tower4level >= 1) {drawTower = false;}
                            if(nbTower == 5 && tower5level >= 1) {drawTower = false;}
                            if(nbTower == 6 && tower6level >= 1) {drawTower = false;}
                            if(nbTower == 7 && tower7level >= 1) {drawTower = false;}
                            if(nbTower == 8 && tower8level >= 1) {drawTower = false;}
                            if(nbTower == 9 && tower9level >= 1) {drawTower = false;}
                        }

                        //Quitter Tour
                          if( events.button.x > (menuTowerPosX+450) && events.button.x < (menuTowerPosX+475) && events.button.y > (menuTowerPosY-280) && events.button.y < (menuTowerPosY-235) && drawTower == true){
                            if(nbTower == 2 && tower2level == 0){drawTower = false;} 
                            if(nbTower == 3 && tower3level == 0){drawTower = false;} 
                            if(nbTower == 4 && tower4level == 0){drawTower = false;} 
                            if(nbTower == 5 && tower5level == 0){drawTower = false;} 
                            if(nbTower == 6 && tower6level == 0){drawTower = false;} 
                            if(nbTower == 7 && tower7level == 0){drawTower = false;} 
                            if(nbTower == 8 && tower8level == 0){drawTower = false;} 
                            if(nbTower == 9 && tower9level == 0){drawTower = false;} 
                        }
                    }
            }   
        }
        if(menu == false && end == false){
            SDLAff();
            quitButton.draw(renderer, 1840, 30, WIDTH_PAUSE_BUTTON, HEIGHT_PAUSE_BUTTON);
            settingsButton.draw(renderer, 1770, 30, WIDTH_PAUSE_BUTTON, HEIGHT_PAUSE_BUTTON);
            game.autoEvents();
            if (drawTower == true) {
                if(nbTower==2) {
                    if(tower2level == 0) {affMenuTower (nbTower,menuTowerPosX,menuTowerPosY); }
                    if(tower2level == 1) {affMenuTowerUpgrade1 (nbTower,menuTowerPosX,menuTowerPosY);}
                    if(tower2level == 2) {affMenuTowerUpgrade2 (nbTower,menuTowerPosX,menuTowerPosY);}
                    if(tower2level == 3) {affMenuTowerUpgrade3 (nbTower,menuTowerPosX,menuTowerPosY);}
                    if(tower2level > 3) {affMenuTowerUpgradeMax(nbTower,menuTowerPosX,menuTowerPosY);}
                }
                if(nbTower==3) {
                    if(tower3level == 0) {affMenuTower (nbTower,menuTowerPosX,menuTowerPosY); }
                    if(tower3level == 1) {affMenuTowerUpgrade1 (nbTower,menuTowerPosX,menuTowerPosY);}
                    if(tower3level == 2) {affMenuTowerUpgrade2 (nbTower,menuTowerPosX,menuTowerPosY);}
                    if(tower3level == 3) {affMenuTowerUpgrade3 (nbTower,menuTowerPosX,menuTowerPosY);}
                    if(tower3level > 3) {affMenuTowerUpgradeMax(nbTower,menuTowerPosX,menuTowerPosY);}   
                }
                if(nbTower==4) {
                    if(tower4level == 0) {affMenuTower (nbTower,menuTowerPosX,menuTowerPosY); }
                    if(tower4level == 1) {affMenuTowerUpgrade1 (nbTower,menuTowerPosX,menuTowerPosY);}  
                    if(tower4level == 2) {affMenuTowerUpgrade2 (nbTower,menuTowerPosX,menuTowerPosY);}
                    if(tower4level == 3) {affMenuTowerUpgrade3 (nbTower,menuTowerPosX,menuTowerPosY);}
                    if(tower4level > 3) {affMenuTowerUpgradeMax(nbTower,menuTowerPosX,menuTowerPosY);}   
                }
                if(nbTower==5) {
                    if(tower5level == 0) {affMenuTower (nbTower,menuTowerPosX,menuTowerPosY); }
                    if(tower5level == 1) {affMenuTowerUpgrade1 (nbTower,menuTowerPosX,menuTowerPosY);}
                    if(tower5level == 2) {affMenuTowerUpgrade2 (nbTower,menuTowerPosX,menuTowerPosY);}
                    if(tower5level == 3) {affMenuTowerUpgrade3 (nbTower,menuTowerPosX,menuTowerPosY);}
                    if(tower5level > 3) {affMenuTowerUpgradeMax(nbTower,menuTowerPosX,menuTowerPosY);}   
                }
                if(nbTower==6) {
                    if(tower6level == 0) {affMenuTower (nbTower,menuTowerPosX,menuTowerPosY); }
                    if(tower6level == 1) {affMenuTowerUpgrade1 (nbTower,menuTowerPosX,menuTowerPosY);}
                    if(tower6level == 2) {affMenuTowerUpgrade2 (nbTower,menuTowerPosX,menuTowerPosY);}
                    if(tower6level == 3) {affMenuTowerUpgrade3 (nbTower,menuTowerPosX,menuTowerPosY);}
                    if(tower6level > 3) {affMenuTowerUpgradeMax(nbTower,menuTowerPosX,menuTowerPosY);}   
                }
                if(nbTower==7) {
                    if(tower7level == 0) {affMenuTower (nbTower,menuTowerPosX,menuTowerPosY); }
                    if(tower7level == 1) {affMenuTowerUpgrade1 (nbTower,menuTowerPosX,menuTowerPosY);}
                    if(tower7level == 2) {affMenuTowerUpgrade2 (nbTower,menuTowerPosX,menuTowerPosY);}
                    if(tower7level == 3) {affMenuTowerUpgrade3 (nbTower,menuTowerPosX,menuTowerPosY);}
                    if(tower7level > 3) {affMenuTowerUpgradeMax(nbTower,menuTowerPosX,menuTowerPosY);}   
                }
                if(nbTower==8) {
                    if(tower8level == 0) {affMenuTower (nbTower,menuTowerPosX,menuTowerPosY); }
                    if(tower8level == 1) {affMenuTowerUpgrade1 (nbTower,menuTowerPosX,menuTowerPosY);}
                    if(tower8level == 2) {affMenuTowerUpgrade2 (nbTower,menuTowerPosX,menuTowerPosY);}
                    if(tower8level == 3) {affMenuTowerUpgrade3 (nbTower,menuTowerPosX,menuTowerPosY);}
                    if(tower8level > 3) {affMenuTowerUpgradeMax(nbTower,menuTowerPosX,menuTowerPosY);}   
                }
                if(nbTower==9) {
                    if(tower9level == 0) {affMenuTower (nbTower,menuTowerPosX,menuTowerPosY); }
                    if(tower9level == 1) {affMenuTowerUpgrade1 (nbTower,menuTowerPosX,menuTowerPosY);}
                    if(tower9level == 2) {affMenuTowerUpgrade2 (nbTower,menuTowerPosX,menuTowerPosY);}
                    if(tower9level == 3) {affMenuTowerUpgrade3 (nbTower,menuTowerPosX,menuTowerPosY);}
                    if(tower9level > 3) {affMenuTowerUpgradeMax(nbTower,menuTowerPosX,menuTowerPosY);}   
                }
            }

            //usleep(10000);
        } 
        if(game.castle.getPV() <= 0) {
            endGame();
            end = true;
            play = false;
        }
        
        if( menu == true){
            affMenuPrinc();
            shopButton.draw(renderer, 1770, 30, WIDTH_PAUSE_BUTTON, HEIGHT_PAUSE_BUTTON);
        }
        if(settings == true){
            affSettings();
        }
        if(info == true){
            affInfo();
        }
        if(shop == true){
            affShop();
        }
        
        SDL_RenderPresent(renderer);
    }
    
}

void AppSDL::SDLAffQuit(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit(); // Quit image
    TTF_Quit(); // Quit police
    SDL_CloseAudio(); // QUit Audio
    Mix_CloseAudio();
    SDL_Quit();
}

void AppSDL::run(){
    SDLAffInit();
    SDLAffLoop();
}

void AppSDL::affMenuPrinc(){
    menuPrinc.draw(renderer, 0, 0, WIDTH_WINDOW, HEIGHT_WINDOW);
}

void AppSDL::endGame(){
    menuPerdu.draw(renderer, (WIDTH_WINDOW/2)-(WIDTH_MENU_PERDU/2), (HEIGHT_WINDOW/2)-(HEIGHT_MENU_PERDU/2), WIDTH_MENU_PERDU, HEIGHT_MENU_PERDU);
}

void AppSDL::playSound(Mix_Music* music, const char* filename) {

    if (Mix_OpenAudio(96000, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) < 0){
        SDL_Log("Erreur initialisation SDL_mixer : %s", Mix_GetError());
        SDL_Quit();
        exit(1);
    }

    music = Mix_LoadMUS(filename);

    if (music == nullptr){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Erreur chargement de la musique : %s", Mix_GetError());
        Mix_CloseAudio();
        SDL_Quit();
        exit(1);
    }

    Mix_PlayMusic(music, -1);


}


void AppSDL::affMenuTower(int n, int posX, int posY) {
    MenuBuy.draw(renderer, posX, posY-300, WIDTH_WINDOW/4, HEIGHT_WINDOW/4);
}

void AppSDL::affMenuTowerUpgrade1(int n, int posX, int posY) {
    MenuUpgrade1.draw(renderer, posX, posY-300, WIDTH_WINDOW/6, HEIGHT_WINDOW/6);
}
void AppSDL::affMenuTowerUpgrade2(int n, int posX, int posY) {
    MenuUpgrade2.draw(renderer, posX, posY-300, WIDTH_WINDOW/6, HEIGHT_WINDOW/6);
}
void AppSDL::affMenuTowerUpgrade3(int n, int posX, int posY) {
    MenuUpgrade3.draw(renderer, posX, posY-300, WIDTH_WINDOW/6, HEIGHT_WINDOW/6);
}
void AppSDL::affMenuTowerUpgradeMax(int n, int posX, int posY) {
    MenuUpgradeMax.draw(renderer, posX, posY-300, WIDTH_WINDOW/6, HEIGHT_WINDOW/6);
}

void AppSDL::affInfo(){
    menuInfo.draw(renderer, 380, 200, WIDTH_WINDOW*0.6, HEIGHT_WINDOW*0.7); 
}

void AppSDL::affShop(){
    menuShop.draw(renderer, 380, 200, WIDTH_WINDOW*0.6, HEIGHT_WINDOW*0.7); 
}

void AppSDL::affSettings(){
    menuSettings.draw(renderer, 1770, 30, WIDTH_PAUSE_BUTTON, HEIGHT_PAUSE_BUTTON*3); 
}

bool AppSDL::pause(){
    ImageSDL pauseMessage, continueButton, quitButton;
    SDL_Color color = {255, 255, 255};
    SDL_Event event;
    int x = 0, y = 0;
    bool quit = false, returnFalse = false;

    pauseMessage.write(renderer, "PAUSED", font, "font/futura/Futura Bold font.ttf", 60, color, WIDTH_WINDOW/2 - 100, 50, 200, 100);
    continueButton.write(renderer, "Continue Game", font, "font/futura/Futura Bold font.ttf", 50, color, WIDTH_WINDOW/2 - 150, HEIGHT_WINDOW/2 - 100, 300, 100);
    quitButton.write(renderer, "Quit", font, "font/futura/Futura Bold font.ttf", 50, color, WIDTH_WINDOW/2 - 75, HEIGHT_WINDOW/2, 150, 100);

    while (!quit)
    {
        while(SDL_PollEvent(&event)){
            switch(event.type)
            {
                case SDL_QUIT:
                    returnFalse = true;
                    quit = true;
                    break;
                case SDL_MOUSEBUTTONUP:
                    x = event.button.x;
                    y = event.button.y;

                    if ((x > WIDTH_WINDOW/2 - 150) && (x < WIDTH_WINDOW/2 + 150) && (y > HEIGHT_WINDOW/2 - 100) && (y < HEIGHT_WINDOW/2)){
                        quit = true;
                    }
                    else if ((x > WIDTH_WINDOW/2 - 150 ) && (x < WIDTH_WINDOW/2 + 150) && (y > HEIGHT_WINDOW/2) && (y < HEIGHT_WINDOW/2 + 100)){
                        returnFalse = true;
                        quit = true;
                    }
                    break;
            }
            SDL_RenderPresent(renderer);
        }
    }

    if (returnFalse)
        return false;

    return true;
}
