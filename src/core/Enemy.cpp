#include "Enemy.h"
#include <math.h>
#include <unistd.h>
#include <iostream>

Enemy::Enemy() {

    setPos(0.f, 855.f);
    setSpeed(1);
    setPV(100);
    setIsDead(false);
    isArrived = false;
    NextPoint = true;
    pointTrack = 0;
    path = "data/Wariors/Walk/spritesheet_WariorWalk.png";
    texture = NULL;
    surface = NULL;
}

Enemy::~Enemy(){
    delete[] this;
}

void Enemy::setIsArrived(bool _isArrived){
    isArrived = _isArrived;
}

bool Enemy::getIsArrived(){
    return isArrived;
}

void Enemy::walk(Road& road){

    if(this->isArrived == false) {

        if (NextPoint == true) {
            _enemyDirectionX = enemyDirectionX(road);
            _enemyDirectionY = enemyDirectionY(road);

            NextPoint = false;

        }

        enemyAvancementX = getPosX() - ((float)getConstSpeed()*_enemyDirectionX);
        enemyAvancementY = getPosY() - ((float)getConstSpeed() * _enemyDirectionY);
        

        setPosX(enemyAvancementX);
        setPosY(enemyAvancementY);

    }

    if ((int)getConstPosX() <= (int)road.getPointX(pointTrack)+3 && (int)getConstPosX() >= (int)road.getPointX(pointTrack)-3) {
        if ((int)getConstPosY() <= (int)road.getPointY(pointTrack)+3 && (int)getConstPosY() >= (int)road.getPointY(pointTrack)-3) {
            pointTrack += 1;
            NextPoint = true;
        }
    }
}

bool Enemy::isDead() {

    if (getPV() <= 0) {
        setIsDead(true);
    }

    return getIsDead();
}

const float Enemy::enemyDistance(Road& road) const {

    float v1,v2;

    v1 = pow(getConstPosX() - road.getPointX(pointTrack),2);
    v2 = pow(getConstPosY() - road.getPointY(pointTrack),2);
    return (sqrt(v1) + sqrt(v2));
}

const float Enemy::enemyDirectionX(Road& road) const{
    return (getConstPosX() - road.getPointX(pointTrack)) / enemyDistance(road)  ; 
}

const float Enemy::enemyDirectionY(Road& road) const{
    return (getConstPosY() - road.getPointY(pointTrack)) / enemyDistance(road)  ; 
}





 