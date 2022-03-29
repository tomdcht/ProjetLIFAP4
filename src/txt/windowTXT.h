#ifndef _WINDOW_TXT_H_
#define _WINDOW_TXT_H_

class WindowTXT{
    private:

        int dimX, dimY;
        char* winTab;

    public:

        WindowTXT(int _dimX, int _dimY);

        void termMove(int x, int y);
        void termClear();
        void termInit();

        void clear(char c=' ');
        void print(int x, int y, char c);
        void print(int x, int y, char* c);
        void draw(int x=0, int y=0);
        void pause();
        char getCh();


};



#endif
