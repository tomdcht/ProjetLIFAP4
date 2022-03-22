#include "Entity.h"
#include <vector>

Entity::Entity(){
    posx, posy = 0;
    PV = 0;
    damage = 0;
}

Entity::~Entity(){

}

std::vector<double> Entity::GetPos() const{

}