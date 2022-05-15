#include "TowerArcher.h"


TowerArcher::TowerArcher(){
    setSpeed(1);
    setRange(500);
    setPrice(100);
    setDamage(5);
    path = "data/Tower/PNG/ArcherTower/Lvl1/sprites_towerArch.png";
    texture = NULL;
    surface = NULL;
}

TowerArcher::~TowerArcher(){
    delete[] this;
    
}

