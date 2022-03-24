#include "TowerMagic.h"
#include "Entity.h"
#include <iostream>

TowerMagic::TowerMagic(){
    range=1; 
    price=250;
}

TowerMagic::~TowerMagic(){
        
}

void TowerMagic::setRange(int _range){
    range=_range;
}

int TowerMagic::getRange() const{
    return range;
}

void TowerMagic::setPrice(int _price){
    price=_price;
}

int TowerMagic::getPrice() const{
    return price;
}