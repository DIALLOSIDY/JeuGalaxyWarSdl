#ifndef GAME_H
#define GAME_H

#include <vector>
#include "ennemi.h"   /**< Inclut le fichier d'en-tête "ennemi.h" */
#include "avion.h"    /**< Inclut le fichier d'en-tête "avion.h" */
#include "map.h"      /**< Inclut le fichier d'en-tête "map.h" */
#include "config.h"   /**< Inclut le fichier d'en-tête "config.h" */
#include "rectangle.h" /**< Inclut le fichier d'en-tête "rectangle.h" */
#include <unistd.h>

/**
 * @brief La classe Game représente le jeu lui-même.
 */
class Game {
public:
    Ennemi e;
    Avion avion;
    int score ;
    /**< Caractère qu'on recupere depuis le SDGAME.cpp */
    char controlleur ;



    std::chrono::steady_clock::time_point tempsDerniereVague ;/**< Dernier temps où une vague a été lancée */

    // Gestion des vagues
    std::vector<Ennemi> tabVague; /**< Vecteur d'ennemis formant une vague */

    /**
     * @brief Constructeur de la classe Game.
     */
    Game();

    /**
     * @brief Méthode pour générer une vague d'ennemis.
     */
    void generationVague();

    /**
     * @brief Méthode pour gérer les entrées clavier.
     * @param c La touche pressée par le joueur.
     * @param collision La position de collision.
     */
    void gestionClavier(char c, const Point & collision, int x, int y);

    /**
     * @brief Méthode pour vérifier la collision entre un rectangle et une balle.
     * @param rect1 Le rectangle.
     * @param balle La position de la balle.
     * @return True si une collision est détectée, sinon False.
     */
    static bool verifieCollision(Rectangle rect1, Point balle);

    /**
     * @brief Méthode pour gérer les collisions entre l'avion et les balles.
     */
    void collisionAvionBalle();

    /**
     * @brief Méthode pour gérer les collisions entre les ennemis et les balles.
     */
    void collisionEnnemiBalle();

    /**
     * @brief Méthode pour gérer la fin de partie.
     * @return True si la partie est terminée, sinon False.
     */
    bool gameOver();

    /**
     * @brief Méthode pour mettre à jour le jeu.
     * @param c La touche pressée par le joueur.
     * @param collision La position de collision.
     * @param x la largeur de l'avion
     * @param y la hauteur de l'avion
     */
    void update(char c,const Point & collision,int x, int y);

    /**
     * @brief Méthode pour déplacer les ennemis de la vague.
     */
    void mouveVague();

    /**
     * @brief Méthode pour lancer une vague d'ennemis.
     */
    void lancerVague();
};

#endif