/**
 * \file Entity.h
 * \author Tom.D, Allan.D, Aline.S
 * \version 1.0
 * \date 15 mars 2022
 */

#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "Vec2.h"

/** \class Entity
   * \brief class representant l'ensemble des entités
   *  La classe gere les toutes les fonctions commmunes des entités
*/
class Entity{
    private:
        float posx, posy;
        int damage;
        int PV;
        bool isDead;

        int speed;

    public:


        /** \fn Constructeur par défaut
         *  \brief Constructeur de la classe **/
        Entity();
        /** \fn Destructeur par défaut
         *  \brief Destructeur de la classe **/
        ~Entity();





        /** \fn getPosX()
         * \brief Fonction retournant la position en x de l'entité
         *  \return posx **/
        float getPosX();

        /** \fn getPosY()
         * \brief Fonction retournant la position en y de l'entité
         *  \return posy **/
        float getPosY();





        /** \fn getConstPosX()
         * \brief Fonction retournant la position en x de l'entité en const
         *  \return const posx **/
        const float getConstPosX() const;

        /** \fn getConstPosY()
         * \brief Fonction retournant la position en y de l'entité en const
         *  \return const posy **/
        const float getConstPosY() const;





        /** \fn setPos(float _posx, float _posy)
         * \param _posx Coordonnées en x
         * \param _posy Coordonnées en x
         * \brief Procédure définissant la position en x et en y **/        
        void setPos(float _posx, float _posy);

        /** \fn setPosX(float _posx)
         * \param _posx Coordonnées en x
         * \brief Procédure définissant la position en x **/   
        void setPosX(float _posx);

        /** \fn setPosY(float _posy)
         * \param _posy Coordonnées en y
         * \brief Procédure définissant la position en y **/   
        void setPosY(float _posy);





        /** \fn setSpeed(int _speed)
         * \param _speed vitesse de l'entité
         * \brief Procédure définissant la vitesse de l'entité **/   
        void setSpeed(int _speed);

        /** \fn getConstSpeed()
         * \brief Fonction retournant la vitesse de l'entité en const
         * \return const speed **/   
        const int getConstSpeed() const ;





        /** \fn getDamage()
         * \brief Fonction retournant les dégats de l'entité en const
         * \return const damage **/   
        int getDamage() const;

        /** \fn setDamage(int _damage)
         * \param _damage dégats de l'entité
         * \brief Procedure définissant les dégats de l'entité **/   
        void setDamage(int _damage);





        /** \fn getPV()
         * \brief Fonction retournant les PV de l'entité en const
         * \return const PV **/   
        int getPV() const;

        /** \fn setPV(int _PV)
         * \param _PV pv de l'entité
         * \brief Procedure définissant les PV de l'entité **/   
        void setPV(int _PV);





        /** \fn setIsDead(bool _isDead)
         * \param _isDead booléen vie de l'entité
         * \brief Procedure définissant la vie ou la mort de l'entité **/   
        void setIsDead(bool _isDead);

        /** \fn getIsDead()
         * \brief Fonction retournant la mort ou non de l'entité
         * \return true si l'entité est mort
         * \return false si l'entité est en vie  **/   
        bool getIsDead();

};

#endif // _ENTITY_H_