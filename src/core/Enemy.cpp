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
<<<<<<< HEAD
    enemies.push_back(this);
    path = "data/Wariors/Idle/Wariror_Idle_000.png";
=======
>>>>>>> 5f0ff1c8abf39171b26d95cd718121d0fab774ee
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

<<<<<<< HEAD

void Enemy::regressionTest(Enemy& enemy){
    enemy.setPos(0.f, 11.f);
    enemy.setSpeed(1);
    enemy.setPV(10);
    enemy.setIsDead(false);
    enemy.setIsArrived(false);
    enemy.enemies.push_back(this);

    cout << enemy.getPosX() << " " << enemy.getPosY() << endl;
    cout << "Speed : " << enemy.getSpeed() << "PV : " << enemy.getPV() << endl;
    cout << "IsDead ? " << enemy.getIsDead() << endl;
    cout << "IsArrived ? "  << enemy.getIsArrived() << endl;

    enemy.setPos(4.f, 12.f);

    cout << enemy.enemies.front()->getPosX() << " " << enemy.enemies.front()->getPosY() << endl;
    cout << "Speed : " << enemy.enemies.front()->getSpeed() << ", PV : " << enemy.enemies.front()->getPV() << endl;
    cout << "IsDead ? " << enemy.enemies.back()->getIsDead() << endl;
    cout << "IsArrived ? " << enemy.enemies.back()->getIsArrived() << endl;

}

// int main(void){

//     Enemy enemy;
//     enemy.regressionTest(enemy);
//     return 0;
// }
=======
>>>>>>> 5f0ff1c8abf39171b26d95cd718121d0fab774ee


