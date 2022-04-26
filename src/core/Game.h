/**

* \file Game.h
* \brief Définition des donées membres et des fonctions membres de la classe Game
* \version 1.0
* \date 4 Avril 2022
* \include Enemy.h, Map.h, TowerArcher.h, Projectile.h,

*/


#ifndef _GAME_H_
#define _GAME_H_

#include "Enemy.h"
#include "Map.h"
#include "TowerArcher.h"
#include "Projectile.h"
#include "Ressources.h"
#include "Castle.h"

 /** \brief Classe gérant la physique du jeu */
class Game{

    private:

        /** \brief Un ennemi*/
        Enemy enemy;
        /** \brief La map */
        Map map;
        /** \brief Une tour d'archer*/
        TowerArcher towerArch;
        /** \brief Un projectile de type flèche*/
        Projectile arrow;
        /** \brief Les ressources géré dans le  jeu */
        Ressources gold;
        /** \brief Le chateau */
        Castle castle;

        int time = 0;
        int n = 0;
        int trace = 0;
        int n_track = 0;
        int minimum = 0;

    public:

        /** \brief Liste d'ennemis */
        std::list<Enemy*> enemies;

        /** \brief Liste d'ennemis */
        std::list<TowerArcher*> towers;

        /** \brief Liste d'ennemis */
        std::list<Projectile*> projectiles;

        /** \brief Constructeur de la classe Game*/
        Game ();

        /** \brief Accesseur renvoyant un ennemi */
        Enemy& getEnemy();
        /** \brief Accesseur renvoyant la map */
        Map& getMap();
        /** \brief Accesseur renvoyant une tour d'archer */
        TowerArcher& getTowerArcher();
        /** \brief Accesseur renvoyant un ennemide type const */
        const Enemy& getConstEnemy () const;
        /** \brief Accesseur renvoyant la map de type const */
        const Map& getConstMap () const;
        /** \brief Accesseur renvoyant une tour de type const */
        const TowerArcher& getConstTowerArcher () const;
        /** \brief Accesseur renvoyant un projectile de type const*/
        const Projectile& getConstProjectile () const;
        /** \brief Accesseur renvoyant un projectile de type const*/
        Projectile& getProjectile ();
        /** \brief Accesseur renvoyant une classe ressources de type const*/
        const Ressources& getConstRessources() const;
        /** \brief Accesseur renvoyant le chateau de type const*/
        const Castle& getConstCastle() const;

        void earnGold();

        Enemy* getItEnemy(std::list<Enemy*> _list, int _i);
        TowerArcher* getItTower(std::list<TowerArcher*> _list, int _i);
        Projectile* getItProjectile(std::list<Projectile*> _list, int _i);

         /** \fn Fonction const permettant de récupérer la taille de la liste*/
        const int getSizeListEnemy();
        const int getSizeListProjectile();
        const int getSizeListTower();

        /** \brief Fonction gérant tous les évènements automatiques du jeu */
        void autoEvents();

};

#endif