/**
 * \file Projectile.h
 * \author Allan.D, Aline.S
 * \version 2.0
 * \date 2 avril 2022
 */

#ifndef _PROJECTILE_H_
#define _PROJECTILE_H_
#include "Entity.h"
#include "Enemy.h"
#include "TowerArcher.h"
#include <iostream>


/** \class Projectile
   * \brief class representant les projectiles
*/
class Projectile : public Entity{
        private:

        TowerArcher towerArch;
        int time;
        bool tracking;
        bool _inRange;

        float avancementX, avancementY, _DirectionX, _DirectionY, _Distance;



        public:

             /** \fn Constructeur par défaut
            *  \brief Constructeur de la classe **/
            Projectile();

            /** \fn Constructeur du projectile
            *  \brief Constructeur d'un projectile en fonction du type de la tour
            * \param towerArch tour **/
            Projectile(const TowerArcher& towerArch);

            /** \fn Destructeur par défaut
            *  \brief Destructeur de la classe **/
            ~Projectile();

            int getProjectile(int damage);
            void setProjectile(int damage);

            void setTime(int _time);
            const int getTime();


            const float directionX(const Enemy& enemy, const TowerArcher& tower);
            const float directionY(const Enemy& enemy, const TowerArcher& tower);

            const float distance(const Enemy& x, const TowerArcher& y);

            void track(Enemy& enemy, const TowerArcher& towerArch);

            void inRange(const Enemy& enemy, const TowerArcher& towerArch);
            const bool isInRange() const;

            const bool touch ();

};



#endif