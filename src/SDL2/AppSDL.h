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
#ifndef APPSDL_H__
#define APPSDL_H__

#include <string>
#include <assert.h>
#include <time.h>
#include <stdlib.h>

// #include "../core/Castle.h"
// #include "../core/Enemy.h"
// #include "../core/Entity.h"
// #include "../core/Projectile.h"
// #include <GLFW/glfw3.h>
// #include "../lib/imgui/imgui_impl_sdl.h"
// #include "../lib/imgui/imgui_impl_opengl3.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "../SDL2/ImageSDL.h"

#include "../core/Game.h"

/** \brief Constante de la largeur de la fenêtre SDL */
#define WIDTH_WINDOW 1920

/** \brief Constante de la hauteur de la fenêtre SDL */
#define HEIGHT_WINDOW 1080

#define HEIGHT_ENEMY 70
#define WIDTH_ENEMY 70

#define HEIGHT_TOWER 300
#define WIDTH_TOWER 300

#define HEIGHT_PROJECTILE 30
#define WIDTH_PROJECTILE 30

#define WIDTH_CASTLE 320
#define HEIGHT_CASTLE 320

#define HEIGHT_PAUSE_BUTTON 60
#define WIDTH_PAUSE_BUTTON 60

#define WIDTH_PVCASTLE 170
#define HEIGHT_PVCASTLE 60

#define WIDTH_COINS 220
#define HEIGHT_COINS 70

#define WIDTH_MENU_PERDU 600
#define HEIGHT_MENU_PERDU 600

class AppSDL {
    private:

        /** \brief Fonctions gérant l'affichage avec SDL */
        void SDLAffInit();
        void SDLAffLoop();
        void SDLAffQuit();
        void SDLAff(); //Nom provisoire

        ImageSDL background; //!\ Déclarer en Map et faire l'affichage de la map en ajoutant un path à la map /!\*/
        ImageSDL menuPrinc;
        ImageSDL menuPerdu;
        ImageSDL quitButton;
        ImageSDL textGold;
        ImageSDL textPvCastle;
        ImageSDL infoButton;
        ImageSDL menuInfo;
        ImageSDL shopButton;
        ImageSDL menuShop;
        ImageSDL settingsButton;
        ImageSDL menuSettings;

        ImageSDL castleImage1;
        ImageSDL castleImage2;
        ImageSDL castleImage3;

        ImageSDL coins;
        ImageSDL PVCastle;

        ImageSDL MenuBuy;
        ImageSDL MenuUpgrade1;
        ImageSDL MenuUpgrade2;
        ImageSDL MenuUpgrade3;
        ImageSDL MenuUpgradeMax;

    public:
        Game game;

        /** \param Paramètres permettant la création d'une fenêtre SDL*/
        SDL_Window * window;

        /** \param Paramètres permettant la création d'un rendu SDL*/
        SDL_Renderer *renderer;

        TTF_Font* font;

        SDL_Color color = {255, 255 ,255};

        Mix_Music* music;

        /** \brief Constructeur par défaut de la classe jeu*/
        AppSDL ();

        /** \brief Destructeur de la classe jeu */
        ~AppSDL ();

        /** \brief Fonction qui effectue le lancement de l'application */
        void run();

        void fontInit();

        void playSound(Mix_Music* music, const char* filename);

        void affMenuTower(int n, int posx, int posy);
        void affMenuTowerUpgrade1(int n, int posx, int posy);
        void affMenuTowerUpgrade2(int n, int posx, int posy);
        void affMenuTowerUpgrade3(int n, int posx, int posy);
        void affMenuTowerUpgradeMax(int n, int posx, int posy);

         /** \brief Procédure qui affiche la page d'acceuil donc le menu principal */
        void affMenuPrinc();

        /** \brief Procédure qui affiche la page relié aux infos concernant les tours et leur niveau */
        void affInfo();

        /** \brief Procédure qui affiche la page de la boutique */
        void affShop();

        /** \brief Procédure qui affiche les parametres du jeu*/
        void affSettings();

        void endGame();

        bool pause();


};

#endif