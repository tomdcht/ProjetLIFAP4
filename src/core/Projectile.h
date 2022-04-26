/**

* \file Projectile.h
* \brief Définition des donées membres et des fonctions membres de la classe Projectile
* \version 1.0
* \date 4 Avril 2022
* \include Entity.h, Enemy.h, TowerArcher.h

*/


#ifndef _PROJECTILE_H_
#define _PROJECTILE_H_

#include "Entity.h"
#include "Enemy.h"
#include "TowerArcher.h"
#include <iostream>

/** \brief Classe gérant les projectiles /!\ Hérite de la classe Entity /!\ */
class Projectile : public Entity{
    private:

        /** \brief Une tour d'archer */
        TowerArcher towerArch;
        /** \brief Le temps qu'un projectile mets à atteindre sa cible */
        int time;
        /** \brief Booléen permettant de savoir si une tour est en train de tirer */
        bool tracking;
        /** \brief Booléen permettant de savoir si un ennemi est à portée */
        bool _inRange;

        /** \brief Nouvelle position en x d'un projectile */
        float avancementX;
        /** \brief Nouvelle position en y d'un projectile */
        float avancementY;
        /** \brief Direction du projectile en x */
        float _DirectionX;
        /** \brief Direction du projectile en y */
        float _DirectionY;
        /** \brief Distance entre un projectile et sa cible */
        float _Distance;

    public:
        /** \brief Constructeur par défaut de la classe Projectile */
        Projectile();
        /** \brief Destructeur par défaut de la classe Projectile */
        ~Projectile();

        Projectile(const TowerArcher& towerArch);

        /** \brief Accesseur renvoyant la valeur de la donnée membre damage */
        int getProjectile(int damage);
        /** \brief Accesseur modifiant la valeur de la donnée membre damage
         *  \param damage Dommage causés par un ennemi
         */
        void setProjectile(int damage);

        /** \brief Accesseur modifiant la valeur de la donnée membre time
         *  \param time Le temps que met un projectile à atteindre sa cible
         */
        void setTime(int _time);
        /** \brief Accesseur renvoyant la valeur de la donnée membre time */
        const int getTime();

        /** \brief Fonction calculant la direction en x depuis une tour vers un ennemi
         *  \param enemy Un ennemi
         *  \param tower Une tour d'archer
        */
        const float directionX(const Enemy& enemy, const TowerArcher& tower);

        /** \brief Fonction calculant la direction en y depuis une tour vers un ennemi
         *  \param enemy Un ennemi
         *  \param tower Une tour d'archer
        */
        const float directionY(const Enemy& enemy, const TowerArcher& tower);



        /** \brief Fonction calculant toutes les positions nécessaires au projectile entre une tour et un ennemi
         *  \param enemy Un ennemi
         *  \param towerArch Une tour d'archer
        */
        void track(Enemy& enemy, const TowerArcher& towerArch);

        /** \brief Fonction modifiant la donnée membre inRange en fonction de la distance entre un ennemi et une tour
         *  \param enemy Un ennemi
         *  \param tower Une tour d'archer
        */
        void inRange(const Enemy& enemy, const TowerArcher& tower);

        /** \brief Fonction renvoyant la valeur de la donnée membre _inRange */
        bool isInRange() const;

        /** \brief Fonction calculant la distance depuis une tour jusqu'à un ennemi
         *  \param enemy Un ennemi
         *  \param tower Une tour d'archer
        */
        const float distance(const float enemy_x, const float enemy_y, const TowerArcher& tower );

        /** \brief Fonction renvoyant true si l'ennemi est touché par un projectil*/
        const bool touch ();
};



#endif