/**

* \file TowerMagic.h
* \brief Définition des donées membres et des fonctions membres de la classe TowerMagic
* \version 1.0
* \date 4 Avril 2022
* \include Entity.h

*/

#ifndef _TOWERMAGIC_H_
#define _TOWERMAGIC_H_
#include "Tower.h"


/** \brief Classe gérant les tours d'archer /!\ Hérite de la classe Entity /!\ */
class TowerMagic : public Tower{
    private :

    public:
        /** \brief Constructeur par défaut de la classe TowerArcher */
        TowerMagic();
        /** \brief Destructeur par défaut de la classe TowerArcher */
        ~TowerMagic();
};






#endif