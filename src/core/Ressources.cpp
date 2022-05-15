#include "Ressources.h"
#include <iostream>

Ressources::Ressources(){
    gold = 900;
}

Ressources::~Ressources(){

}

int Ressources::getGold() const{
    return gold;
}

void Ressources::setGold(int _gold){
    gold=_gold;
}