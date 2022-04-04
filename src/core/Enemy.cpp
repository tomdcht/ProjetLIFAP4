#include "Enemy.h"
#include "Entity.h"
#include <unistd.h>
#include <iostream>
using namespace std;

Enemy::Enemy(){

    setPos(0.f, 11.f);
    setSpeed(1);
    setPV(10);
    setIsDead(false);
    isArrived = false;
    enemies.push_back(this);

    /*SOIT*/

    // enemies.push_back(*this);
    // enemies.back().setPos(0.f, 11.f);
    // enemies.back().setSpeed(1);
    // enemies.back().setPV(10);
    // enemies.back().setIsDead(false);
    // enemies.back().isArrived = false;

}

Enemy::~Enemy(){
    delete [] &enemies;
    enemies.clear();
}

void Enemy::setIsArrived(bool _isArrived){
    isArrived = _isArrived;
}

bool Enemy::getIsArrived(){
    return isArrived;
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
        setIsDead(true);
    }

<<<<<<< HEAD
    return true;
=======
    return getIsDead();
>>>>>>> bb8ccf78abf66c738ce7d51e413429a033d6d82b
}

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

    cout << enemy.enemies.back()->getPosX() << " " << enemy.getPosY() << endl;
    cout << "Speed : " << enemy.getSpeed() << "PV : " << enemy.getPV() << endl;
    cout << "IsDead ? " << enemy.enemies.back()->getIsDead() << endl;
    cout << "IsArrived ? " << enemy.enemies.back()->getIsArrived() << endl;
}

// int main(void){

//     Enemy enemy;
//     enemy.regressionTest(enemy);
//     return 0;
// }


