#include "Entity.h"
#include <vector>

Entity::Entity(){
    posx, posy = 0;
    PV = 0;
    damage = 0;
    isDead = false;
}

Entity::~Entity(){

}

Vec2 Entity::getPos() const{
    return Vec2(posx, posy);
}

void Entity::setPos(int _posx, int _posy){
    posx = _posx;
    posy = _posy;
}

int Entity::getDamage() const{
    return damage;
}

void Entity::setDamage(int _damage){
    damage = _damage;
}

int Entity::getPV() const{
    return PV;
}

void Entity::setPV(int _PV){
    PV = _PV;
}