#include "TowerBomb.h"


TowerBomb::TowerBomb(){
    setSpeed(1);
    setRange(250);
    setPrice(200);
    setDamage(20);
    path = "data/Tower/PNG/BombTower/Lvl1/sprites_TowerBomb.png";
    texture = NULL;
    surface = NULL;
}

TowerBomb::~TowerBomb(){
    delete[] this;
    
}
