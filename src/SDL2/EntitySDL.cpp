
#include "EntitySDL.h"


EntitySDL::EntitySDL(){
    src_rect.x = 0; src_rect.y = 0; src_rect.w = 0; src_rect.h = 0;
    texture = NULL;
    surface = NULL;
}

EntitySDL::~EntitySDL(){

}


void EntitySDL::show(SDL_Renderer* renderer){
    surface = IMG_Load(path);
    if(!surface)
    {
        printf("EntitySDL : Erreur de chargement de l'image : %s",SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_RenderClear(renderer);
    if (renderer == NULL){
        std::cout << "EntitySDL : Erreur lors de la création du renderer ! " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(1);
    }

    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    // if(SDL_RenderCopy(renderer, texture, &src_rect, &dst_rect) != 0){
    //    std::cout << " EntityDSL : Erreur lors de l'application du rendu ! " << SDL_GetError() << std::endl;
    //    SDL_Quit();
    //    exit(1);
    // }

    //SDL_RenderPresent(renderer);
}