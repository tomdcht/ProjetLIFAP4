/**

* \file Enemy.h
* \brief Définition des donées membres et des fonctions membres de la classe Enemy
* \version 1.0
* \date 4 Avril 2022
* \include Entity.h, Map.h

*/


#ifndef _ENEMY_H_
#define _ENEMY_H_
#include <iostream>
#include <list>

#include "Entity.h"
#include "Map.h"

/** \brief Classe gérant les ennemis  /!\ Hérite de la classe Entity /!\ */
class Enemy : public Entity{
    private:
        /** \brief Booléen permettant de savoir si un ennemi est arrivée au château */
        bool isArrived;

    public:
        /** \brief Liste d'ennemis */
        std::list<Enemy*> enemies;

        /** \brief Constructeur apr défaut de la classe Enemy */
        Enemy();
        /** \brief Destructeur par défaut de la classe Enemy */
        ~Enemy();

        /** \fn Accesseur modifiant la donnée membre privée 'isArrived' */
        void setIsArrived(bool _isArrived);

        /** \fn Accesseur renvoyant la donnée membre privée 'isArrived' */
        bool getIsArrived();

        /** \fn Fonction permettant de faire avancer un ennemi
         *  \param map La map courante
        */
        void walk(const Map& map);

        /** \fn Fonction vérifiant si les PV d'un ennemi sont à 0
         *  \return La donnée membre privée 'isDead'
        */
        bool isDead();

        /** \fn Test de régression de la classe Enemy
         *  \param enemy Un ennemi
         */
        void regressionTest(Enemy& enemy);
};


#endif