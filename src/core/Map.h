/**
 * \file Map.h
 * \author Tom.D, Aline.S
 * \version 1.0
 * \date 15 mars 2022
 */

#ifndef _MAP_H
#define _MAP_H


class Map {

private :

	int dimx;
	int dimy;
	char map [100][100];

public :

    Map();


    bool IsValidPosition (const int x, const int y) const;

    /**
    @brief Renvoie le type d'objet se trouvant en (x,y)
    @param x : abs de la case de l'objet
    @param y : ordonnée de la case de l'objet
    */
    char getXY (const int x, const int y) const;

    /**
    @brief Renvoie la largeur du terrain
    */
    int getDimX () const;

    /**
    @brief Renvoie la hauteur du terrain
    */
    int getDimY () const;

};

#endif
