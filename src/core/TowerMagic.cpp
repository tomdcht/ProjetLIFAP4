#include "TowerMagic.h"


TowerMagic::TowerMagic(){
    setSpeed(1);
    setRange(400);
    setPrice(200);
    setDamage(3);
    path = "data/Tower/PNG/MagicTower/Lvl1/01.png";
    texture = NULL;
    surface = NULL;
}

TowerMagic::~TowerMagic(){
    delete[] this;
    
}

