#ifndef _TOWER.H_
#define _TOWER.H_
#include <iostream>
#include "Entity.h"

class Tower : public Entity{
    private :
        int range; 
        int price;
    
    public: 
        Tower();
        ~Tower();
        void setRange(int range);
        int getRange(int range) const;
        
};






#endif