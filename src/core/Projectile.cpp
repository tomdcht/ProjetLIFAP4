#include "Projectile.h"
#include <iostream>
using namespace std;

Projectile::Projectile(){

}

Projectile::Projectile(){

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


    setPosX( getPosX()+ avancementX);
    setPosY( getPosX()+ avancementY);

    avancementX = (enemy.getConstPosX()+ getTime() * enemy.getConstSpeed() * 1 - tower.getConstPosX() ) / (getTime() * getConstSpeed()); // 1 = direction E
    avancementY = (enemy.getConstPosY()+ getTime() * enemy.getConstSpeed() * 0 - tower.getConstPosY() ) / (getTime() * getConstSpeed()); // 0 = direction E


    int xpos = getPosX();
    int ypos = getPosY();

    if ( xpos == enemy.getConstPosX() && ypos == enemy.getConstPosY() ) {
        setPosX(tower.getConstPosX() );
        setPosX(tower.getConstPosY() );
    }
    // if range
}


