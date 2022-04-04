#include "Projectile.h"
#include "TowerArcher.h"
#include <unistd.h>
#include <math.h>
#include <iostream>
using namespace std;

Projectile::Projectile() : towerArch(){

    setPos(towerArch.getConstPosX(), towerArch.getConstPosY());
    setTime(4);
    setSpeed(2);
    towerArch.setRange(10);

    tracking = false;
    _inRange = false;

    float _DirectionX = 0;
    float _DirectionY = 0;

    float avancementX = 0;
    float avancementY = 0;

    int time = 4;
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

const float Projectile::distance(const Enemy& x, const TowerArcher& y ) {

    float v1,v2;

    v1 = pow(x.getConstPosX() - y.getConstPosX(),2);
    v2 = pow(x.getConstPosY() - y.getConstPosY(),2);

    return (sqrt(v1) - sqrt(v2));
}


void Projectile::track(Enemy& enemy, const TowerArcher& tower) {

    if (tracking == false) { // tower.InRange(enemy) == true && tracking == 0

        setPos(towerArch.getConstPosX(), towerArch.getConstPosY());
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

    if ( getPosX() == (enemy.getConstPosX()+1) && getPosY() == enemy.getConstPosY() ) {
        enemy.setPV(enemy.getPV()-5);
        tracking = false;
        _inRange = false;

        std::cout << "Touché" << std::endl;
        std::cout << "PV : "<< enemy.getPV() << "   " << std::endl;
    }

    else {
        std::cout << "         " << std::endl;
        std:: cout<< std :: endl;
        std::cout << "appuyez sur q pour quitter la partie "<<std::endl;
    }

}

void Projectile::inRange(const Enemy& enemy, const TowerArcher& tower){

    if (distance(enemy,tower) <= tower.getRange() && tracking == 0) {
        _inRange = true;
    }

}

const bool Projectile::isInRange() const{
    return _inRange;
}




