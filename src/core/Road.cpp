#include "Road.h"



Road::Road() {


}

Road::~Road() {

}


const std::vector<float> Road::getPoint(int n) const {
        return cheminTXT[n];
}


const float Road::getPointX(int n) const {
        return cheminTXT[n][0];
}


const float Road::getPointY(int n) const {
        return cheminTXT[n][1];
}
