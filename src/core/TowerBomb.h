/**

* \file TowerBomb.h
* \brief Définition des donées membres et des fonctions membres de la class TowerBomb
* \version 1.0
* \date 4 Avril 2022
* \include Entity.h

*/

#ifndef _TOWERBOMB_H_
#define _TOWERBOMB_H_
#include "Tower.h"


/** \brief Classe gérant les tours d'archer /!\ Hérite de la classe Entity /!\ */
class TowerBomb : public Tower{
    private :

    public:
        /** \brief Constructeur par défaut de la classe TowerArcher */
        TowerBomb();
        /** \brief Destructeur par défaut de la classe TowerArcher */
        ~TowerBomb();
};






#endif