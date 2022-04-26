#include "Enemy.h"
<<<<<<< HEAD

=======
#include "Entity.h"
#include "Game.h"
>>>>>>> 5f0ff1c8abf39171b26d95cd718121d0fab774ee
#include <unistd.h>
#include <iostream>
using namespace std;

Enemy::Enemy() {

    setPos(0.f, 800.f);
    setSpeed(1);
    setPV(15);
    setIsDead(false);
    isArrived = false;
    enemies.push_back(this);
    path = "data/Wariors/Idle/Wariror_Idle_000.png";
}

Enemy::~Enemy(){
}

void Enemy::setIsArrived(bool _isArrived){
    isArrived = _isArrived;
}

bool Enemy::getIsArrived(){
    return isArrived;
}

void Enemy::walk(/*const Map& map*/){

    // if(map.IsValidPosition(this->getPosX(), this->getPosY()) && this->isArrived == false){
        this->setPosX(this->getPosX() + 5);
    //}
}

bool Enemy::isDead() {

    if (getPV() <= 0) {
        setIsDead(true);
    }

    return getIsDead();
}



// int main(void){

//     Enemy enemy;
//     enemy.regressionTest(enemy);
//     return 0;
// }


