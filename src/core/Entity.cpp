#include "Entity.h"
#include <vector>

Entity::Entity(){
    posx = 0.f;
    posy = 0.f;
    PV = 0;
    damage = 0;
    isDead = false;
}

Entity::~Entity(){

}

float Entity::getPosX(){
    return posx;
}

float Entity::getPosY(){
    return posy;
}

const float Entity::getConstPosX() const {
    return posx;
}

const float Entity::getConstPosY() const {
    return posy;
}

void Entity::setPos(float _posx, float _posy){
    posx = _posx;
    posy = _posy;
}

void Entity::setPosX(float _posx){
    posx = _posx;
}

void Entity::setPosY(float _posy){
    posy = _posy;
}



void Entity::setSpeed(int _speed) {
    speed = _speed;
}

int Entity::getSpeed(){
    return speed;
}

const int Entity::getConstSpeed() const {
    return speed;
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

void Entity::setPV(int _PV) {
    PV = _PV;
}

void Entity::setIsDead(bool _isDead){
    isDead = _isDead;
}

bool Entity::getIsDead(){
    return isDead;
}

