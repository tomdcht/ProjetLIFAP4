#include "TowerArcher.h"
#include "Entity.h"
#include <iostream>

TowerArcher::TowerArcher(){
    range=1; 
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