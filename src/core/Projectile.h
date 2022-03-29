#ifndef _PROJECTILE_H_
#define _PROJECTILE_H_
#include "Entity.h"
#include "Enemy.h"
#include "TowerArcher.h"
#include <iostream>

class Projectile : public Entity{
        private:

        TowerArcher towerArch;
        int time;

        public:
            Projectile();
            Projectile(const TowerArcher& towerArch);
            ~Projectile();

            int getProjectile(int damage);
            void setProjectile(int damage);

            void setTime(int _time);
            const int getTime();

            void track(const Enemy& enemy, const TowerArcher& towerArch);

};



#endif