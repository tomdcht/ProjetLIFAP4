/**
 * \file castle.h
 * \author Aline.D
 * \version 0.0
 * \date 15 mars 2022
 * \include Entity.h
 */

#ifndef _CASTLE_H_
#define _CASTLE_H_
#include "Entity.h"
#include <iostream>

/** \class Castle
   * \brief classe representant le chateau
   *  La classe gere les fonctions du chateau
*/
class Castle : public Entity{
    private:

    public:
        /** \fn Constructeur par défaut
         *  \brief Constructeur de la classe **/
        Castle();

        /** \fn Destructeur par défaut
         *  \brief Destructeur de la classe **/
        ~Castle();
};


#endif