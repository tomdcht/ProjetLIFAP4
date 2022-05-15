#include "Map.h"
#include <cassert>

const char m_map[53][115] = {
"                                        -----------------------------                                         ",
"                                        |     LIFAPOWER DEFENSE     |                                         ",
"                                        |        version 0.2        |                                         ",
"                                        -----------------------------                                         ", 
"                                                                                                              ",
"        ---------------                           Vague 1/5                        ------------------         ",
"        | GOLD =      |                       Nombre ennemies 10                   | CASTLE PV =    |         ", 
"        ---------------                                                            ------------------         ",
"   ###########################################################################################################",
"   #                                                                                                         #",
"   #    ####################################################################                                 #",
"   #    #                                                                  #                                 #",
"   #    #                                                                  #                                 #",
"   #    #                                                                  #                                 #",
"   #    #   ############################################################   #                                 #",
"   #    #   #                                   ---                    #   #    ---                          #",
"   #    #   #                                   | |                    #   #    | |                          #",
"   ######   #                                   ---                    #   #    ---                          #",
"            #    ---                                                   #   #                                 #",
"            #    | |                                              ---  #   #                                 #",
"            #    ---                                              | |  #   #                                 #", 
"   ##########                                                     ---  #   #                                 #",
"   #                                                                   #   #                                 #",
"   #                                                                   #   #                                 #",
"   #                                                                   #   #                                 #",
"   #                                                                   #   #                                 #",
"   #                                                                   #   #                   ---           #",
"   #                                                                   #   #                   | |           #",
"   #                                                                   #   #                   ---           #",
"   #                                                                   #   ###################################",
"   #                                                                   #                                      ",
"   #                                                                   #                                      ",
"   #                                                                   #                                      ",
"   #                                                                   #######################################",
"   #                                                                                                         #",
"   ###########################################################################################################",
"          ------------------------------                       --------------------------------------         ",
"          |    Nombre de tours :  /5   |                       |     Coût des tours : 100 gold      |         ",
"          | Dégats des flèches :    pv |                       | Amélioration des flèches : 70 gold |         ",
"          ------------------------------                       --------------------------------------         ",
"                                                                                                              ",
"                                Appuyer sur 'v' pour acheter une tour archer                                  ",
"                                Appuyer sur 'b' pour acheter une tour mortier                                 ",
"                                Appuyer sur 'm' pour acheter une tour magique                                 ",
"                                                                                                              ",
"                                 Appuyer sur 'p' pour mettre en Pause le jeu                                  ",
"                                     Appuyer sur 'q' pour Quitter le jeu                                      ",
"                                                                                                              ",
"                                                                                                              "
};

Map::Map() {
	dimx = 112;
	dimy = 48;
	for(int x=0;x<dimx;++x)
		for(int y=0;y<dimy;++y)
			map[y][x] = m_map[y][x];
}

bool Map::IsValidPosition (const int x, const int y) const {
	return ((x>=0) && (x<dimx) && (y>=0) && (y<dimy) && (map[y][x]!='#'));
}

char Map::getXY (const int x, const int y) const {
	assert(x>=0);
	assert(y>=0);
	assert(x<dimx);
	assert(y<dimy);
	return map[y][x];
}

int Map::getDimX () const { return dimx; }

int Map::getDimY () const {	return dimy; }
