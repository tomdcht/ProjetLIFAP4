#include "Map.h"
#include <cassert>

const char map[21][46] = {
"#############################################",
"#                                           #",
"#                                           #",
"#                                           #",
"#                                           #",
"#                                           #",
"#                                           #",
"#                                           #",
"#############################################",
"#####################                        ",
"                                             ",
"                                             ",
"                #############################",
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
			map[x][y] = map[dimy-1-y][x];
}

bool Map::IsValidPosition (const int x, const int y) const {
	return ((x>=0) && (x<dimx) && (y>=0) && (y<dimy) && (map[x][y]!='#'));
}

char Map::getXY (const int x, const int y) const {
	assert(x>=0);
	assert(y>=0);
	assert(x<dimx);
	assert(y<dimy);
	return map[x][y];
}

int Map::getDimX () const { return dimx; }

int Map::getDimY () const {	return dimy; }