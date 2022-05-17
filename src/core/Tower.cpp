#include "Tower.h"

#include "assert.h"


Tower::Tower(){
    level = 0;
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

void Tower::regressionTest(Tower& tower){
    setRange(1);
    setPrice(20);
    setLevel(2);

    assert(getPrice() == 20);
    assert(getRange() == 1);
    assert(getRange() == 2);

}


// int main(void) {
//     Tower tower;
//     regressionTest(tower);
// }


