#ifndef _IMAGE_SDL_H_
#define _IMAGE_SDL_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


class ImageSDL{
    private:
        SDL_Surface* surface;
        SDL_Texture *texture;


    public:
        ImageSDL() ;

        bool has_changed = false;


        void loadFromFile (const char* filename, SDL_Renderer * renderer);
        void loadFromCurrentSurface (SDL_Renderer * renderer);
        void draw (SDL_Renderer * renderer, int x, int y, int w=-1, int h=-1);
        SDL_Texture * getTexture() const;
        void setSurface(SDL_Surface * surf);
};

#endif