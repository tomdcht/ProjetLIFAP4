#ifndef _PROJECTILE.H_
#define _PROJECTILE.H_
#include "Entity.h"
#include <iostream>

class Projectile : public : Entity{
        private:
            
        public: 
            Projectile();
            ~Projectile();
            getProjectile(int damage);
            setProjectile(int damage);


}



#endif