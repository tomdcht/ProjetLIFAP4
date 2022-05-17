#ifndef _RESSOURCES_H_
#define _RESSOURCES_H_
#include <iostream>


class Ressources{
    private:
        int gold;

    public:
        /** \brief Constructeur de la classe Ressource */
        Ressources();

        /** \brief Destructeur de la classe Ressource*/
        ~Ressources();

        /** \brief Accesseur de la donnée membre gold */
        int getGold() const;

        /** \brief Mutateur de la donnée membre gold*/
        void setGold(int _gold);
};

#endif