#ifndef _ENTITY_SDL_H_
#define _ENTITY_SDL_H_

#include "ImageSDL.h"

#include <iostream>
using namespace std;



class EntitySDL: public ImageSDL{
    private:

    public:

        // AppSDL app;

        SDL_Texture *texture;
        SDL_Surface *surface;
        SDL_Rect src_rect;
        SDL_Rect dst_rect;

        const char* path;

        EntitySDL();
        ~EntitySDL();

        void show(SDL_Renderer* renderer);
};

#endif // _ENTITYSDL_H_