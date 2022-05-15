#include "Tower.h"


Tower::Tower(){
}

Tower::~Tower(){
    delete[] this;
}

void Tower::setRange(int _range){
    range=_range;
}

int Tower::getRange() const{
    return range;
}

void Tower::setPrice(int _price){
    price=_price;
}

int Tower::getPrice() const{
    return price;
}

void Tower::setLevel(int lvl) {
    level = lvl;
}

int Tower::getLevel() const {
    return level;
}


