#include <iostream>
#include "Vec2.h"

Vec2::Vec2(){
    x = 0;
    y = 0;
}

Vec2::Vec2(double _x, double _y) : x(_x), y(_y) {
    x = _x;
    y = _y;
}

Vec2::~Vec2(){

}

Vec2 Vec2::operator= (const Vec2& opdDroite){
    Vec2 vec;
    vec.x = opdDroite.x;
    vec.y = opdDroite.y;
    return vec;
}

Vec2 Vec2::operator+ (const Vec2& opdDroite){
    Vec2 vec;
    vec.x += opdDroite.x;
    vec.y += opdDroite.y;
    return vec;
}

Vec2 Vec2::operator- (const Vec2& opdDroite){
    Vec2 vec;
    vec.x -= opdDroite.x;
    vec.y -= opdDroite.y;
    return vec;
}