#include "Projectile.h"
#include <iostream>
using namespace std;

Projectile::Projectile() : towerArch(){
    setPos(towerArch.getConstPosX(), towerArch.getConstPosY());
    setTime(1);
    setSpeed(2);
}

Projectile::~Projectile(){

}


void Projectile::setTime(int _time) {
    time = _time;
}

const int Projectile::getTime() {
    return time;
}

void Projectile::track(const Enemy& enemy, const TowerArcher& tower) {

    float avancementX, avancementY;

    avancementX = (((enemy.getConstPosX() + (enemy.getConstSpeed() / getTime()) * 1) / (getConstSpeed() / getTime())) - getConstPosX()); // 1 = direction E
    avancementY = (((enemy.getConstPosY() + (enemy.getConstSpeed() / getTime()) * 1) / (getConstSpeed() / getTime())) - getConstPosY()); // 1 = direction E


    setPosX((int)avancementX);
    setPosY((int)avancementY);

    if ( getPosX() == enemy.getConstPosX() && getPosY() == enemy.getConstPosY() ) {
        setPosX(tower.getConstPosX() );
        setPosY(tower.getConstPosY() );
    }
    // if range
}


