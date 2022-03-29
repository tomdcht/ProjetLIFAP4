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

int Entity::getPosX(){
    return posx;
}

int Entity::getPosY(){
    return posy;
}

const int Entity::getConstPosX() const {
    return posx;
}

const int Entity::getConstPosY() const {
    return posy;
}

void Entity::setPos(int _posx, int _posy){
    posx = _posx;
    posy = _posy;
}

void Entity::setPosX(int _posx){
    posx = _posx;
}

void Entity::setPosY(int _posy){
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