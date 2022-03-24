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