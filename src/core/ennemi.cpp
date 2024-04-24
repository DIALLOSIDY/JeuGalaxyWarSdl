#include "ennemi.h"
#include <iostream>
#include "config.h"
#include "rectangle.h"
#include "SDL.h"


Ennemi::Ennemi():vie(20) {
    pos.posX= 250;
    pos.posY=300;
    vitesse=0 ;
    vitesseBalle=0;
    Ennemi::DernierTir = std::chrono::steady_clock::now();
}

Ennemi::Ennemi(float _x ,float _y ,int _vie ,float _tempsDernierTir,std::chrono::steady_clock::time_point _DernierTir  ,float _vitesse,float _vitesseBalle){
    vie= _vie ;
    pos.posX= _x;
    pos.posY=_y;
    vitesse=_vitesse;
    vitesseBalle=_vitesseBalle;
    DernierTir =_DernierTir ;
}


void Ennemi::bougerHorizontal() {
    this->pos.posX-=vitesse ;
}

// Dans la méthode Ennemi::tirerBalle()
void Ennemi::tirerBalle() {
    // Obtenir le temps actuel
    auto maintenant = std::chrono::steady_clock::now();
    // Vérifier si suffisamment de temps s'est écoulé depuis le dernier tir
    if (std::chrono::duration_cast<std::chrono::milliseconds>(maintenant - DernierTir).count() >= 1000) {
        // Si oui, créer une balle
        creerBalle();
        // Mettre à jour le temps du dernier tir
        DernierTir = maintenant;
    }
}

    void Ennemi::creerBalle() {
        // Utiliser la position stockée pour initialiser la balle

        Direction dir;//juste une direction pour la balle mais pas important pour l'ennemi
        Balle balle(pos.posX, pos.posY, dir);
        tabBalle.push_back(balle);
    }


void Ennemi::deplacerBalle() {
    // Parcourez le tableau de balles à l'envers pour permettre la suppression sans causer de problèmes d'itération
    for (int i=0 ;i<tabBalle.size();i++) {
        // Déplacez la balle
        tabBalle[i].posBalle.posX -= vitesseBalle;
        // Vérifiez si la balle est entièrement hors de la fenêtre
        if (tabBalle[i].posBalle.posX <= 0) {
            // Supprimez la balle du tableau
            tabBalle.erase(tabBalle.begin() + i);
            SDL_Log("balle rest %zu", tabBalle.size());
        }
    }
}



