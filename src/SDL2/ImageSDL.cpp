#include "ImageSDL.h"

#include <iostream>
#include <assert.h>
using namespace std;

ImageSDL::ImageSDL () {
    surface = NULL;
    texture = NULL;
    has_changed = false;
}

void ImageSDL::loadFromFile (const char* filename, SDL_Renderer * renderer) {
    surface = IMG_Load(filename);
    if (surface == NULL) {
        string nfn = string("../") + filename;
        cout << "Error: cannot load "<< filename <<". Trying "<<nfn<<endl;
        surface = IMG_Load(nfn.c_str());
        if (surface == NULL) {
            nfn = string("../") + nfn;
            surface = IMG_Load(nfn.c_str());
        }
    }
    if (surface == NULL) {
        cout<<"Error: cannot load "<< filename <<endl;
        exit(1);
    }

    SDL_Surface * surfaceCorrectPixelFormat = SDL_ConvertSurfaceFormat(surface,SDL_PIXELFORMAT_ARGB8888,0);
    SDL_FreeSurface(surface);
    surface = surfaceCorrectPixelFormat;

    texture = SDL_CreateTextureFromSurface(renderer,surfaceCorrectPixelFormat);
    if (texture == NULL) {
        cout << "Error: problem to create the texture of "<< filename<< endl;
        exit(1);
    }
}

void ImageSDL::loadFromCurrentSurface (SDL_Renderer * renderer) {
    texture = SDL_CreateTextureFromSurface(renderer,surface);
    if (texture == NULL) {
        cout << "Error: problem to create the texture from surface " << endl;
        exit(1);
    }
}

void ImageSDL::draw (SDL_Renderer * renderer, int x, int y, int w, int h) {
    int ok;
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = (w<0)?surface->w:w;
    r.h = (h<0)?surface->h:h;

    if (has_changed) {
        ok = SDL_UpdateTexture(texture,NULL,surface->pixels,surface->pitch);
        assert(ok == 0);
        has_changed = false;
    }

    ok = SDL_RenderCopy(renderer,texture,NULL,&r);
    assert(ok == 0);
}

void ImageSDL::draw(SDL_Renderer * renderer, int x_src, int y_src, int w_src, int h_src, int x_dst, int y_dst, int w_dst, int h_dst){
    int ok;
    SDL_Rect dst_rect;
    dst_rect.x = x_dst;
    dst_rect.y = y_dst;
    dst_rect.w = (w_dst<0)?surface->w:w_dst;
    dst_rect.h = (h_dst<0)?surface->h:h_dst;

    SDL_Rect src_rect;
    src_rect.x = x_src;
    src_rect.y = y_src;
    src_rect.w = (w_src<0)?surface->w:w_src;
    src_rect.h = (h_src<0)?surface->h:h_src;

    if (has_changed) {
        ok = SDL_UpdateTexture(texture,&src_rect,surface->pixels,surface->pitch);
        assert(ok == 0);
        has_changed = false;
    }
    has_changed = true;

    ok = SDL_RenderCopy(renderer,texture,&src_rect,&dst_rect);
    assert(ok == 0);
}

void ImageSDL::write(SDL_Renderer* renderer, const char* text, TTF_Font* font, const char* font_name, int font_size, SDL_Color color, int x, int y, int w, int h){
    int ok;
    SDL_Rect dst_rect = {x, y, w, h};
    font = TTF_OpenFont(font_name, font_size);
    surface = TTF_RenderText_Solid(font, text, color);

    texture = SDL_CreateTextureFromSurface(renderer, surface);
    TTF_CloseFont(font);
    SDL_FreeSurface(surface);
    ok = SDL_RenderCopy(renderer,texture, NULL, &dst_rect);
    assert(ok == 0);
}

SDL_Texture * ImageSDL::getTexture() const {return texture;}

void ImageSDL::setSurface(SDL_Surface * surf) {surface = surf;}