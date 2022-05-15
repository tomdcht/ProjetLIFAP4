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

    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER) < 0){
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
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
    quitButton.loadFromFile("data/Button/pauseButton.png", renderer);

    // fontInit();

    
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
        }
        game.newProjectile1 = false; 
    }

    if (game.newProjectile2 == true) {
        for(int n = 0 ; n < game.getSizeListProjectile(2); n++){
            game.getItProjectile(game.projectiles2, n)->loadFromFile(game.getItProjectile(game.projectiles2, n)->path, renderer);
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
        game.getItEnemy(game.enemies, n)->draw(renderer, 370*spriteEnemy, 0, 341, 370, game.getItEnemy(game.enemies, n)->getPosX()-(WIDTH_ENEMY/2), game.getItEnemy(game.enemies, n)->getPosY()-(HEIGHT_ENEMY/2), WIDTH_ENEMY, HEIGHT_ENEMY);
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

    coins.draw(renderer, 20, 20, WIDTH_COINS, HEIGHT_COINS);
    PVCastle.draw(renderer, 250, 26, WIDTH_PVCASTLE, HEIGHT_PVCASTLE);

    // printF("Hello World", 10, 10);

}

void AppSDL::SDLAffLoop(){
    SDL_Event events;
	bool quit = false;
    bool menu = true;

    while (!quit) {
        while(SDL_PollEvent(&events)){
            switch (events.type) {
                case SDL_KEYDOWN:
                    if(events.key.keysym.scancode == SDL_SCANCODE_ESCAPE){
                        cout << "Fermeture de la fenêtre" << endl;
                        SDLAffQuit();
                        quit = true; break;
                    }
                    if(events.key.keysym.scancode == SDL_SCANCODE_V){
                        game.addTowerArch();
                    }
                    if(events.key.keysym.scancode == SDL_SCANCODE_B){
                        game.addTowerBomb();
                    }
                    if(events.key.keysym.scancode == SDL_SCANCODE_N){
                        game.addTowerMagic();
                    }
                    break;

                case SDL_KEYUP:

                case SDL_WINDOWEVENT:
                    if (events.window.event == SDL_WINDOWEVENT_CLOSE){
                        quit = true; break;
                    }

                case SDL_MOUSEBUTTONDOWN:
                    if(events.button.button == SDL_BUTTON_LEFT){
                        if( events.button.x > 855 && events.button.x < 1060 && events.button.y > 546 && events.button.y < 599 ){
                            menu = false;

                        }
                        
                        if( events.button.x > 1840 && events.button.x < 1890 && events.button.y > 30 && events.button.y < 78 ){
                            quit = true; break;
                        }
                    }
            }
        }

        if(menu == false){
            SDLAff();
            quitButton.draw(renderer, 1840, 30, WIDTH_PAUSE_BUTTON, HEIGHT_PAUSE_BUTTON);
            game.autoEvents();
            usleep(10000);
        }
        if( menu == true){
            affMenuPrinc();
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
    SDL_Quit();
}

void AppSDL::run(){
    SDLAffInit();
    SDLAffLoop();
}

void AppSDL::affMenuPrinc(){
    menuPrinc.draw(renderer, 0, 0, WIDTH_WINDOW, HEIGHT_WINDOW);
}


// void AppSDL::fontInit(){
//         TTF_Init();
//         font = TTF_OpenFont("arial.ttf", 12);
//         fColor.r = 255;
//         fColor.g = 255;
//         fColor.b = 255;
// }

// void AppSDL::printF(char *c, int x, int y){
//         fontSurface = TTF_RenderText_Solid(font, c, fColor);
//         fontRect.x = x;
//         fontRect.y = y;
//         SDL_BlitSurface(fontSurface, NULL, fontSurface, &fontRect);
//         SDL_Flip(fontSurface);
// }