#include "TowerArcher.h"
#include "Entity.h"
#include "Enemy.h"
#include <iostream>


TowerArcher::TowerArcher(){
    setPos(15.f,7.f);
    setSpeed(2);
    range=10;
    price=100;
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