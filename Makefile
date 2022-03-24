CC = g++
DEBUG = -ggdb

ODIR = obj
LDIR = lib
SDIR = src
HDIR = $(SDIR)/include
BDIR = bin

SDLLIB = /usr/include/SDL2
IMGEXT = $(wildcard *.h)
IMGUILIB = $(LDIR)/imgui/
IMGUILIBI = $(IMGUILIB)$(IMGEXT)


SRC= $(wildcard $(SDIR)/*.cpp)
_OBJ= $(notdir $(SRC:.cpp=.o))
OBJ = $(addprefix $(ODIR)/, $(_OBJ))

$(BDIR)/App: $(OBJ)
	$(CC) $^ -o $@ -L$(SDLLIB) -lSDL2_image -lSDL2 -lSDL2_ttf

$(ODIR)/%.o : $(SDIR)/%.cpp $(SDIR)/%.h
	$(CC) -c $< -o $@

obj/App.o: src/App.cpp src/AppSDL.h
	g++ -c src/App.cpp -o obj/App.o

clean:
	rm -r $(ODIR)/*
