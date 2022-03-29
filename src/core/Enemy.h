#ifndef _ENEMY_H_
#define _ENEMY_H_
#include <iostream>

#include "Entity.h"
#include "Map.h"

class Enemy : public Entity{
    private:


    public:
        Enemy();

        void walk(const Map& map);
};


#endif