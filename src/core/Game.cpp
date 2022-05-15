#include <iostream>

#include "Game.h"
#include "Enemy.h"
#include "Tower.h"
#include "TowerArcher.h"
#include "TowerMagic.h"
#include "TowerBomb.h"
#include "Projectile.h"


#include <list>
using namespace std;


Game::Game(){
    enemies.push_front(new Enemy);
    projectiles1.push_front(new Projectile);
    towers.push_front(new TowerArcher);
    countTower = 1;
    newProjectile1 = true;
    newTower = true;
    newEnemy = true;
    

}



Game::~Game(){
    projectiles1.clear();
    projectiles2.clear();
    projectiles3.clear();
    projectiles4.clear();
    projectiles5.clear();
    projectiles6.clear();
    projectiles7.clear();
    projectiles8.clear();
    projectiles9.clear();
    towers.clear();
    enemies.clear();
}


void Game::coordTowersFonction(std::vector<float> coord) {
    for (int n = 0; n <= 5; n++) {
            coordTowers->assign(n,coord[n]);
    }
}



void Game::earnGold(){
    gold.setGold(gold.getGold() + 10);

}

void Game::addTowerArch() {

    if (getCountTower()<9 && gold.getGold() >= 100) {
        towers.push_back(new TowerArcher);
        setCountTower(getCountTower()+1);
        gold.setGold(gold.getGold() - 100);

        if (getCountTower() == 2) {
            getItTower(towers, 1) -> setPos(coordTowers[1][0],coordTowers[1][1]);
            projectiles2.push_front(new Projectile);
            getItProjectile(projectiles2,0)->setTime(10);
            newProjectile2 = true;
            newTower = true;
        }

        if (getCountTower() == 3) {
            getItTower(towers, 2) -> setPos(coordTowers[2][0],coordTowers[2][1]);
            projectiles3.push_front(new Projectile);
            getItProjectile(projectiles3,0)->setTime(10);
            newProjectile3 = true;
            newTower = true;
        }

        if (getCountTower() == 4) {
            getItTower(towers, 3) -> setPos(coordTowers[3][0],coordTowers[3][1]);
            projectiles4.push_front(new Projectile);
            getItProjectile(projectiles4,0)->setTime(10);
            newProjectile4 = true;
            newTower = true;
        }  

        if (getCountTower() == 5) {
            getItTower(towers, 4) -> setPos(coordTowers[4][0],coordTowers[4][1]);
            projectiles5.push_front(new Projectile);
            getItProjectile(projectiles5,0)->setTime(10);
            newProjectile5 = true;
            newTower = true;
        }

        if (getCountTower() == 6) {
            getItTower(towers, 5) -> setPos(coordTowers[5][0],coordTowers[5][1]);
            projectiles6.push_front(new Projectile);
            getItProjectile(projectiles6,0)->setTime(10);
            newProjectile6 = true;
            newTower = true;
        } 

        if (getCountTower() == 7) {
            getItTower(towers, 6) -> setPos(coordTowers[6][0],coordTowers[6][1]);
            projectiles7.push_front(new Projectile);
            getItProjectile(projectiles7,0)->setTime(10);
            newProjectile7 = true;
            newTower = true;
        } 

        if (getCountTower() == 8) {
            getItTower(towers, 7) -> setPos(coordTowers[7][0],coordTowers[7][1]);
            projectiles8.push_front(new Projectile);
            getItProjectile(projectiles8,0)->setTime(10);
            newProjectile8 = true;
            newTower = true;
        } 

        if (getCountTower() == 9) {
            getItTower(towers, 8) -> setPos(coordTowers[8][0],coordTowers[8][1]);
            projectiles9.push_front(new Projectile);
            getItProjectile(projectiles9,0)->setTime(10);
            newProjectile9 = true;
            newTower = true;
        }   

    }

}

