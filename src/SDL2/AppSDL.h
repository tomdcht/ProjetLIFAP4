/**
* \file AppSDL.h
* \brief
* \version 1.0
* \date 22 Mars 2022
* \include Castle.h
* \include Enemy.h
* \include Entity.h
* \include Projectile.h
* \include Tower.h
* \include Vec.h
*/

#include <string>
#include <assert.h>
#include <time.h>
#include <stdlib.h>

#include "../core/Castle.h"
#include "../core/Enemy.h"
#include "../core/Entity.h"
#include "../core/Projectile.h"
#include "../core/Tower.h"
#include "../core/Game.h"

// #include <GLFW/glfw3.h>
// #include "../lib/imgui/imgui_impl_sdl.h"
// #include "../lib/imgui/imgui_impl_opengl3.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>


/** \brief Constante de la largeur de la fenêtre SDL */
#define WIDTH_WINDOW 1920

/** \brief Constante de la hauteur de la fenêtre SDL */
#define HEIGHT_WINDOW 1080

#define HEIGHT_ENEMY 70

#define WIDTH_ENEMY 70

#define HEIGHT_TOWER 300

#define WIDTH_TOWER 300

#define HEIGHT_PROJECTILE 20

#define WIDTH_PROJECTILE 20

/**
 * \class Jeu
 * \brief Class Jeu
 *
 * Déclaration des données membres et des fonctions de la class Jeu
 */

class AppSDL{
    private:

        /** \brief Fonctions gérant l'affichage avec SDL */
        void SDLAffInit();
        void SDLAffLoop();
        void SDLAffQuit();
        void SDLAff(); //Nom provisoire

        Game game;
        ImageSDL background; //!\ Déclarer en Map et faire l'affichage de la map en ajoutant un path à la map /!\*/
        Enemy enemy;
        TowerArcher towerArch;
        Projectile arrow;


    public:

        /** \param Paramètres permettant la création d'une fenêtre SDL*/
        SDL_Window * window;

        /** \param Paramètres permettant la création d'un rendu SDL*/
        SDL_Renderer *renderer;

        // /** \param Paramètres permettant la création d'une surface SDL*/
        // SDL_Surface *picture;

        // /** \param Paramètres permettant la création d'une texture SDL*/
        // SDL_Texture *texture;


        /** \brief Constructeur par défaut de la classe jeu*/
        AppSDL ();

        /** \brief Destructeur de la classe jeu */
        ~AppSDL ();

        /** \brief Fonction qui effectue le lancement de l'application */
        void run();


};