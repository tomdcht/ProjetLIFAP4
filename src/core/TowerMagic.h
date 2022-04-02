/**
 * \file TowerMagic.h
 * \author Aline.S
 * \version 0.0
 * \date 15 mars 2022
 */

#ifndef _TOWER_MAGIC_H_
#define _TOWER_MAGIC_H_
#include <iostream>
#include "Entity.h"

class TowerMagic : public Entity{
    private :
        int range;
        int price;

    public:
        TowerMagic();
        ~TowerMagic();
        void setRange(int range);
        int getRange() const;

        void setPrice(int _price);
        int getPrice() const;

};






#endif