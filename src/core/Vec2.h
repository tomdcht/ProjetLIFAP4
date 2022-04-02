/**
 * \file Vec2.h
 * \author Tom.D
 * \version 1.0
 * \date 15 mars 2022
 */

#ifndef _VEC2_H_
#define _VEC2_H_

#include <iostream>

class Vec2{
    public:
        double x, y;
        /** \fn Constructeur par défaut **/
        Vec2();

        /** \fn Constructeur
         *  \param _x Coordonnées en x
         *  \param _y Coordonnées en y **/
        Vec2(double _x, double _y);

        /** \fn Destructeur **/
        ~Vec2();

        Vec2 operator= (const Vec2& opdDroite);
        Vec2 operator+ (const Vec2& opdDroite);
        Vec2 operator- (const Vec2& opdDroite);
};

#endif // _VEC2_H_