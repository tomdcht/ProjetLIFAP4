#include "Enemy.h"
#include "Entity.h"
#include <iostream>
using namespace std;

Enemy::Enemy(){
    setPos(1, 16);
}

void Enemy::walk(const Map& map){
    if(map.IsValidPosition(getPosX(), getPosY())){
        setPosX(getPosX() + 1);
    }
}
