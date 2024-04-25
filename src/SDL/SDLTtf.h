
#ifndef  SDLTTF_H
#define SDLTTF_H
#ifdef __linux__
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#else
#include "SDL.h"      /**< Inclut le fichier d'en-tête SDL */
#include "SDL_ttf.h"
#endif


#include "point.h"

 class SDLTtf{
 public:
    SDL_Surface * _surface ;
     SDL_Texture * _texture ;

     /**
      * @brief constructeur de la classe
      */
     SDLTtf();

     /**
      * @brief destructeur de la classe
      */
     ~SDLTtf();

     /**
      *
      * @param path represente le chemin vers la fonte
      * @param size represente la taille avec laquelle la font est chargée
      * @return la font chargée
      */
     static TTF_Font *loadFont(const char *path ,int size);

     /**
      *
      * @param renderer le rendu sur lequel on dessine
      * @param font la font a dessinée
      * @param message le message
      * @param color la couleur
      * @param posMessage la position du message sur la fenetre
      * @param w la largeur du message
      * @param h la hauteur du message
      */

     void drawS(SDL_Renderer *renderer ,TTF_Font *font ,const char * message ,SDL_Color color,Point posMessage,int w,int h
     );

};


#endif