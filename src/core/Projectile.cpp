#include "Projectile.h"
#include <iostream>
using namespace std;

Projectile::Projectile() : towerArch(){
    setPos(towerArch.getConstPosX(), towerArch.getConstPosY());
    setTime(2);
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

    avancementX = 0;
    avancementY = 0;

    avancementX = ((enemy.getConstPosX()+ getTime() * enemy.getConstSpeed() * 1 - tower.getConstPosX() ) / (getTime() * getConstSpeed())); // 1 = direction E
    avancementY = ((enemy.getConstPosY()+ getTime() * enemy.getConstSpeed() * 0 - tower.getConstPosY() ) / (getTime() * getConstSpeed())); // 0 = direction E

    setPosX( getPosX()+ (int)avancementX);
    setPosY( getPosX()+ (int)avancementY);


    int xpos = getPosX();
    int ypos = getPosY();

    if ( getPosX() == enemy.getConstPosX() && getPosY() == enemy.getConstPosY() ) {
        setPosX(tower.getConstPosX() );
        setPosX(tower.getConstPosY() );
    }
    // if range
}


