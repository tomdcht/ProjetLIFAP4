/**
* \file Vec2.h
* \brief
* \version 1.0
* \date Février 2022
* \include iostream
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

        /** \fn Surcharge d'opérateur = **/
        Vec2 operator= (const Vec2& opdDroite);

        /** \fn Surcharge d'opérateur  + **/
        Vec2 operator+ (const Vec2& opdDroite);

        /** \fn Surcharge d'opérateur - **/
        Vec2 operator- (const Vec2& opdDroite);
};

#endif // _VEC2_H_