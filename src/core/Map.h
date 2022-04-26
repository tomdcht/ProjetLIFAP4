/**

* \file Map.h
* \brief Définition des donées membres et des fonctions membres de la classe Map
* \version 1.0
* \date 4 Avril 2022

*/


#ifndef _MAP_H
#define _MAP_H

#include "../SDL2/ImageSDL.h"


/** Classe gérant la map */
class Map : public ImageSDL{

private :

    /** \brief Dimension en x de la map */
	int dimx;
    /** \brief Dimension en y de la map */
	int dimy;
    /** \brief Tableau contenant les caractères qui crée la map */
	char map [100][100];

public :

    /** \brief Constructeur par défaut de la classe Map */
    Map();

    const char* path;

    /** \brief Fonction vérifiant si le caractère à la case de coordonnées (x,y) est valide
     *  \param x Coordonnée en x du caractère
     *  \param y Coordonnée en y du caractère
     */
    bool IsValidPosition (const int x, const int y) const;

    /** \brief Fonction renvoyant le caractère aux coordonnées (x,y) de la map
    *   \param x Coordonnée en x du caractère
        \param y Coordonnée en y du caractère
    */
    char getXY (const int x, const int y) const;

    /** \brief Renvoie la largeur du terrain */
    int getDimX () const;

    /** \brief Renvoie la hauteur du terrain */
    int getDimY () const;

};

#endif
