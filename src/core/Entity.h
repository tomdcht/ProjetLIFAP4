#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "Vec2.h"

class Entity{
    private:
        int posx, posy;
        int damage;
        int PV;
        bool isDead;

        int speed;

    public:
        Entity();
        ~Entity();

        int getPosX();
        int getPosY();

        const int getConstPosX() const;
        const int getConstPosY() const;

        void setPos(int _posx, int _posy);

        void setPosX(int _posx);
        void setPosY(int _posy);

        void setSpeed(int _speed);
        const int getConstSpeed() const ;

        int getDamage() const;
        void setDamage(int _damage);

        int getPV() const;
        void setPV(int _PV);
};

#endif // _ENTITY_H_