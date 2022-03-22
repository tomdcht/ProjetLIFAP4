#include "Entity.h"
#include <vector>

Entity::Entity(){
    posx, posy = 0;
    PV = 0;
    damage = 0;
}

Entity::~Entity(){

}

Vec2 Entity::GetPos() const{
    return Vec2(posx, posy);
}

void Entity::SetPos(int _posx, int _posy){
    posx = _posx;
    posy = _posy;
}