void Game::addTowerMagic() {

    if (getCountTower()<9 && gold.getGold() >= 100) {
        towers.push_back(new TowerMagic);
        setCountTower(getCountTower()+1);
        gold.setGold(gold.getGold() - 100);

        if (getCountTower() == 2) {
            getItTower(towers, 1) -> setPos(coordTowers[1][0],coordTowers[1][1]);
            projectiles2.push_front(new Projectile);
            getItProjectile(projectiles2,0)->setTime(7);
            getItProjectile(projectiles2,0)->fctPath("data/Projectile/Magic01.png");
            newProjectile2 = true;
            newTower = true;
        }

        if (getCountTower() == 3) {
            getItTower(towers, 2) -> setPos(coordTowers[2][0],coordTowers[2][1]);
            projectiles3.push_front(new Projectile);
            getItProjectile(projectiles3,0)->setTime(7);
            getItProjectile(projectiles3,0)->fctPath("data/Projectile/Magic01.png");
            newProjectile3 = true;
            newTower = true;
        }

        if (getCountTower() == 4) {
            getItTower(towers, 3) -> setPos(coordTowers[3][0],coordTowers[3][1]);
            projectiles4.push_front(new Projectile);
            getItProjectile(projectiles4,0)->setTime(7);
            getItProjectile(projectiles4,0)->fctPath("data/Projectile/Magic01.png");
            newProjectile4 = true;
            newTower = true;
        }  

        if (getCountTower() == 5) {
            getItTower(towers, 4) -> setPos(coordTowers[4][0],coordTowers[4][1]);
            projectiles5.push_front(new Projectile);
            getItProjectile(projectiles5,0)->setTime(7);
            getItProjectile(projectiles5,0)->fctPath("data/Projectile/Magic01.png");
            newProjectile5 = true;
            newTower = true;
        }  

        if (getCountTower() == 6) {
            getItTower(towers, 5) -> setPos(coordTowers[5][0],coordTowers[5][1]);
            projectiles6.push_front(new Projectile);
            getItProjectile(projectiles6,0)->setTime(7);
            getItProjectile(projectiles6,0)->fctPath("data/Projectile/Magic01.png");
            newProjectile6 = true;
            newTower = true;
        } 

        if (getCountTower() == 7) {
            getItTower(towers, 6) -> setPos(coordTowers[6][0],coordTowers[6][1]);
            projectiles7.push_front(new Projectile);
            getItProjectile(projectiles7,0)->setTime(7);
            getItProjectile(projectiles7,0)->fctPath("data/Projectile/Magic01.png");
            newProjectile7 = true;
            newTower = true;
        } 

        if (getCountTower() == 8) {
            getItTower(towers, 7) -> setPos(coordTowers[7][0],coordTowers[7][1]);
            projectiles8.push_front(new Projectile);
            getItProjectile(projectiles8,0)->setTime(7);
            getItProjectile(projectiles8,0)->fctPath("data/Projectile/Magic01.png");
            newProjectile8 = true;
            newTower = true;
        } 

        if (getCountTower() == 9) {
            getItTower(towers, 8) -> setPos(coordTowers[8][0],coordTowers[8][1]);
            projectiles9.push_front(new Projectile);
            getItProjectile(projectiles9,0)->setTime(7);
            getItProjectile(projectiles9,0)->fctPath("data/Projectile/Magic01.png");
            newProjectile9 = true;
            newTower = true;
        }   

    }

}

