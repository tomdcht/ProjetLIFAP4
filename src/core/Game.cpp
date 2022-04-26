#include <iostream>

#include "Game.h"
#include <list>
using namespace std;

Game::Game(){
    enemies.push_front(new Enemy);
    towerArch.setPos(9.f,7.f);

    arrow.setPos(towerArch.getPosX(), towerArch.getPosY());
}

Enemy& Game::getEnemy(){ return *enemies.front(); }

Map& Game::getMap(){ return map;}

TowerArcher& Game::getTowerArcher(){ return towerArch;}

const Enemy& Game::getConstEnemy() const { return enemy;}

const Map& Game::getConstMap() const { return map;}

const TowerArcher& Game::getConstTowerArcher() const { return towerArch;}

const Projectile& Game::getConstProjectile() const { return arrow;}

const Ressources& Game::getConstRessources() const { return gold;}

const Castle& Game::getConstCastle() const { return castle;}

void Game::earnGold(){
    gold.setGold(gold.getGold() + 10);

}

Enemy* Game::getItEnemy(list<Enemy*> _list, int _i){
    list<Enemy*>::iterator it = _list.begin();
    for(int i=0; i<_i; i++){
        ++it;
    }
    return *it;
}

Projectile* Game::getItProjectile(list<Projectile*> _list, int _i){
    list<Projectile*>::iterator it = _list.begin();
    for(int i=0; i<_i; i++){
        ++it;
    }
    return *it;
}

TowerArcher* Game::getItTower(list<TowerArcher*> _list, int _i){
    list<TowerArcher*>::iterator it = _list.begin();
    for(int i=0; i<_i; i++){
        ++it;
    }
    return *it;
}

const int Game::getSizeListEnemy() {
    return enemies.size();
}

const int Game::getSizeListTower() {
    return towers.size();
}

const int Game::getSizeListProjectile() {
    return projectiles.size();
}










void Game::autoEvents() {

    const int size = enemies.size();
    int tracker = 0;


    for (n_track = minimum ; n_track < size ; n_track++) {

        arrow.inRange(*getItEnemy(enemies, n_track),towerArch);

        if(arrow.isInRange() == true && getItEnemy(enemies, n_track)-> isDead() == false ) {
            arrow.track(*getItEnemy(enemies, n_track),towerArch);
            minimum = n_track;
            tracker = n_track;
            break;
        }

    }

    

    /// Marche des ennemies
    for (int n = 0; n < size ; n++) {
        getItEnemy(enemies, n)->walk(map);
    }


    if(getItEnemy(enemies, tracker)->getPosX() == map.getDimX()-1 || getItEnemy(enemies, n)-> getIsDead() == true){
            enemies.remove(getItEnemy(enemies, n));
            minimum = minimum-1;

            earnGold();

            std::cout << "mort" << endl;
    }
    else {
        std::cout << "     " << endl;
    }


    time++;
    if(time == 8) {
        enemies.push_back(new Enemy);
        time = 0;
    }

}