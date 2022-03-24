#ifndef _MAP_H
#define _MAP_H


class Map {

private :

	int m_dimx;
	int m_dimy;
	char m_map [100][100];

public :

    Map();

    
    bool estPositionPersoValide (const int x, const int y) const;

    

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
