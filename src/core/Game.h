#ifndef _GAME_H_
#define _GAME_H_

#include "Enemy.h"
#include "Map.h"
#include "TowerArcher.h"

class Game{

    private:

        Enemy enemy;
        Map map;
        TowerArcher towerArch;

    public:

        Game ();

        Enemy& getEnemy ();
        Map& getMap ();
        TowerArcher& getTowerArcher ();

        const Enemy& getConstEnemy () const;
        const Map& getConstMap () const;
        const TowerArcher& getConstTowerArcher () const;

        void autoEvents();

};

#endif