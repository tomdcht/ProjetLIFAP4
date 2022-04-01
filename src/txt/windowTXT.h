#ifndef _WINDOW_TXT_H_
#define _WINDOW_TXT_H_

class WindowTXT{
    private:

        int dimX, dimY;
        char* winTab;

    public:

        WindowTXT(int _dimX, int _dimY);

        void setDimX(int _dimX);
        int getDimX();

        const void setConstDimX(int _dimX) const ;
        const int getConstDimX() const ;

        void termMove(int x, int y);
        void termClear();
        void termInit();

        void clear(char c=' ');
        void print(int x, int y, char c);
        void print(int x, int y, char* c);
        void draw(int x=0, int y=0);
        void erase(int x=0, int y=0, char c=' ');

        void pause();
        char getCh();


};



#endif
