#ifndef _ENEMY_SDL_H_
#define _ENEMY_SDL_H_
#include <iostream>

#include "EntitySDL.h"
// #include "AppSDL.h"

/** \brief Classe gérant les ennemis  /!\ Hérite de la classe Entity /!\ */
class EnemySDL: public EntitySDL{
    private:

    public:
        //AppSDL app;

        /** \brief Constructeur apr défaut de la classe Enemy */
        EnemySDL();
        /** \brief Destructeur par défaut de la classe Enemy */
        ~EnemySDL();
};

#endif