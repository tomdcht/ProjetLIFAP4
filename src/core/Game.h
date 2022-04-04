/**
 * \file Game.h
 * \author Tom.D
 * \version 1.0
 * \date 15 mars 2022
 */

#ifndef _GAME_H_
#define _GAME_H_

#include "Enemy.h"
#include "Map.h"
#include "TowerArcher.h"
#include "Projectile.h"

class Game{

    private:

        Enemy enemy;
        Map map;
        TowerArcher towerArch;
        TowerArcher towerArch1;
        Projectile arrow;
        Projectile arrow1;

    public:

        Game ();

        Enemy& getEnemy();
        Map& getMap();
        TowerArcher& getTowerArcher();
        TowerArcher& getTowerArcher1();

        const Enemy& getConstEnemy () const;
        const Map& getConstMap () const;
        const TowerArcher& getConstTowerArcher () const;
        const Projectile& getConstProjectile () const;

        void autoEvents();
        void autoEvents1();
        void appear();
};

#endif