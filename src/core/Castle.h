/**

* \file Castle.h
* \brief Définition des donées membres et des fonctions membres de la classe Castle
* \version 1.0
*/

#ifndef _CASTLE_H_
#define _CASTLE_H_

class Castle {
    private:

        /** \brief Les points de vie du château */
        int PVCastle;

    public:
        /** \brief Constructeur de la classe Castle */
        Castle();

        /** \brief Destructeur de la classe Castle */
        ~Castle();

        /** \brief Accesseur de la donnée membre PVCastle */
        const int getPV();

        /** \brief Accesseur qui modifie la donnée membre PVCastle 
         *  \param _PV nombre de PV du chateau **/ 
        void setPV(const int _PV);

        /** \brief Enleve 1 point de vie au château */ 
        void damageCastle();
};


#endif