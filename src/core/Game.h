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
        Projectile arrow;

    public:

        Game ();

        Enemy& getEnemy();
        Map& getMap();
        TowerArcher& getTowerArcher();

        const Enemy& getConstEnemy () const;
        const Map& getConstMap () const;
        const TowerArcher& getConstTowerArcher () const;
        const Projectile& getConstProjectile () const;

        void autoEvents();
};

#endif