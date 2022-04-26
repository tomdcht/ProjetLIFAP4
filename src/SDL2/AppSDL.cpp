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
// #include "EntitySDL.h"
// #include "EnemySDL.h"

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

    window = SDL_CreateWindow("LifaPower Defense", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH_WINDOW, HEIGHT_WINDOW, SDL_WINDOW_FULLSCREEN_DESKTOP);
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


    //IMAGES
    background.loadFromFile("data/Map/PNG/game_background_1/game_background_1.png", renderer);
    enemy.loadFromFile(enemy.path, renderer);
    towerArch.loadFromFile(towerArch.path, renderer);
    //arrow.loadFromFile(arrow.path, renderer);

}

void AppSDL::SDLAff() {

    background.draw(renderer, 0, 0, WIDTH_WINDOW, HEIGHT_WINDOW);
    //cout << "X : " << enemy.getPosX() << "  " << "Y : " << enemy.getPosY() << endl;
    //enemy.draw(renderer, enemy.getPosX(), enemy.getPosY(), WIDTH_ENEMY, HEIGHT_ENEMY);

    int size = enemy.enemies.size();

    towerArch.draw(renderer, towerArch.getConstPosX(), towerArch.getConstPosY(), WIDTH_TOWER, HEIGHT_TOWER);

    //enemy.enemies.front()->draw(renderer, enemy.enemies.front()->getConstPosX(), enemy.enemies.front()->getConstPosY(), WIDTH_ENEMY, HEIGHT_ENEMY);
    // enemy.enemies.push_back(new Enemy);
    // enemy.enemies.back()->draw(renderer, enemy.enemies.back()->getConstPosX() + 50 , enemy.enemies.back()->getConstPosY(), WIDTH_ENEMY, HEIGHT_ENEMY);
    //game.getIt(enemy.enemies, 0)->draw(renderer, game.getIt(enemy.enemies, 0)->getConstPosX(), game.getIt(enemy.enemies, 0)->getConstPosY(), WIDTH_ENEMY, HEIGHT_ENEMY);
    // enemy.enemies.push_back(new Enemy);
    //game.getIt(enemy.enemies, 1)->draw(renderer, game.getIt(enemy.enemies, 1)->getConstPosX(), game.getIt(enemy.enemies, 1)->getConstPosY(), WIDTH_ENEMY, HEIGHT_ENEMY);

    // enemy.enemies.front()->walk();

    // enemy.enemies.back()->walk();

    for (int n = 0; n < size ; n++) {
        game.getIt(enemy.enemies, n)->draw(renderer, game.getIt(enemy.enemies, n)->getConstPosX(), game.getIt(enemy.enemies, n)->getConstPosY(), WIDTH_ENEMY, HEIGHT_ENEMY);
        game.getIt(enemy.enemies, n)->walk();
        game.getIt(enemy.enemies, n)->has_changed = true;
    //     win.print((int)game.getIt(enemy.enemies, n)-> getConstPosX(), (int)game.getIt(enemy.enemies, n)->getConstPosY(), 'X');

    //     if (game.getIt(enemy.enemies, n)->isDead() == true) {
    //         win.print((int)game.getIt(enemy.enemies, n)->getConstPosX(), (int)game.getIt(enemy.enemies, n)->getConstPosY(), ' ');

    //         if (arrow.isInRange() == false) {
    //             win.print((int)arrow.getConstPosX(), (int)arrow.getConstPosY(), ' ');
    //         }
    //     }

    // }
    // game.getIt(enemy.enemies, 0)->draw(renderer, game.getIt(enemy.enemies, 0)->getConstPosX(), game.getIt(enemy.enemies, 0)->getConstPosY(), WIDTH_ENEMY, HEIGHT_ENEMY);
    // game.getIt(enemy.enemies, 1)->draw(renderer, game.getIt(enemy.enemies, 1)->getConstPosX() + 50, game.getIt(enemy.enemies, 1)->getConstPosY(), WIDTH_ENEMY, HEIGHT_ENEMY);

    // if (arrow.isInRange() == true) {
    //     arrow.draw(renderer, arrow.getConstPosX(), arrow.getConstPosY(), WIDTH_PROJECTILE, HEIGHT_PROJECTILE);
    }

    //enemy.has_changed = true;

    // arrow.inRange(enemy, towerArch);

    // if(arrow.isInRange() == true) {
    //     arrow.track(enemy, towerArch);
    //     arrow.draw(renderer, arrow.getPosX(), arrow.getPosY(), WIDTH_PROJECTILE, HEIGHT_PROJECTILE);
    // }

}

void AppSDL::SDLAffLoop(){
    SDL_Event events;
	bool quit = false;

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
            }
        }

        SDLAff();

        game.autoEvents();
        usleep(100000);

        SDL_RenderPresent(renderer);
    }
}

void AppSDL::SDLAffQuit(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void AppSDL::run(){
    SDLAffInit();
    SDLAffLoop();
}