#ifndef _RESSOURCES_H_
#define _RESSOURCES_H_
#include "Entity.h"
#include <iostream>


class Ressources{
    private:
        int gold;

    public:
        Ressources();
        ~Ressources();
        int getGold() const;
        void setGold(int _gold);
};

#endif