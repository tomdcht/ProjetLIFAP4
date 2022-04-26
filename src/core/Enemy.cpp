#include "Enemy.h"
#include "Entity.h"
#include "Game.h"
#include <unistd.h>
#include <iostream>
using namespace std;

Enemy::Enemy() {

    setPos(0.f, 11.f);
    setSpeed(1);
    setPV(15);
    setIsDead(false);
    isArrived = false;
}

Enemy::~Enemy(){
}

void Enemy::setIsArrived(bool _isArrived){
    isArrived = _isArrived;
}

bool Enemy::getIsArrived(){
    return isArrived;
}

void Enemy::walk(const Map& map){

    if(map.IsValidPosition(this->getPosX(), this->getPosY()) && this->isArrived == false){
        this->setPosX(this->getPosX() + 1);
    }
}

bool Enemy::isDead() {

    if (getPV() <= 0) {
        setIsDead(true);
    }

    return getIsDead();
}



