/**

* \file TowerArcher.h
* \brief Définition des donées membres et des fonctions membres de la classe TowerArcher
* \version 1.0
* \date 4 Avril 2022
* \include Entity.h

*/

#ifndef _TOWERARCHER_H_
#define _TOWERARCHER_H_
#include "Tower.h"


/** \brief Classe gérant les tours d'archer /!\ Hérite de la classe Entity /!\ */
class TowerArcher : public Tower{
    private :

    public:
        /** \brief Constructeur par défaut de la classe TowerArcher */
        TowerArcher();
        /** \brief Destructeur par défaut de la classe TowerArcher */
        ~TowerArcher();
};






#endif