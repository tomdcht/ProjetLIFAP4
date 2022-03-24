#ifndef _ENEMY_H_
#define _ENEMY_H_
#include "Entity.h"
#include <iostream>

class Enemy : public Entity{
    private:
        //Mouvement : deplacement;

    public:
        Enemy();
        ~Enemy();
        int getEnemy(int PV);
        void setEnemy(int PV);
};


#endif