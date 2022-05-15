#ifndef _ROAD_H_
#define _ROAD_H_
#include <iostream>

#include <vector>

class Road {
    private :
        

    public:
        Road();
        ~Road();

        std::vector<float> cheminTXT[7] = {{588.f,830.f},{690.f,525.f}, {900.f,520.f}, {994.f,696.f}, {1123.f,848.f}, {1840.f,848.f}};
        int taille_cheminTXT = 5;

        // donne le point en position n en Vec
        const std::vector<float> getPoint(int n) const;

        const float getPointX(int n) const;

        const float getPointY(int n) const ;

};

#endif