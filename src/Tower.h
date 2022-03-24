#ifndef _TOWER_H_
#define _TOWER_H_
#include <iostream>
#include "Entity.h"

class Tower : public Entity{
    private :
        int range;

    public:
        Tower();
        ~Tower();
        void setTower(int PV);
        int getTower(int PV);
};

#endif