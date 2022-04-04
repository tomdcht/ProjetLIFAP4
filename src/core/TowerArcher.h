#ifndef _TOWER_H_
#define _TOWER_H_
#include <iostream>
#include "Entity.h"

class TowerArcher : public Entity{
    private :
        int range;
        int price;

    public:
        TowerArcher();
        ~TowerArcher();
        void setRange(int range);
        int getRange() const;

        void setPrice(int _price);
        int getPrice() const;

        //const bool InRange(const Enemy& enemy) const;

};






#endif