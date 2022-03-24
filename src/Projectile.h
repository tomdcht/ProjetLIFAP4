#ifndef _PROJECTILE_H_
#define _PROJECTILE_H_
#include "Entity.h"
#include <iostream>

class Projectile : public Entity{
        private:

        public:
            Projectile();
            ~Projectile();
            int getProjectile(int damage);
            void setProjectile(int damage);
};



#endif