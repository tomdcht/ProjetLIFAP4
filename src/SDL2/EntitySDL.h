#ifndef _ENTITY_SDL_H_
#define _ENTITY_SDL_H_

#include "ImageSDL.h"

#include <iostream>
using namespace std;



class EntitySDL: public ImageSDL{
    private:

    public:

        // AppSDL app;
        /** \brief Structure de Pixels **/
        SDL_Texture *texture;

        /** \brief structure de pixels **/
        SDL_Surface *surface;

         /** \brief  Structure d'un rectangle dont l'ogine est en haut à gauche
        *  \param src_rect rectangle source
         *  \param src_rect rectangle destination **/
        SDL_Rect src_rect;
        SDL_Rect dst_rect;

        /** \brief Chemin du repertoire qui mene à l'image **/
        const char* path;

        /** \brief Constructeur de la classe Entity **/
        EntitySDL();

        /** \brief Destrcuteur de la classe Entiry **/
        ~EntitySDL();


        void show(SDL_Renderer* renderer);
};

#endif // _ENTITYSDL_H_