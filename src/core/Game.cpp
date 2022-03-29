#include <iostream>

#include "Game.h"

Game::Game(){

}

Enemy& Game::getEnemy(){ return enemy;}

Map& Game::getMap(){ return map;}

TowerArcher& Game::getTowerArcher(){ return towerArch;}

const Enemy& Game::getConstEnemy() const { return enemy;}

const Map& Game::getConstMap() const { return map;}

const TowerArcher& Game::getConstTowerArcher() const { return towerArch;}

const Projectile& Game::getConstProjectile() const { return arrow;}

void Game::autoEvents(){
    enemy.walk(map);
}