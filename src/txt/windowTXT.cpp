#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <assert.h>

#include "windowTXT.h"

void WindowTXT::termMove(int x, int y){
    char t[16];
    sprintf(t, "\033[%d;%dH",y ,x);
    printf("%s", t);
}

void WindowTXT::termClear(){
    system("clear");
}

void WindowTXT::termInit(){
    struct termios ttystate;
    bool state = true;

    tcgetattr(STDIN_FILENO, &ttystate);

    if(state){

        ttystate.c_lflag &= ~ICANON;

        ttystate.c_cc[VMIN] = 1;
    }
    else{

        ttystate.c_lflag |= ICANON;
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);

    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag |= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

WindowTXT::WindowTXT(int _dimx, int _dimy){
    dimX = _dimx;
    dimY = _dimy;
    winTab = new char[dimX*dimY];
    clear();
    termInit();
}

void WindowTXT::setDimX(int _dimX){
    dimX = _dimX;
}

int WindowTXT::getDimX(){
    return dimX;
}

const int WindowTXT::getConstDimX() const {
    return dimX;
}

void WindowTXT::clear(char c){
    for(int i = 0; i < dimX; i++){
        for(int j = 0; j < dimY; j++){
            print(i, j, c);
        }
    }
}

void WindowTXT::print(int x, int y, char c){
    if(x < 0) return;
    if(y < 0) return;
    if(x>=dimX) return;
    if(y>=dimY) return;
    winTab[y*dimX + x] = c;
}

void WindowTXT::print(int x, int y, char* c){
    int i = 0;
    while(c[i] != '\0'){
        print(x+i, y, c[i]);
        i++;
    }
}

void WindowTXT::draw(int x, int y){
    termMove(0,0);
    for(int j=0; j<dimY; ++j){
        for(int i=0; i<dimX; ++i){
            printf("%c", winTab[j*dimX + i]);
        }
        printf("\n");
    }
    termMove(0, dimY);
}

void WindowTXT::erase(int x, int y, char c){
    if(x < 0) return;
    if(y < 0) return;
    if(x>=dimX) return;
    if(y>=dimY) return;
    winTab[y*dimX + x] = c;
}

int khbit(){
    struct timeval tv;
    fd_set fds;
    tv.tv_sec = 0;
    tv.tv_usec = 0;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);
    return FD_ISSET(STDIN_FILENO, &fds);
}

void WindowTXT::pause() {
    printf("Appuyer sur une touche\n");
    while(!khbit());
}

char WindowTXT::getCh(){
    char key = 0;
    if(khbit()){
        key = fgetc(stdin);
    }
    return key;
}
