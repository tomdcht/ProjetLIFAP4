#include "Map.h"
#include <cassert>

const char m_map[21][46] = {
"#############################################",
"#                               PV = 10     #",
"#                                           #",
"#                                           #",
"#                                           #",
"#                                           #",
"#                                           #",
"#                                           #",
"#############################################",
"                #############################",
"                                             ",
"                                             ",
"####################                         ",
"#############################################",
"#                                           #",
"#                                           #",
"#                                           #",
"#                                           #",
"#                                           #",
"#############################################"
};

Map::Map() {
	dimx = 46;
	dimy = 21;
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
