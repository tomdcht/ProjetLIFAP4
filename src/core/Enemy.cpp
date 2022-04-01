#include "Enemy.h"
#include "Entity.h"
#include <unistd.h>
#include <iostream>
using namespace std;

Enemy::Enemy(){
    isArrived = false;
    isDead = false;
    setPos(0, 10);

}

Enemy::~Enemy(){
    delete [] enemies;
    enemies = nullptr;
}

void Enemy::setIsArrived(bool _isArrived){
    isArrived = _isArrived;
}

bool Enemy::getIsArrived(){
    return isArrived;
}

void Enemy::setIsDead(bool _isDead){
    isDead = _isDead;
}

bool Enemy::getIsDead(){
    return isDead;
}

void Enemy::walk(const Map& map){

    if(map.IsValidPosition(getPosX(), getPosY()) && isArrived == false){
        setPosX(getPosX() + 1);
    }

    if(getPosX() == map.getDimX()){
        isArrived = true;
    }

    if(isArrived == true){

    }
}

void Enemy::appear(){

}