void Game::addTowerBomb() {

    if (getCountTower()<9 && gold.getGold() >= 100) {
        towers.push_back(new TowerBomb);
        setCountTower(getCountTower()+1);
        gold.setGold(gold.getGold() - 100);

        if (getCountTower() == 2) {
            getItTower(towers, 1) -> setPos(coordTowers[1][0],coordTowers[1][1]);
            projectiles2.push_front(new Projectile);
            getItProjectile(projectiles2,0)->setTime(15);
            getItProjectile(projectiles2,0)->fctPath("data/Projectile/Bomb01.png");
            newProjectile2 = true;
            newTower = true;
        }

        if (getCountTower() == 3) {
            getItTower(towers, 2) -> setPos(coordTowers[2][0],coordTowers[2][1]);
            projectiles3.push_front(new Projectile);
            getItProjectile(projectiles3,0)->setTime(15);
            getItProjectile(projectiles3,0)->fctPath("data/Projectile/Bomb01.png");
            newProjectile3 = true;
            newTower = true;
        }

        if (getCountTower() == 4) {
            getItTower(towers, 3) -> setPos(coordTowers[3][0],coordTowers[3][1]);
            projectiles4.push_front(new Projectile);
            getItProjectile(projectiles4,0)->setTime(15);
            getItProjectile(projectiles4,0)->fctPath("data/Projectile/Bomb01.png");
            newProjectile4 = true;
            newTower = true;
        }  

        if (getCountTower() == 5) {
            getItTower(towers, 4) -> setPos(coordTowers[4][0],coordTowers[4][1]);
            projectiles5.push_front(new Projectile);
            getItProjectile(projectiles5,0)->setTime(15);
            getItProjectile(projectiles5,0)->fctPath("data/Projectile/Bomb01.png");
            newProjectile5 = true;
            newTower = true;
        }  

        if (getCountTower() == 6) {
            getItTower(towers, 5) -> setPos(coordTowers[5][0],coordTowers[5][1]);
            projectiles6.push_front(new Projectile);
            getItProjectile(projectiles6,0)->setTime(15);
            getItProjectile(projectiles6,0)->fctPath("data/Projectile/Bomb01.png");
            newProjectile6 = true;
            newTower = true;
        } 

        if (getCountTower() == 7) {
            getItTower(towers, 6) -> setPos(coordTowers[6][0],coordTowers[6][1]);
            projectiles7.push_front(new Projectile);
            getItProjectile(projectiles7,0)->setTime(15);
            getItProjectile(projectiles7,0)->fctPath("data/Projectile/Bomb01.png");
            newProjectile7 = true;
            newTower = true;
        } 

        if (getCountTower() == 8) {
            getItTower(towers, 7) -> setPos(coordTowers[7][0],coordTowers[7][1]);
            projectiles8.push_front(new Projectile);
            getItProjectile(projectiles8,0)->setTime(15);
            getItProjectile(projectiles8,0)->fctPath("data/Projectile/Bomb01.png");
            newProjectile8 = true;
            newTower = true;
        } 

        if (getCountTower() == 9) {
            getItTower(towers, 8) -> setPos(coordTowers[8][0],coordTowers[8][1]);
            projectiles9.push_front(new Projectile);
            getItProjectile(projectiles9,0)->setTime(15);
            getItProjectile(projectiles9,0)->fctPath("data/Projectile/Bomb01.png");
            newProjectile9 = true;
            newTower = true;
        }   

    }

}


 //-------------------------------- Accesseurs -----------------------------------

    Ressources& Game::getRessources(){ return gold;}
    const Ressources& Game::getConstRessources() const { return gold;}

    Map& Game::getMap(){ return map;}
    const Map& Game::getConstMap() const { return map;}

    

//-------------------------------------------------------------------------------


int Game::getCountTower() { return countTower; }
void Game::setCountTower(int _count) { countTower = _count; }


//--------------------- Fonctions des itérateurs pour listes --------------------------

    Enemy* Game::getItEnemy(list<Enemy*> _list, int _i){
        list<Enemy*>::iterator it = _list.begin();
        for(int i=0; i<_i; i++){
            ++it;
        }
        return *it;
    }

    Tower* Game::getItTower(list<Tower*> _list, int _i){
        list<Tower*>::iterator it = _list.begin();
        for(int i=0; i<_i; i++){
            ++it;
        }
        return *it;
    }

    Projectile* Game::getItProjectile(list<Projectile*> _list, int _i){
        list<Projectile*>::iterator it = _list.begin();
        for(int i=0; i<_i; i++){
            ++it;
        }
        return *it;
    }
//-------------------------------------------------------------------------------------


//------------------------- Accesseur des tailles de listes ------------------------------

    const int Game::getSizeListEnemy() {
        return enemies.size();
    }

    const int Game::getSizeListTower() {
        return towers.size();
    }

    const int Game::getSizeListProjectile(int numero_list) {
        switch(numero_list) {
            case 1 :
                return projectiles1.size();
            case 2 :
                return projectiles2.size();
            case 3 :
                return projectiles3.size();
            case 4 :
                return projectiles4.size();
            case 5 :
                return projectiles5.size();
            case 6 :
                return projectiles6.size();
            case 7 :
                return projectiles7.size();
            case 8 :
                return projectiles8.size();
            case 9 :
                return projectiles9.size();
            default : return 0;
        }
    }

//----------------------------------------------------------------------------------------





