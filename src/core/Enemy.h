/**
 * \file Enemy.h
 * \author Tom.D
 * \version 1.0
 * \date 15 mars 2022
 */

#ifndef _ENEMY_H_
#define _ENEMY_H_
#include <iostream>
#include <list>

#include "Entity.h"
#include "Map.h"


/** \class Enemy
   * \brief classe representant l'ennemie
   *  La classe gere les fonctions de l'ennemie
*/
class Enemy : public Entity{
    private:
        
        bool isArrived;

    public:
        std::list<Enemy> *enemies;

        Enemy();
        ~Enemy();

        void setIsArrived(bool _isArrived);
        bool getIsArrived();
        void walk(const Map& map);

        bool isDead();

        void walk(const Map& map);
        void appear();
};


#endif