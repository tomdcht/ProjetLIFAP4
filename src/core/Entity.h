#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "Vec2.h"

class Entity{
    private:
        float posx, posy;
        int damage;
        int PV;
        bool isDead;

        int speed;

    public:
        Entity();
        ~Entity();

        float getPosX();
        float getPosY();

        const float getConstPosX() const;
        const float getConstPosY() const;

        void setPos(float _posx, float _posy);

        void setPosX(float _posx);
        void setPosY(float _posy);

        void setSpeed(int _speed);
        const int getConstSpeed() const ;

        int getDamage() const;
        void setDamage(int _damage);

        int getPV() const;
        void setPV(int _PV);

        void setIsDead(bool _isDead);
        bool getIsDead();

};

#endif // _ENTITY_H_