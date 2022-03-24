#include "Map.h"
#include <cassert>

const char m_map[21][46] = {
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
"#############################################",
};

Map::Map() {
	m_dimx = 46;
	m_dimy = 21;
	for(int x=0;x<m_dimx;++x)
		for(int y=0;y<m_dimy;++y)
			m_map[x][y] = m_map[m_dimy-1-y][x];
}

bool Map::estPositionPersoValide (const int x, const int y) const {
	return ((x>=0) && (x<m_dimx) && (y>=0) && (y<m_dimy) && (m_map[x][y]!='#'));
}

char Map::getXY (const int x, const int y) const {
	assert(x>=0);
	assert(y>=0);
	assert(x<m_dimx);
	assert(y<m_dimy);
	return m_map[x][y];
}

int Map::getDimX () const { return m_dimx; }

int Map::getDimY () const {	return m_dimy; }
