#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "Vec2.h"

class Entity{
    private:
        double posx, posy;
        int damage;
        int PV;

    public:
        Entity();
        ~Entity();

        Vec2 GetPos() const;
        void SetPos(int _posx, int _posy);



};

#endif // _ENTITY_H_