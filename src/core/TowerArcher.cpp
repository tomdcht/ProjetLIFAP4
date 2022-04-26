#include "TowerArcher.h"
#include "Entity.h"
#include "Enemy.h"
#include <iostream>


TowerArcher::TowerArcher(){
    setPos(670.f,480.f);
    setSpeed(2);
    range=10;
    price=100;
    path = "data/Tower/PNG/ArcherTower/Lvl1/01.png";
}

TowerArcher::~TowerArcher(){

}

void TowerArcher::setRange(int _range){
    range=_range;
}

int TowerArcher::getRange() const{
    return range;
}

void TowerArcher::setPrice(int _price){
    price=_price;
}

int TowerArcher::getPrice() const{
    return price;
}


//const bool TowerArcher::InRange(const Enemy& enemy) const { return true; }