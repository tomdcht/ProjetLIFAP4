/**
 * \file Tower.h
 * \author Aline.S
 * \version 1.0
 * \date 15 mars 2022
 */

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
        void setTower();
        int getTower();
};

#endif