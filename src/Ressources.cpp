#include "Ressources.h"
#include "Entity.h"
#include <iostream>

Ressources::Ressources(){
    gold=150;
}

Ressources::~Ressources(){

}

int Ressources::getGold(int gold)const{
    return gold;
}

void Ressources::setGold(int _gold){
    gold=_gold;
}