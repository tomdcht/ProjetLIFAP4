/**

* \file Entity.h
* \brief Définition des donées membres et des fonctions membres de la classe Entity
* \version 1.0
* \date 4 Avril 2022
*/

#include "Vec2.h"

#ifndef _ENTITY_H_
#define _ENTITY_H_

/** \brief Classe gérant toutes les entités présentes dans le jeu (Ennemis, Tours, Projectiles, etc.) */
class Entity{
    private:

        /** \brief Coordonnée de l'ennemi en x */
        float posx;
        /** \brief Coordonnée de l'ennemi en x */
        float posy;
        /** \brief Dégats causés par l'ennemi */
        int damage;
        /** \brief Points de vie de l'ennemi */
        int PV;
        /** \brief Booléen permettant de savoir si un ennemi est mort */
        bool isDead;
        /** \brief Vitesse de l'ennemi */
        int speed;

    public:
        /** \brief Constructeur par défaut de la classe Entity */
        Entity();
        /** \brief Destructeur par défaut de la classe Entity */
        ~Entity();

        /** \brief Accesseur renvoyant la position en x d'une entité */
        float getPosX();
        /** \brief Accesseur renvoyant la position en y d'une entité */
        float getPosY();

        /** \brief Accesseur renvoyant la position en x d'un ennemi de type const */
        const float getConstPosX() const;
        /** \brief Accesseur renvoyant la position en y d'un ennemi de type const */
        const float getConstPosY() const;

        /** \brief Accesseur modifiant la position en x et en y d'un ennemi
         *  \param _posx La position en x d'un ennemi
         *  \param _posy La position en y d'un ennemi
        */
        void setPos(float _posx, float _posy);

        /** \brief Accesseur modifiant la position en x d'un ennemi
         *  \param _posx La position en x d'un ennemi
        */
        void setPosX(float _posx);
        /** \brief Accesseur modifiant la position en y d'un ennemi
         *  \param _posy La position en y d'un ennemi
        */
        void setPosY(float _posy);

        /** \brief Accesseur modifiant la vitesse d'un ennemi
         *  \param _speed La vitesse d'un ennemi
        */
        void setSpeed(int _speed);

        /** \brief Accesseur renvoyant la vitesse d'un ennemi*/
        int getSpeed();

        /** \brief Accesseur renvoyant la vitesse d'un ennemi de type const*/
        const int getConstSpeed() const ;

        /** \brief Accesseur renvoyant les dommages causés par un ennemi */
        int getDamage() const;

        /** \brief Accesseur modifiant les dommages causés par un ennemi
         *  \param _damage Les dégats d'un ennemi
         */
        void setDamage(int _damage);

        /** \brief Accesseur renvoyant les points de vie d'un ennemi */
        int getPV() const;
        char getPV() ;

        /** \brief Accesseur modifiant les points de vie d'un ennemi */
        void setPV(int _PV);

        /** \brief Accesseur modifiant la données membre 'isDead' d'un ennemi
         *  \param _isDead La donnée membre 'isDead'
         */
        void setIsDead(bool _isDead);

        /** \brief Accesseur renvoyant la valeur de la donnée membre 'isDead' d'un ennemi */
        bool getIsDead();

};

#endif // _ENTITY_H_