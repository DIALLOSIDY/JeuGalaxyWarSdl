
#pragma once

#include "SDLTtf.h"   /// inclusion de SDLTtf pour les textures
#include "rectangle.h"  /// inclusion de la structure rectangle

/**
 * @brief la classe Menu pour gerer le menu du jeu
 */
class Menu{
   public:
    int itemWith ;
    int itemHeigh ;
    Point position[10]; /// un tableau de position ,pour la position de chaque message du menu
    Rectangle posMenu ; /// le rectangle destination qui contiendra le menu
    Rectangle reset ; /// le rectangle destination qui contiendra la popop apres gameover
    int itempos{} ;



    /**
     * le constructeur de la classe menu
     */
    Menu();
    /**
     * @brief fonction qui permettra de dessiner tout ce qui'il y'aura dans le menu
     * @param renderer pointeur sur le rendu de la fenetre
     * @param font   une fonte pour le texte qui sera afficher
     * @param color une couleur pour le texte qui sera affiché
     */

    void drawMenu(SDL_Renderer *renderer ,TTF_Font * font ,SDL_Color color);

    /**
     *@brief cette classe permet de detecter si il y'a eu un clic sur un item precis
     * @param souris represente le coordees x et y de la souris au moment du clic
     * @return un int correpondant a l'itemps cliqué
     */
    int detectionClic(Point souris);

};