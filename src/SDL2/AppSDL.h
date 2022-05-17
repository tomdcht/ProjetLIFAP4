/**
* \file AppSDL.h
* \brief
* \version 1.0
* \include string
* \include assert.h
* \include time.h
* \include stdlib.h
* \include SDL2/SDL.h
* \include SDL2/SDL_opengl.h
* \include SDL2/SDL_image.h
* \include SDL2/SDL_ttf.h
* \include SDL2/SDL_mixer.h
* \include ../SDL2/ImageSDL.h
* \include ../core/Game.h
*/
#ifndef APPSDL_H__
#define APPSDL_H__

#include <string>
#include <assert.h>
#include <time.h>
#include <stdlib.h>

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

/** \brief Constantes de dimension d'un Ennemi*/ 
#define HEIGHT_ENEMY 70
#define WIDTH_ENEMY 70

/** \brief Constantes de dimension d'une Tour*/ 
#define HEIGHT_TOWER 300
#define WIDTH_TOWER 300

/** \brief Constantes de dimension d'un Projectile*/ 
#define HEIGHT_PROJECTILE 30
#define WIDTH_PROJECTILE 30

/** \brief Constantes de dimension du château*/ 
#define WIDTH_CASTLE 320
#define HEIGHT_CASTLE 320

/** \brief Constantes de dimension du bouton pause*/ 
#define HEIGHT_PAUSE_BUTTON 60
#define WIDTH_PAUSE_BUTTON 60

/** \brief Constantes de dimension du conteneur des PV du château*/ 
#define WIDTH_PVCASTLE 170
#define HEIGHT_PVCASTLE 60

/** \brief Constantes de dimension du conteneur des ressources d'or*/ 
#define WIDTH_COINS 220
#define HEIGHT_COINS 70

/** \brief Constantes de dimension de l'affichage du menu lorsque l'on perd*/
#define WIDTH_MENU_PERDU 600
#define HEIGHT_MENU_PERDU 600

class AppSDL {
    private:

        /** \brief Fonction d'initalisation de la librairie SDL */
        void SDLAffInit();
        /** \brief Fonction d'affichage du jeu et des évenements */
        void SDLAffLoop();
        /** \brief Fonction de libération des fonctions en mémoire de la librairie SDL*/
        void SDLAffQuit();
        /** \brief Fonction d'iaffichage des éléments SDL */
        void SDLAff(); 
        
        /** \brief Image du background*/
        ImageSDL background;
        /** \brief Image de fond du menu principal*/
        ImageSDL menuPrinc;
        /** \brief Image de fond du menu perdu*/
        ImageSDL menuPerdu;
        /** \brief Image du menu perdu*/
        ImageSDL quitButton;
        /** \brief Image du text pour les coins*/
        ImageSDL textGold;
        /** \brief Image du text pour les pv du chateau*/
        ImageSDL textPvCastle;
        /** \brief Image du button info*/
        ImageSDL infoButton;
        /** \brief Image du menu info*/
        ImageSDL menuInfo;
        /** \brief Image du button shop*/
        ImageSDL shopButton;
        /** \brief Image du menu shop*/
        ImageSDL menuShop;
        /** \brief Image du button settings*/
        ImageSDL settingsButton;
        /** \brief Image du menu settings*/
        ImageSDL menuSettings;

        /** \brief Image du chateau 1 */
        ImageSDL castleImage1;
        /** \brief Image du chateau 2 */
        ImageSDL castleImage2;
        /** \brief Image du chateau 3 */
        ImageSDL castleImage3;

        /** \brief Image du menu pour les coins en jeu */
        ImageSDL coins;
        /** \brief Image du menu pour les pv du chateau */
        ImageSDL PVCastle;

        /** \brief Image du menu pour acheter les tours */
        ImageSDL MenuBuy;  
        /** \brief Image du menu pour la 1ere amélioration de la tour */ 
        ImageSDL MenuUpgrade1;
        /** \brief Image du menu pour la 2e amélioration de la tour */ 
        ImageSDL MenuUpgrade2;
        /** \brief Image du menu pour la 3e amélioration de la tour */ 
        ImageSDL MenuUpgrade3;
        /** \brief Image du menu pour le max */ 
        ImageSDL MenuUpgradeMax;

    public:
        Game game;

        /** \brief Paramètres permettant la création d'une fenêtre SDL*/
        SDL_Window * window;

        /** \brief Paramètres permettant la création d'un rendu SDL*/
        SDL_Renderer *renderer;
        
        /** \brief Police d'écriture gérée par SDL*/ 
        TTF_Font* font;
        
        /** \brief Couleur SDL*/
        SDL_Color color = {255, 255 ,255};

        /** \brief Classe qui gère les sons sous SDL*/
        Mix_Music* music;

        /** \brief Constructeur par défaut de la classe jeu*/
        AppSDL ();

        /** \brief Destructeur de la classe jeu */
        ~AppSDL ();

        /** \brief Fonction qui effectue le lancement de l'application */
        void run();

        /** \brief Fonction permettant de jouer un son
        *   \param Music La musique sous SDL
        *   \param filename Nom du fichier
        */
        void playSound(Mix_Music* music, const char* filename);

        /** \brief afficher le menu achat de la tour
        *   \param n numero de la tour
        *   \param posx position en x du menu
        *   \param posy position en y du menu
        */
        void affMenuTower(int n, int posx, int posy);

        /** \brief afficher le menu upgrade 1 de la tour
        *   \param n numero de la tour
        *   \param posx position en x du menu
        *   \param posy position en y du menu
        */
        void affMenuTowerUpgrade1(int n, int posx, int posy);

        /** \brief afficher le menu upgrade 3 de la tour
        *   \param n numero de la tour
        *   \param posx position en x du menu
        *   \param posy position en y du menu
        */
        void affMenuTowerUpgrade2(int n, int posx, int posy);

        /** \brief afficher le menu upgrade 3 de la tour
        *   \param n numero de la tour
        *   \param posx position en x du menu
        *   \param posy position en y du menu
        */
        void affMenuTowerUpgrade3(int n, int posx, int posy);

        /** \brief afficher le menu upgrade max de la tour
        *   \param n numero de la tour
        *   \param posx position en x du menu
        *   \param posy position en y du menu
        */
        void affMenuTowerUpgradeMax(int n, int posx, int posy);

         /** \brief Procédure qui affiche la page d'acceuil donc le menu principal */
        void affMenuPrinc();

        /** \brief Procédure qui affiche la page relié aux infos concernant les tours et leur niveau */
        void affInfo();

        /** \brief Procédure qui affiche la page de la boutique */
        void affShop();

        /** \brief Procédure qui affiche les parametres du jeu*/
        void affSettings();
        
        /** \brief Fonction affichant le menu de fin de jeu */ 
        void endGame();
        
        /** \brief Fonction qui met en pause le jeu */
        bool pause();


};

#endif