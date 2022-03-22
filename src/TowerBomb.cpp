#include "TowerBomb.h"
#include "Entity.h"
#include <iostream>

TowerBomb::TowerBomb(){
    range=1; 
    price=200;
}

TowerBomb::~TowerBomb(){
        
}

void TowerBomb::setRange(int _range){
    range=_range;
}

int TowerBomb::getRange() const{
    return range;
}

void TowerBomb::setPrice(int _price){
    price=_price;
}

int TowerBomb::getPrice() const{
    return price;
}