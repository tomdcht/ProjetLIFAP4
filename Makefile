CC = g++ -Wall
DEBUG = -ggdb

ODIR = obj
LDIR = lib

SDIRCORE = src/core
SDIRTXT = src/txt
SDIRSDL = src/SDL2

HDIR = $(SDIR)/include
BDIR = bin

SDLLIB = /usr/include/SDL2
IMGEXT = $(wildcard *.h)
IMGUILIB = $(LDIR)/imgui/
IMGUILIBI = $(IMGUILIB)$(IMGEXT)


SRCCORE= $(wildcard $(SDIRCORE)/*.cpp)
SRCSDL= $(wildcard $(SDIRSDL)/*.cpp)
SRCTXT= $(wildcard $(SDIRTXT)/*.cpp)

_OBJCORE= $(notdir $(SRCCORE:.cpp=.o))
_OBJSDL= $(notdir $(SRCSDL:.cpp=.o))
_OBJTXT= $(notdir $(SRCTXT:.cpp=.o))

OBJCORE = $(addprefix $(ODIR)/, $(_OBJCORE))
OBJSDL = $(addprefix $(ODIR)/, $(_OBJSDL))
OBJTXT = $(addprefix $(ODIR)/, $(_OBJTXT))

$(BDIR)/AppSDL: $(OBJCORE) $(OBJSDL)
	$(CC) $(DEBUG) $^ -o $@ -L$(SDLLIB) -lSDL2_image -lSDL2 -lSDL2_ttf -lSDL2_mixer

$(BDIR)/AppTxt: $(OBJTXT) $(OBJCORE)
	$(CC) $^ -o $@

$(ODIR)/%.o : $(SDIRCORE)/%.cpp $(SDIRCORE)/%.h
	$(CC) -c $< -o $@

$(ODIR)/%.o : $(SDIRSDL)/%.cpp $(SDIRSDL)/%.h
	$(CC) -c $< -o $@

$(ODIR)/%.o : $(SDIRTXT)/%.cpp $(SDIRTXT)/%.h
	$(CC) -c $< -o $@

obj/mainSDL.o: src/SDL2/mainSDL.cpp src/SDL2/AppSDL.h
	g++ -c src/SDL2/mainSDL.cpp -o obj/mainSDL.o

obj/mainTXT.o: src/txt/mainTXT.cpp src/txt/GameTXT.cpp
	g++ -c src/txt/mainTXT.cpp -o obj/mainTXT.o

docu: doc/lifapower.doxy
	doxygen doc/lifapower.doxy
	firefox doc/html/index.html

clean:
	rm -r $(ODIR)/*
