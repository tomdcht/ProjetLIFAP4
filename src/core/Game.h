/**

* \file Game.h
* \brief Définition des donées membres et des fonctions membres de la classe Game
* \version 1.0
* \date 4 Avril 2022
* \include Enemy.h, Map.h, Tower.h, Projectile.h,

*/


#ifndef _GAME_H_
#define _GAME_H_


#include "Ressources.h"
#include "Road.h"
#include "Map.h"
#include "Castle.h"

class Enemy; 
class Tower; 
class TowerArcher; 
class TowerBomb;
class TowerMagic;
class Projectile; 


#include <vector>
#include <list> 




 /** \brief Classe gérant la physique du jeu */
class Game{

    private:
        /** \brief Le cheminnnnnnnnnnnnnnnnnnnnnn */
        Road road;
        Map map;

        // time+1 par actualisation pour le nombre d'ennemies
        int time = 0;
        int n = 0;

        int timeVague1 = 200;
        int timeVague2 = 170;
        int timeVague3 = 150;
        int timeVague4 = 120;
        bool vague1 = true;
        bool vague3 = false;
        bool vague4 = false;
        bool vague2 = false;

        bool vague1End = false;
        bool vague3End = false;
        bool vague4End = false;
        bool vague2End = false;
        int nbTotalEnemy = 0;

        
        int e_minimum = 0;    // PLACER MINIMUM DANS GAME.CPP AUTO EVENTS EN CONST
        int p_minimum = 0;  // PLACER MINIMUM DANS GAME.CPP AUTO EVENTS EN CONST

        /** \brief Nombre de tours actives */
        int countTower;


    public:

        Castle castle;
        Ressources gold;

        bool newEnemy = false;
        bool newTower = false;

        int nbNewEnemy;
        int tabTower[9];

        bool newProjectile1 = false;
        bool newProjectile2 = false;
        bool newProjectile3 = false;
        bool newProjectile4 = false;
        bool newProjectile5 = false;
        bool newProjectile6 = false;
        bool newProjectile7 = false;
        bool newProjectile8 = false;
        bool newProjectile9 = false;

        std::vector<float> coordTowersTXT[5] = {{18.f,19.f},{49.f,16.f},{67.f,20.f}, {76.f,16.f}, {96.f,27.f}};

        std::vector<float> coordTowers[9]= {{160.f, 970.f},{560.f,970.f},{820.f,640.f},{1050.f,420.f},{1200.f,680.f},{1315.f,970.f},{1720.f,970.f},{1425.f,360.f},{1750.f,450.f}};
       


        /** \brief Constructeur de la classe Game*/
        Game ();

        ~Game();

        void coordTowersFonction(std::vector<float> coord);

        /** \brief Fonction gérant tous les évènements automatiques du jeu */
        void autoEvents();

        /** \brief Procédure ajoutant +10 gold*/
        void earnGold();

        /** \brief Procédure ajoutant une tour archer active (max 5)*/
        void addTowerArch(int num);

        /** \brief Procédure ajoutant une tour magique active (max 5)*/
        void addTowerMagic(int num);

        /** \brief Procédure ajoutant une tour magique active (max 5)*/
        void addTowerBomb(int num);

        void coordTower(int num);





        //-------------------------------- Accesseurs -----------------------------------
        
        
            /** \brief Accesseur renvoyant ressources*/     
            Ressources& getRessources() ;  
            /** \brief Accesseur renvoyant ressources de type const*/
            const Ressources& getConstRessources() const;

            /** \brief Accesseur renvoyant le cheminnnnnnnnnnnnnnnnnnnnn */
            Road& getRoad();        
            /** \brief Accesseur renvoyant le cheminnnnnnnnnnnnnnnnnnn de type const*/
            const Road& getConstRoad() const;

            Map& getMap();
            const Map& getConstMap() const;
        //-------------------------------------------------------------------------------



        /** \fn Fonction permettant de récupérer les dégats de la tour*/
        int getDamageArrow();

        /** \brief Procédure modifiant les dégats de la tour */
        void setDamageArrow(int _damage);


        /** \fn Fonction permettant de récupérer le nombre de tour*/
        int getCountTower();

        /** \brief Fonction modifiant le nombre de tours actives */
        void setCountTower(int _count);


        //------------------------------ Décalartion des listes ---------------------------------
            /** \brief Liste d'ennemis */
            std::list<Enemy*> enemies;

            /** \brief Liste des tours */
            std::list<Tower*> towers;

            /** \brief Liste des projectiles de la tour 1 */
            std::list<Projectile*> projectiles1;
            /** \brief Liste des projectiles de la tour 2 */
            std::list<Projectile*> projectiles2;
            /** \brief Liste des projectiles de la tour 3 */
            std::list<Projectile*> projectiles3;
            /** \brief Liste des projectiles de la tour 4 */
            std::list<Projectile*> projectiles4;
            /** \brief Liste des projectiles de la tour 5 */
            std::list<Projectile*> projectiles5;
            /** \brief Liste des projectiles de la tour 6 */
            std::list<Projectile*> projectiles6;
            /** \brief Liste des projectiles de la tour 7 */
            std::list<Projectile*> projectiles7;
            /** \brief Liste des projectiles de la tour 8 */
            std::list<Projectile*> projectiles8;
            /** \brief Liste des projectiles de la tour 9 */
            std::list<Projectile*> projectiles9;
        //---------------------------------------------------------------------------------------


        //--------------------- Fonctions des itérateurs pour listes --------------------------
            /** \brief Fonction modifiant le nombre de tours actives */
            Enemy* getItEnemy(std::list<Enemy*> _list, int _i);
            /** \brief Fonction modifiant le nombre de tours actives */
            Tower* getItTower(std::list<Tower*> _list, int _i);
            /** \brief Fonction modifiant le nombre de tours actives */
            Projectile* getItProjectile(std::list<Projectile*> _list, int _i);
        //---------------------------------------------------------------------------------------


        //------------------------- Accesseur des tailles de listes ------------------------------
            /** \fn Fonction const permettant de récupérer la taille de la liste Enemy*/
            const int getSizeListEnemy();

            /** \fn Fonction const permettant de récupérer la taille d'une liste de Projectile*/
            const int getSizeListProjectile(int numero_list);

            /** \fn Fonction const permettant de récupérer la taille de la liste de Tours*/
            const int getSizeListTower();
        //----------------------------------------------------------------------------------------


};

#endif