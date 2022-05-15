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
#include "Road.h"


/** \brief Classe gérant les ennemis  /!\ Hérite de la classe Entity /!\ */
class Enemy : public Entity{
    private:
        /** \brief Booléen permettant de savoir si un ennemi est arrivée au château */
        bool isArrived;

        /** \brief Nouvelle position en x d'un enemy */
        float enemyAvancementX;
        /** \brief Nouvelle position en y d'un enemy */
        float enemyAvancementY;
        /** \brief Direction du enemy en x */
        float _enemyDirectionX;
        /** \brief Direction du enemy en y */
        float _enemyDirectionY;
        /** \brief Distance entre un enemy et sa cible */
        float _enemyDistance;

        /** \brief true si il doit aller au prochain point */
        bool NextPoint;

    public:

        int pointTrack;

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
        void walk(Road& road);

        /** \fn Fonction vérifiant si les PV d'un ennemi sont à 0
         *  \return La donnée membre privée 'isDead'
        */
        bool isDead();

        /** \fn Test de régression de la classe Enemy
         *  \param enemy Un ennemi
         */
        //void regressionTest();

        const float enemyDistance(Road& road) const;

        const float enemyDirectionX(Road& road) const;
        const float enemyDirectionY(Road& road) const;

};


#endif