#include "Castle.h"


Castle::Castle() {
   PVCastle = 20;
}

Castle::~Castle() {

}

const int Castle::getPV() {
    return PVCastle;
}


void Castle::damageCastle(){
    PVCastle = PVCastle - 1;
}




