/**
* \file AppSDL.cpp
* \brief
* \version 1.0
* \date 22 Mars 2022
* \include AppSDL.h
*/

#include <iostream>
#include <fstream>

#include "AppSDL.h"

using namespace std;


AppSDL::AppSDL(){

}

AppSDL::~AppSDL(){

}

void AppSDL::SDLAffInit(){

    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER) < 0){
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    window = SDL_CreateWindow("LifaPower Defense", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080, SDL_WINDOW_FULLSCREEN_DESKTOP);
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

    //picture = IMG_Load("data/######");
    //if(!picture){
    //    cout << "Erreur concernant le chargement de l'image ! " << SDL_GetError() << endl;
    //    SDL_Quit();
    //    exit(1);
    //}

    //if(SDL_QueryTexture(texture, NULL, NULL, &dest_rect.w, &dest_rect.h) != 0){
    //    cout << "Erreur lors de l'application de la texture ! " << SDL_GetError() << endl;
    //    SDL_Quit();
    //    exit(1);
    //}

    //if(SDL_RenderCopy(renderer, texture, &src_rect, &dest_rect) != 0){
    //    cout << "Erreur lors de l'application du rendu ! " << SDL_GetError() << endl;
    //    SDL_Quit();
    //    exit(1);
    //}

    SDL_RenderPresent(renderer);

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
                    if (events.window.event == SDL_WINDOWEVENT_CLOSE)
                        quit = true; break;
            }
        }
    }
}

void AppSDL::SDLAffQuit(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(picture);
    SDL_Quit();
}

void AppSDL::run(){
    SDLAffInit();
    SDLAffLoop();
}