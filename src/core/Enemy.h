#ifndef _ENEMY_H_
#define _ENEMY_H_
#include <iostream>
#include <list>

#include "Entity.h"
#include "Map.h"

class Enemy : public Entity{
    private:
        bool isArrived;
        bool isDead;

    public:
        std::list<Enemy> *enemies;

        Enemy();
        ~Enemy();

        void setIsArrived(bool _isArrived);
        bool getIsArrived();

        void setIsDead(bool _isDead);
        bool getIsDead();

        void walk(const Map& map);
        void appear();
};


#endif