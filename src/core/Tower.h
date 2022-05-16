#ifndef _TOWER_H_
#define _TOWER_H_
#include "Entity.h"

class Tower : public Entity{
    private :
        /** \brief Portée de la tour d'archer */
        int range;
        /** \brief Prix d'une tour d'archer */
        int price;

    public:

        int level;
        Tower();
        ~Tower();

        /** \brief Accesseur modifiant la valeur de la donnée membre range
         *  \param range Portée de la tour*/
        void setRange(int range);
        /** \brief Accesseur renvoyant la valeur de la donnée membre range */
        int getRange() const;

        /** \brief Accesseur modifiant la valeur de la donnée membre price
         *  \param _price Prix de la tour*/
        void setPrice(int _price);
        /** \brief Accesseur renvoyant la valeur de la donnée membre price */
        int getPrice() const;

        /** \brief Accesseur modifiant la valeur de la donnée membre level
         *  \param lvl Niveau de la tour MAX 3 */
        void setLevel(int lvl);
        /** \brief Accesseur renvoyant la valeur de la donnée membre price */
        int getLevel() const;
};

#endif