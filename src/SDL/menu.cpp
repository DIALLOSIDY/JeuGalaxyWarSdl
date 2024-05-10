#include "menu.h"

#include "TextureLoader.h"
SDLTtf ttf ;

Menu::Menu():itempos(0){

    posMenu.x = 300;
    posMenu.y = 80;
    posMenu.w = 250;
    posMenu.h = 300;


    reset.x = 300;
    reset.y = 80;
    reset.w = 130;
    reset.h = 100;


    itemWith =100;
    itemHeigh =29;

    position[0].posX =posMenu.x +25 ;
    position[0].posY = posMenu.y+10;
    position[0].items=0 ;
    for (int i = 1; i < 5; ++i) {
        position[i].posX =(posMenu.x +posMenu.w/2)-itemWith/2 ;
        position[i].posY = posMenu.y+((1+i)*45) ;
        position[i].items=i ;

    }

    //reset innacheve our l'instant
    position[3].posX =reset.x+10 ;
    position[4].posX = reset.x+10;
    position[3].posY =reset.h+10 ;
    position[4].posY = reset.h+40;

    //
}


void Menu::drawMenu(SDL_Renderer *renderer, TTF_Font *font, SDL_Color color) {

    SDL_SetRenderDrawColor(renderer ,0,0,0,255);
    SDL_RenderClear(renderer);
    TextureLoader::drawRectangle(renderer,posMenu.x,posMenu.y,posMenu.w,posMenu.h);
    ttf.drawS(renderer , font, " GALAXY WAR ",{0,0,0},position[0],itemWith,itemHeigh);
    ttf.drawS(renderer , font,  "PLAY ",{0,0,0},position[1],itemWith,itemHeigh);
    ttf.drawS(renderer , font,  " QUIT ",{0,0,0},position[2],itemWith,itemHeigh);
    for(int i = 1; i < 3; i++) {
        SDL_SetRenderDrawColor(renderer, 48, 99, 50, 255);
        SDL_Rect rect = {static_cast<int>(position[i].posX), static_cast<int>(position[i].posY), itemWith, itemHeigh};
        SDL_RenderDrawRect(renderer, &rect);
    }
}


int  Menu::detectionClic(Point souris) {
    Point clicPosition ; // Position par défaut si aucun clic détecté

    for (int i = 1; i < 5; ++i) {
        // Vérifie si la position de la souris se trouve à l'intérieur de la zone de l'item i
        if (souris.posX >= position[i].posX && souris.posX <= position[i].posX + itemWith &&
            souris.posY >= position[i].posY && souris.posY <= position[i].posY + itemHeigh) {
            clicPosition = position[i]; // Si le clic est détecté, met à jour la position du clic
            break; // Sort de la boucle dès qu'un clic est détecté
        }
    }
    return clicPosition.items; // Retourne la position du clic (ou la position par défaut si aucun clic détecté)
}


