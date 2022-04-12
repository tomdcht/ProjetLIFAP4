/**

* \file WindowTXT.h
* \brief Définitions de la classe WindowTXT
* \version 1.0
* \date 4 Avril 2022

*/


#ifndef _WINDOW_TXT_H_
#define _WINDOW_TXT_H_

/** \brief Classe gérant l'affichage dans le terminal ainsi qu eles propriétées de la fenêtre */
class WindowTXT{
    private:

        /** \brief Dimensions en x et y de la fenêtre */
        int dimX, dimY;
        /** \brief Tableau de caractères composant la fenêtre */
        char* winTab;

    public:

        /** \brief Constructeur de la classe WindowTXT
         *  \param _dimx Dimension en x de la fenêtre
         *  \param _dimy Dimension en y de la fenêtre
        */
        WindowTXT(int _dimX, int _dimY);

        /** \brief Accesseur modifiant la dimension en x de la fenêtre
         *  \param _dimx Dimension en x de la fenêtre
        */
        void setDimX(int _dimX);
        /** \brief Accesseur renvoyant la valeur de la donnée membre dimX */
        int getDimX();

        /** \brief Accesseur modifiant la dimension en x d'une fenêtre de type const
         *  \param _dimx Dimension en x de la fenêtre
        */
        const void setConstDimX(int _dimX) const ;

        /** \brief Accesseur renvoyant la valeur de la donnée membre dimX d'une fenêtre de type const */
        const int getConstDimX() const ;

        /** \brief Fonction permettant de bouger le curseur du terminal
         *  \param x Position en x du curseur
         *  \param y Position en y du curseur
        */
        void termMove(int x, int y);

        /** \brief Fonction permettant d'effacer tout le terminal */
        void termClear();

        /** \brief Fonction initialisant le mode d'affichage et d'écriture du terminal  */
        void termInit();

        /** \brief Fonction permettant de remplir le terminal d'un même caractère
         *  \param c Caractère qui remplira le terminal
        */
        void clear(char c=' ');

        /** \brief Fonction permettant de remplir le tableau de caractère de la fenêtre
         *  \param x Coordonnée en x du caractère
         *  \param y Coordonnée en y du caractère
         *  \param c Le caractère à positionner en WinTab[y*dimX + x]
        */
        void print(int x, int y, char c);

        /** \brief Fonction permettant de remplir le tableau de caractère de la fenêtre depuis un tableau de caractère
         *  \param x Coordonnée en x du caractère dans le tableau
         *  \param y Coordonnée en y du caractère dans le tableau
         *  \param c Le tableau de caractères
        */
        void print(int x, int y, char* c);

        /** \brief Fonction permettant d'afficher un caractère depuis un tableau de caractère sur le terminal
         *  \param x Coordonnée en x du caractère
         *  \param y Coordonnée en y du caractère
        */
        void draw(int x=0, int y=0);

        /** \brief Fonction permettant de remplir le tableau de caractère de la fenêtre avec un caractère
         *  \param x Coordonnée en x du caractère dans le tableau
         *  \param y Coordonnée en y du caractère dans le tableau
         *  \param c Le caractère
        */
        void erase(int x=0, int y=0, char c=' ');

        /** \brief Fonction permettant de afire pause sur le terminal */
        void pause();

        /** \brief Fonction permettant de recevoir un caractère tapé au clavier */
        char getCh();


};



#endif
