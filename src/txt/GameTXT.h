/**

* \file GameTXT.h
* \brief Fichier s'occupant de l'affichage du jeu en mode texte
* \version 1.0
* \date 4 Avril 2022
* \include WindowTXT.h, Game.h,

*/


#ifndef _GAMETXT_H_
#define _GAMETXT_H_

#include "windowTXT.h"
#include "../core/Game.h"

/** \brief Fonction dans lequel l'affichage se fait
 *  \param win La fenêtre dans laquel l'affichage est fait
 *  \param game Le jeu et ses éléments à afficher
 */
void txtShow(WindowTXT& win, Game& game);

/** \brief Boucle pour l'affichage et la gestion des évènements
 *  \param game Le jeu et ses éléments à afficher
 */
void txtLoop(Game& game);


#endif
