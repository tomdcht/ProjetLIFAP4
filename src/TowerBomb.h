#ifndef _TOWER_BOMB_H_
#define _TOWER_BOMB_H_
#include <iostream>
#include "Entity.h"

class TowerBomb : public Entity{
    private :
        int range;
        int price;

    public:
        TowerBomb();
        ~TowerBomb();
        void setRange(int range);
        int getRange() const;

        void setPrice(int _price);
        int getPrice() const;

};






#endif