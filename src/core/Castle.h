#ifndef _CASTLE_H_
#define _CASTLE_H_

class Castle {
    private:
        int PVCastle;

    public:
        Castle();
        ~Castle();

        const int getPV();
        void damageCastle();
};


#endif