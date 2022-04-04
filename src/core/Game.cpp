#include <iostream>

#include "Game.h"
#include <list>
#include <iostream>
using namespace std;

Game::Game(){

}

Enemy& Game::getEnemy(){ return *enemy.enemies.front(); }

Map& Game::getMap(){ return map;}

TowerArcher& Game::getTowerArcher(){ return towerArch;}

const Enemy& Game::getConstEnemy() const { return enemy;}

const Map& Game::getConstMap() const { return map;}

const TowerArcher& Game::getConstTowerArcher() const { return towerArch;}

const Projectile& Game::getConstProjectile() const { return arrow;}

void Game::autoEvents() {

    enemy.enemies.front()->walk(map);

    if(enemy.enemies.front()->getPosX() == map.getDimX() || enemy.enemies.front()->getIsDead() == true){
        // std::cout << std::endl;
        // std::cout << std::endl;
        // std::cout << std::endl;
        // std::cout << std::endl;
        //enemies.emplace(enemies.begin(), --it);

        enemy.enemies.pop_front();
        enemy.enemies.push_front(new Enemy);

    }

    arrow.inRange(*enemy.enemies.front(),towerArch);

    if(arrow.isInRange() == true && enemy.enemies.front()->isDead() == false ) {
        arrow.track(*enemy.enemies.front(),towerArch);
    }

    for(std::list<Enemy*>::iterator it = enemy.enemies.begin(); it != enemy.enemies.end(); ++it){
        cout << "Enemy : " << *it << std::endl;
        std::cout << "PosX : " << (int)enemy.enemies.front()->getConstPosX() << ",PosY : " << (int)enemy.enemies.front()->getConstPosY() << std::endl;
        std::cout << "IsDead ? " << enemy.enemies.front()->isDead() << std::endl;
    }


    // std::cout << "PosX : " << (int)enemy.enemies.front()->getConstPosX() << ",PosY : " << (int)enemy.enemies.front()->getConstPosY() << std::endl;
    // std::cout << "IsDead ? " << enemy.enemies.front()->isDead() << std::endl;
    // cout << enemy.enemies.front()->getPV() << std::endl;
}