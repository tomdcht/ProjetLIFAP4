/**

* \file Projectile.h
* \brief Définition des donées membres et des fonctions membres de la classe Projectile
* \version 1.0
* \date 4 Avril 2022
* \include Entity.h, Enemy.h, Tower.h

*/


#ifndef _PROJECTILE_H_
#define _PROJECTILE_H_
#include "Entity.h"
#include "Enemy.h"
#include "Tower.h"
#include <iostream>

/** \brief Classe gérant les projectiles /!\ Hérite de la classe Entity /!\ */
class Projectile : public Entity{
    private:

        /** \brief Le temps qu'un projectile mets à atteindre sa cible */
        int time;
        /** \brief Nouvelle position en x d'un projectile */
        float projectileAvancementX;
        /** \brief Nouvelle position en y d'un projectile */
        float projectileAvancementY;
        /** \brief Direction du projectile en x */
        float _projectileDirectionX;
        /** \brief Direction du projectile en y */
        float _projectileDirectionY;

    public:

        /** \brief Booléen permettant de savoir si une tour est en train de tirer */
        bool tracking;

        /** \brief Booléen permettant de savoir si un ennemi est à portée */
        bool _inRange;

        /** \brief Suppression du projectile après un temps donné */
        int timeDelete;

        /** \brief Constructeur par défaut de la classe Projectile */
        Projectile();
        /** \brief Destructeur par défaut de la classe Projectile */
        ~Projectile();

        Projectile(const Tower& towerArch);

        void fctPath(const char* lien);

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
        const float projectileDirectionX(const Enemy& enemy, const Tower& tower, Road& road);

        /** \brief Fonction calculant la direction en y depuis une tour vers un ennemi
         *  \param enemy Un ennemi
         *  \param tower Une tour d'archer
        */
        const float projectileDirectionY(const Enemy& enemy, const Tower& tower, Road& road);



        /** \brief Fonction calculant toutes les positions nécessaires au projectile entre une tour et un ennemi
         *  \param enemy Un ennemi
         *  \param towerArch Une tour d'archer
        */
        void track(Enemy& enemy, const Tower& towerArch, Road& road);

        /** \brief Fonction modifiant la donnée membre inRange en fonction de la distance entre un ennemi et une tour
         *  \param enemy Un ennemi
         *  \param tower Une tour d'archer
        */
        void inRange(const Enemy& enemy, const Tower& tower);

        /** \brief Fonction calculant la distance depuis une tour jusqu'à un ennemi
         *  \param enemy Un ennemi
         *  \param tower Une tour d'archer
        */
        const float projectileDistance(const float enemy_x, const float enemy_y, const Tower& tower );

        /** \brief Fonction renvoyant true si l'ennemi est touché par un projectil*/
        const bool touch ();
};



#endif