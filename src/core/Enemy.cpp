#include "Enemy.h"
#include "Entity.h"
#include <unistd.h>
#include <iostream>
using namespace std;

Enemy::Enemy(){
    isArrived = false;
    setPos(0, 10);
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


