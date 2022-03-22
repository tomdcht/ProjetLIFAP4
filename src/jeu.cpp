
#include "Jeu.h"
#include <iostream>
using namespace std;

Jeu::Jeu(){

}

Jeu::~Jeu(){

}

void Jeu::SDLAffInit(){

    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    window = SDL_CreateWindow("SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH_WINDOW, HEIGHT_WINDOW, 0);
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

    texture = SDL_CreateTextureFromSurface(renderer, picture);
    SDL_FreeSurface(picture);
    if(!texture){
        cout << "Erreur concernant la création de la texture ! " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    if(SDL_QueryTexture(texture, NULL, NULL, &dest_rect.w, &dest_rect.h) != 0){
        cout << "Erreur lors de l'application de la texture ! " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    if(SDL_RenderCopy(renderer, texture, &src_rect, &dest_rect) != 0){
        cout << "Erreur lors de l'application du rendu ! " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    SDL_RenderPresent(renderer);

}

void Jeu::SDLAffLoop(){
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

void Jeu::SDLAffQuit(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(picture);
    SDL_Quit();
}

void Jeu::run(){
    SDLAffInit();
    SDLAffLoop();
}


int main(){
    jeu.run();
    return 0;
}