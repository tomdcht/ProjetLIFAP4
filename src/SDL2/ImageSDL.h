#ifndef _IMAGE_SDL_H_
#define _IMAGE_SDL_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class ImageSDL{
    private:
        SDL_Surface* surface;
        SDL_Texture *texture;

    public:
        /** \brief Constructeur de la class ImageSDL  */ 
        ImageSDL() ;

         /** \brief Booléen permettant de sacoir si une texture à changée*/ 
        bool has_changed = false;

        /** \brief Procédure qui charge une image depuis nos repertoires
         *  \param filename nom du fichier à importer
         *  \param renderer le buffer du rendu **/
        void loadFromFile (const char* filename, SDL_Renderer * renderer);

        /** \brief Procédure  
         *  \param renderer le buffer du rendu **/
        void loadFromCurrentSurface (SDL_Renderer * renderer);

        /** \brief Procédure qui descine une image dans la fenetre 
        *  \param renderer le buffer du rendu 
         *  \param x coordonnées x de l'image
         *  \param y coordonnées y de l'ima **/
        void draw (SDL_Renderer * renderer, int x, int y, int w=-1, int h=-1);

        /** \brief Procédure qui dessine les sprites et prends en compte un rectangle source 
        *   \param
        */
        void draw(SDL_Renderer * renderer, int x_src, int y_src, int w_src, int h_src, int x_dst, int y_dst, int w_dst, int h_dst);

        /** \brief Procédure qui écrit du texte en format SDL  */
        void write(SDL_Renderer* renderer, const char* text, TTF_Font* font, const char* font_name, int font_size, SDL_Color color, int x, int y, int w, int h);

        /** \brief Surface SDl*/
        SDL_Texture * getTexture() const;

        /** \brief Accesseur qui modifie la donnée membre surface */
        void setSurface(SDL_Surface * surf);
};

#endif