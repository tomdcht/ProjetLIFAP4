#ifndef _ENEMY.H_
#define _ENEMY.H_
#include "Entity.h"
#include <iostream>

class Enemy : public Entity{
    private:
        //Mouvement : deplacement;

    public:
        Enemy();
        ~Enemy();
        getEnemy(double posx, double posy, int PV);
        setEnemy(int PV);
}


#endif