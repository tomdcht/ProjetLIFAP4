#include "Enemy.h"
#include "Entity.h"
#include <unistd.h>
#include <iostream>
using namespace std;

Enemy::Enemy(){
    isArrived = false;
    setPos(0.f, 11.f);
    setSpeed(1);
    setPV(10);
    _isDead = false;
}

Enemy::~Enemy(){
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

bool Enemy::isDead() {

    if (getPV() <= 0) {
        _isDead = true;
    }

    return _isDead;
}


