#include "EntitySDL.h"

EntitySDL::EntitySDL(){

}

EntitySDL::~EntitySDL(){

}


void EntitySDL::Show(const char* img){
    SDL_Surface* image = IMG_Load(img);
    if(!image)
    {
        printf("Erreur de chargement de l'image : %s",SDL_GetError());
        exit(EXIT_FAILURE);
    }
}