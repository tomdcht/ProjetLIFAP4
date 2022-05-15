#include "Projectile.h"
#include "Tower.h"
#include "Game.h"
#include <unistd.h>
#include <math.h>
#include <iostream>
using namespace std;

Projectile::Projectile() {

    setTime(4);
    setSpeed(2);

    tracking = false;
    _inRange = false;

    _projectileDirectionX = 0;
    _projectileDirectionY = 0;

    projectileAvancementX = 0;
    projectileAvancementY = 0;

    time = 10;
    timeDelete = 0;

    path = "data/Projectile/Arrow01.png";
    texture = NULL;
    surface = NULL;

    setPosX(200);
    setPosY(200);

}

Projectile::~Projectile(){ 
    delete[] this;
}

void Projectile::setTime(int _time) {
    time = _time;
}

const int Projectile::getTime() {
    return time;
}

void Projectile::fctPath(const char* lien) {
    path = lien;
}

const float Projectile::projectileDirectionX(const Enemy& enemy, const Tower& tower, Road& road) {
    return (enemy.getConstPosX()- 1.5*enemy.enemyDirectionX(road) * ( time * enemy.getConstSpeed() ) - tower.getConstPosX() ) / ( time * getConstSpeed() ) ; // 1.f = direction X de enemy
}       //1,5 a revoir --> 1,5 parce que *1 = avant et *2 = après donc 1,5 ...

const float Projectile::projectileDirectionY(const Enemy& enemy, const Tower& tower, Road& road) {
    return (enemy.getConstPosY()- 1.5*enemy.enemyDirectionY(road) * ( time * enemy.getConstSpeed() ) - tower.getConstPosY() ) / ( time * getConstSpeed() ) ; // 0.f = direction Y de enemy
}

const float Projectile::projectileDistance(const float enemy_x, const float enemy_y, const Tower& tower ) {
    float v1,v2;

    v1 = pow(enemy_x - tower.getConstPosX(),2);
    v2 = pow(enemy_y - tower.getConstPosY(),2);

    return (sqrt(v1) + sqrt(v2));
}


void Projectile::track(Enemy& enemy, const Tower& tower, Road& road) {

    if (tracking == false) {

        setPos(tower.getConstPosX(), tower.getConstPosY());
        _projectileDirectionX = projectileDirectionX(enemy, tower, road);
        _projectileDirectionY = projectileDirectionY(enemy, tower, road);
        projectileAvancementX = getPosX();
        projectileAvancementY = getPosY();
        tracking = true;
    }

    projectileAvancementX = projectileAvancementX + (tower.getConstSpeed()*_projectileDirectionX);
    projectileAvancementY = projectileAvancementY + (tower.getConstSpeed()*_projectileDirectionY);

    setPosX((int)projectileAvancementX);
    setPosY((int)projectileAvancementY);



    if ((int)getPosX() <= (int)enemy.getConstPosX()+10 && (int)getPosX() >= (int)enemy.getConstPosX()-10) {
        if ((int)getPosY() <= (int)enemy.getConstPosY()+10 && (int)getPosY() >= (int)enemy.getConstPosY()-10) {
            std::cout << "Touché" << std::endl;
            enemy.setPV(enemy.getPV()- tower.getDamage());
            tracking = false;
            _inRange = false;
        }
    }


    timeDelete += 1;

    if (timeDelete >= time+10) {
        std::cout << (int)getPosX() <<"==" << (int)enemy.getConstPosX()<< " et " <<(int)getPosY()<< "==" <<(int)enemy.getConstPosY()<< std::endl; 
        tracking = false;
        _inRange = false;
        timeDelete = 0;
    }

}

void Projectile::inRange(const Enemy& enemy, const Tower& tower){

    if (projectileDistance(enemy.getConstPosX(),enemy.getConstPosY(), tower) < tower.getRange() && tracking == false) {
        _inRange = true;
        
    }

}




