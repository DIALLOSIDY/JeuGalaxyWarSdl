#pragma  once

#include "balle.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>


/**
 * @class Ennemi
 * @brief class liee a la gestion des ennemis et leurs balles
 */
class Ennemi {
public:
    Point pos;
    int vie;
    float vitesse;
    std::vector<Balle> tabBalle;
    float vitesseBalle;
    std::chrono::steady_clock::time_point DernierTir ;

    /**
     * @brief represente le constructeur de ma classe
     */
    Ennemi();
    /**
     * @brief represente le constructeur de ma classe
     */
    Ennemi(float x ,float y ,int vie ,float tempsDernierTir, std::chrono::steady_clock::time_point _DernierTir  ,float vitesse,float vitesseBalle);


    /**
     * @brief cette fonction permettra de faire bouger l'ennemi de façon horizontale
     */
    void bougerHorizontal();

    /**
     * @brief cette fonction permettra de creer une balle et de l'ajouter dans le tableau dynamique
     */
    void creerBalle();

    /**
     * @brief fonction qui permet de regulariser l'espacement des balles en font du temps
     * @param temps variable qui permettra de recuperer le temps ecoulé avec SDL_Geticks()
     */
    void tirerBalle();

    /**
     * @brief fonction qui permet de deplacer les balles
     */
    void deplacerBalle();


};
