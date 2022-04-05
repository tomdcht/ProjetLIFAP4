/**

* \file TowerArcher.h
* \brief Définition des donées membres et des fonctions membres de la classe TowerArcher
* \version 1.0
* \date 4 Avril 2022
* \include Entity.h

*/


#ifndef _TOWER_H_
#define _TOWER_H_
#include <iostream>
#include "Entity.h"

/** \brief Classe gérant les tours d'archer /!\ Hérite de la classe Entity /!\ */
class TowerArcher : public Entity{
    private :
        /** \brief Portée de la tour d'archer */
        int range;
        /** \brief Prix d'une tour d'archer */
        int price;

    public:

        /** \brief Constructeur par défaut de la classe TowerArcher */
        TowerArcher();
        /** \brief Destructeur par défaut de la classe TowerArcher */
        ~TowerArcher();

        /** \brief Accesseur modifiant la valeur de la donnée membre range
         *  \param range Portée de la tour d'archer
        */
        void setRange(int range);
        /** \brief Accesseur renvoyant la valeur de la donnée membre range */
        int getRange() const;

        /** \brief Accesseur modifiant la valeur de la donnée membre price
         *  \param price Prix de la tour d'archer
        */
        void setPrice(int _price);
        /** \brief Accesseur renvoyant la valeur de la donnée membre price */
        int getPrice() const;
};






#endif