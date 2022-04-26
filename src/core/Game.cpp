#include <iostream>

#include "Game.h"
#include <list>
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

const Ressources& Game::getConstRessources() const { return ressources;}

void Game::earnGold(){
    ressources.setGold(ressources.getGold() + 10);

}

Enemy* Game::getIt(list<Enemy*> _list, int _i){
    list<Enemy*>::iterator it = _list.begin();
    for(int i=0; i<_i; i++){
        ++it;
    }
    return *it;
}

void Game::autoEvents() {

    const int size = enemy.enemies.size();
    // int tracker = 0;

    // for (n_track = minimum ; n_track < size ; n_track++) {

    //     arrow.inRange(*getIt(enemy.enemies, n_track),towerArch);

    //     if(arrow.isInRange() == true && getIt(enemy.enemies, n_track)-> isDead() == false ) {
    //         arrow.track(*getIt(enemy.enemies, n_track),towerArch);
    //         minimum = n_track;
    //         tracker = n_track;
    //         break;
    //     }
    // }
    //std::cout << "Game.cpp = "<< enemy.getSizeList()<< std::endl;

    for (int n = 0; n < size ; n++) {
        getIt(enemy.enemies, n)->walk();
    }

    //enemy.walk();

    // if(getIt(enemy.enemies, tracker)->getPosX() == map.getDimX()-1 || getIt(enemy.enemies, n)-> getIsDead() == true){
    //         enemy.enemies.remove(getIt(enemy.enemies, n));
    //         minimum = minimum-1;
    //         //enemy.enemies.pop_front();
    // }

    // time++;
    // if(time == 8) {
    //     enemy.enemies.push_back(new Enemy);
    //     time = 0;
    // }




    //for(std::list<Enemy*>::iterator it = enemy.enemies.begin(); it != enemy.enemies.end(); ++it){
    //    cout << "Enemy : " << *it << std::endl;
    //    std::cout << "PosX : " << (int)enemy.enemies.front()->getConstPosX() << ",PosY : " << (int)enemy.enemies.front()->getConstPosY() << std::endl;
    //    std::cout << "IsDead ? " << enemy.enemies.front()->isDead() << std::endl;
    //}


}