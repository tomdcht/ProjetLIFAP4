#ifndef _TOWER.H_
#define _TOWER.H_
#include <iostream>
#include "Entity.h"

class Tower : public Entity{
    private :
        int range;

    public:
        Tower();
        ~Tower();
        setTower(int PV);
        getTower(itn PV, double posx, double posy);
}






#endif