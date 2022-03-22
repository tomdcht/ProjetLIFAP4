#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "Vec2.h"

class Entity{
    private:
        double posx, posy;
        int damage;
        int PV;
        bool isDead;

    public:
        Entity();
        ~Entity();

        Vec2 getPos() const;
        void setPos(int _posx, int _posy);

        int getDamage() const;
        void setDamage(int _damage);

        int getPV() const;
        void setPV(int _PV);



};

#endif // _ENTITY_H_