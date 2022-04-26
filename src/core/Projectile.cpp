#include "Projectile.h"
#include "TowerArcher.h"
#include <unistd.h>
#include <math.h>
#include <iostream>
using namespace std;

Projectile::Projectile() {

    setTime(4);
    setSpeed(2);
<<<<<<< HEAD
    //towerArch.setRange(10);
    path = "data/Projectile/Arrow.png";
=======
>>>>>>> 5f0ff1c8abf39171b26d95cd718121d0fab774ee

    tracking = false;
    _inRange = false;

    _DirectionX = 0;
    _DirectionY = 0;

    avancementX = 0;
    avancementY = 0;

    time = 4;
}

Projectile::~Projectile(){

}


void Projectile::setTime(int _time) {
    time = _time;
}

const int Projectile::getTime() {
    return time;
}

const float Projectile::directionX(const Enemy& enemy, const TowerArcher& tower) {

    return (enemy.getConstPosX()+ 1.f * ( time * enemy.getConstSpeed() ) - tower.getConstPosX() ) / ( time * getConstSpeed() ) ; // 1.f = direction X de enemy

}

const float Projectile::directionY(const Enemy& enemy, const TowerArcher& tower) {

    return (enemy.getConstPosY()+ 0.f * ( time * enemy.getConstSpeed() ) - tower.getConstPosY() ) / ( time * getConstSpeed() ) ; // 0.f = direction Y de enemy

}

const float Projectile::distance(const float enemy_x, const float enemy_y, const TowerArcher& tower ) {

    float v1,v2;

    v1 = pow(enemy_x - tower.getConstPosX(),2);
    v2 = pow(enemy_y - tower.getConstPosY(),2);

    return (sqrt(v1) + sqrt(v2));
}


void Projectile::track(Enemy& enemy, const TowerArcher& tower) {

    if (tracking == false) {

        setPos(tower.getConstPosX(), tower.getConstPosY());
        _DirectionX = directionX(enemy, tower);
        _DirectionY = directionY(enemy, tower);
        avancementX = getPosX();
        avancementY = getPosY();
        tracking = true;
    }

    avancementX = avancementX + (tower.getConstSpeed()*_DirectionX);
    avancementY = avancementY + (tower.getConstSpeed()*_DirectionY);

    setPosX((int)avancementX);
    setPosY((int)avancementY);

    std::cout << "Position X de l'ennemi tracké = " << enemy.getConstPosX() << std::endl;

    if ( getPosX() == (enemy.getConstPosX()+1) && getPosY() == enemy.getConstPosY() ) {
        enemy.setPV(enemy.getPV()-5);
        tracking = false;
        _inRange = false;
        //std::cout << "Touché       " << std::endl;
    }
    std::cout << "                     " << std::endl;

}

void Projectile::inRange(const Enemy& enemy, const TowerArcher& tower){

    if (distance(enemy.getConstPosX(),enemy.getConstPosY(), tower) < tower.getRange() && tracking == false) {
        _inRange = true;
    }

}

bool Projectile::isInRange() const{
    return _inRange;
}




