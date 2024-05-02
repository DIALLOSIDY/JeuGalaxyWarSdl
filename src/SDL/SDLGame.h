#pragma once
#ifdef __linux__
#include "SDL2/SDL.h"
#else
#include "SDL.h"
#endif

//#include "SDLSprite.h"    /**< Inclut le fichier d'en-tête SDLSprite */
#include "../core/game.h"
#include "SDLMusic.h"
#include "SDLTtf.h"
#include "menu.h"
#include <chrono>
#include "TextureLoader.h"
#include "../core/config.h"

/**
 * @brief La classe SDLGame représente le jeu SDL.
 */
class SDLGame {
public:
    SDL_Window *fenetre = nullptr; /**< Fenêtre SDL */
    SDL_Renderer *renderer = nullptr; /**< Renderer SDL */

    SDL_Texture *text;
    SDL_Texture *bag;
    SDL_Texture *ennemi;
    SDL_Texture *textureAvion; ///< un pointeur qui est la texture de l'avion
    SDL_Texture * textureBalleAvion; ///< un pointeur sur la balle des avions pour leur textures
    //int score = 0; /**< Score du jeu */
    Rectangle rectScore; /**< Rectangle pour afficher le score */

    bool isOpen;

    // Gestion des vagues

    Uint32 time = SDL_GetTicks();
    // Fin de la gestion des vagues

    Game game; /**< Instance du jeu */
    Menu menu;
    SDLTtf ttf; /**< Instance de SDLTtf */
    bool etat; /// cette variable me permet d'arreter le jeu apres le gameover

    // Son
    SDLSound m; /**< Son SDL */
    Mix_Music *msc; /**< Musique SDL */


    // Textures
    TTF_Font *font; /**< Police de caractères SDL */
    TTF_Font *gameover;
    TTF_Font *ttfmenu;


    char buf[150]; /**< Tampon pour le texte */






    /**
     * @brief Constructeur de la classe SDLGame.
     */
    SDLGame();

    /**
     * @brief Destructeur de la classe SDLGame.
     */
    ~SDLGame();

    /**
     * @brief Méthode pour dessiner les éléments du jeu SDL.
     */
    void sdlDraw();


    /**
     * @brief Méthode pour initialiser les textures des ennemis de la vague.

     */
    void drawVagueTexture();

    /**
     * @brief Méthode pour initialiser la texture des balles de la vague.

     */
    void drawBalleVagueTexture();


    /**
     * @brief Méthode pour initialiser les textures des balles de l'avion.
     */
    void drawBalleAvionTexture() const;

    /**
     * @brief Méthode pour dessiner le score.
     * @param rect Le rectangle où afficher le score.
     * @param color La couleur du score.
     */
    void dessinerScore(Rectangle rect, SDL_Color color) const;

    /**
     * @brief Méthode pour mettre à jour le jeu SDL.
     */
    void update();

    /**
     * @brief Méthode pour appeler le draw de game.
     */
    void runProject();

    /**
     * @brief se charge de gerer l'affichage du menu
     */
    void runMenu();

    /**
     * @brief se charge de toute la gestion des evenements
     */

    void evenement();

    /**
     * @brief Cette fonction dessine la texture de l'avion sur le renderer avec une rotation d'un angle
     * @param angle l'angle de rotation
     * @param x la position x de l'avion
     * @param y la position y de l'avion
     * @param h la hauteur de l'avion
     * @param w la largeur de l'avion
     */
    void dessineTexture(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y, float angle, int w, int h);

};

