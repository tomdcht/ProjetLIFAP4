#ifndef _ENEMY_H_
#define _ENEMY_H_
#include <iostream>
#include <list>

#include "Entity.h"
#include "Map.h"

class Enemy : public Entity{
    private:
        bool isArrived;

    public:
        std::list<Enemy*> enemies;

        Enemy();
        ~Enemy();

        void setIsArrived(bool _isArrived);
        bool getIsArrived();
        void walk(const Map& map);

        bool isDead();

        // void appear();

        void regressionTest(Enemy& enemy);
};


#endif