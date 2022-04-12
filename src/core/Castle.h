#ifndef _CASTLE_H_
#define _CASTLE_H_
#include "Entity.h"
#include <iostream>

class Castle : public Entity{
    private:


    public:
        Castle();
        ~Castle();

        char getPVUnits() const;
        char getPVTens() const;
};


#endif