void Game::autoEvents() {

    const int sizeTowers = towers.size();


    int e_track = 0;
    int p_track = 0;
    int t_track = 0;

    getItTower(towers, 0)-> setPos(coordTowers[0][0],coordTowers[0][1]);


    // ---------------------------------------------------------- Avancement et Mort des ennemies ---------------------------------------------------------
    for (int n = 0; n < enemies.size() ; n++) {

        getItEnemy(enemies, n)->walk(road);

        int posx_enemy = (int)getItEnemy(enemies,n)->getPosX();
        int posy_enemy = (int)getItEnemy(enemies,n)->getPosY();

        if (posx_enemy <= (int)road.getPointX(road.taille_cheminTXT)+3 && posx_enemy >= (int)road.getPointX(road.taille_cheminTXT)-3) {
            if (posy_enemy <= (int)road.getPointY(road.taille_cheminTXT)+3 && posy_enemy >= (int)road.getPointY(road.taille_cheminTXT)-3) {
                castle.damageCastle();
                enemies.remove(getItEnemy(enemies, n));
            }
        }
    }
    // ---------------------------------------------------------------------------------------------------------------------------------------------------


    // ------------------------------------------------------------ Avancement des Projectiles ------------------------------------------------------------


        for (t_track = 0 ; t_track < sizeTowers ; t_track++) {

            std::list<Projectile*> projectiles;

            
            if(t_track == 0){projectiles.assign(projectiles1.begin(),projectiles1.end());}
            if(t_track == 1){projectiles.assign(projectiles2.begin(),projectiles2.end());}
            if(t_track == 2){projectiles.assign(projectiles3.begin(),projectiles3.end());}
            if(t_track == 3){projectiles.assign(projectiles4.begin(),projectiles4.end());}
            if(t_track == 4){projectiles.assign(projectiles5.begin(),projectiles5.end());}
            if(t_track == 5){projectiles.assign(projectiles6.begin(),projectiles6.end());}
            if(t_track == 6){projectiles.assign(projectiles7.begin(),projectiles7.end());}
            if(t_track == 7){projectiles.assign(projectiles8.begin(),projectiles8.end());}
            if(t_track == 8){projectiles.assign(projectiles9.begin(),projectiles9.end());}

            

            for (p_track = 0; p_track < getSizeListProjectile(p_track+1) ; p_track ++) {

                for (e_track = 0 ; e_track < enemies.size() ; e_track++) {

                    // Calcule si l'enemie est dans le range : _inRange = true or false
                    getItProjectile(projectiles,p_track)->inRange(*getItEnemy(enemies, e_track),*getItTower(towers, t_track));

                    if(getItProjectile(projectiles,p_track)->_inRange == true) {
                        
                        // attention : pourrait tirer sur chaque enemie a voir ... : && nombre tracking < max tracking
                        if(getItEnemy(enemies, e_track)-> isDead() == false) {
                            getItProjectile(projectiles,p_track)-> track(*getItEnemy(enemies, e_track),*getItTower(towers, t_track), road);
                            break;

                        } 
                    }
                    if (getItEnemy(enemies, e_track)-> isDead() == true) {
                            earnGold();
                            std::cout << "Enemy Dead" << std::endl;
                            enemies.remove(getItEnemy(enemies, e_track));
                            if (e_track > 0) {e_track = e_track+1;}
                            getItProjectile(projectiles,p_track)-> setPos(coordTowers[t_track-1][0],coordTowers[t_track-1][1]);
                            
                    }
                }
            }
        
            if(t_track == 0){projectiles1.assign(projectiles.begin(),projectiles.end());}
            if(t_track == 1){projectiles2.assign(projectiles.begin(),projectiles.end());}
            if(t_track == 2){projectiles3.assign(projectiles.begin(),projectiles.end());}
            if(t_track == 3){projectiles4.assign(projectiles.begin(),projectiles.end());}
            if(t_track == 4){projectiles5.assign(projectiles.begin(),projectiles.end());}
            if(t_track == 5){projectiles6.assign(projectiles.begin(),projectiles.end());}
            if(t_track == 6){projectiles7.assign(projectiles.begin(),projectiles.end());}
            if(t_track == 7){projectiles8.assign(projectiles.begin(),projectiles.end());}
            if(t_track == 8){projectiles9.assign(projectiles.begin(),projectiles.end());}


            projectiles.clear();
        }

    // ---------------------------------------------------------------------------------------------------------------------------------------------------


    time++;
    if(time == 200) {
        enemies.push_back(new Enemy);
        time = 0;
        newEnemy = true;

    }







}