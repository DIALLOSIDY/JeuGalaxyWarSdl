#include "game.h"

Game::Game() :e(),avion(10,200,0.3,500),score(0) {
    controlleur = '\0';
    Game::tempsDerniereVague = std::chrono::steady_clock::now();
}

bool Game::verifieCollision(Rectangle rect1, Point balle) {
    return (balle.posX >= rect1.x && balle.posX <= rect1.x + rect1.w &&
            balle.posY >= rect1.y && balle.posY <= rect1.y + rect1.h);
}

void Game::collisionAvionBalle() {
    Rectangle rectAvion = { avion.getPosX(), avion.getPosY(), avionWidth, avionHeigh };
    // Parcourir toutes les balles ennemies
    for (int i = 0; i < tabVague.size(); ++i) {
        for (int j = 0; j < tabVague[i].tabBalle.size(); j++) {
            Point pos= {tabVague[i].tabBalle[j].posBalle.posX,tabVague[i].tabBalle[j].posBalle.posY};
            if (verifieCollision(rectAvion, pos)) {
                avion.setVie(avion.getVie()- 1);
            }
        }
    }

}

void Game::collisionEnnemiBalle() {

    // Parcourir toutes les balles ennemies
    for (int i = 0; i < avion.getTab().size(); ++i) {
        for (int j = 0; j < tabVague.size(); j++) {
            Rectangle rectEnnemi = { tabVague[j].pos.posX,tabVague[j].pos.posY, ennemiWidth, ennemiHeigh };
            Point pos= {avion.getTab()[i].posBalle.posX,avion.getTab()[i].posBalle.posY};
            if (verifieCollision(rectEnnemi, pos)) {
                tabVague.erase(tabVague.begin() + j);
                score++ ;
            }

        }
    }
}

bool Game::gameOver() {
    if(avion.getVie()==0){
        return true;
    }
    return false;
}
//gestion de vagues

void Game::generationVague(){
    // Génération aléatoire du nombre d'ennemis dans la vague (entre 2 et 5)
    srand(time(nullptr));
    int numEnemies = rand()%4+1; // Pour générer un nombre aléatoire entre 2 et 5

    // Initialisation des ennemis pour cette vague
    for (int i = 0; i < numEnemies; ++i) {
        int y =rand() % 500; //pour generer la position aleatoire sur le y car mon x est fixe
         Ennemi ennemi(630,y,0,0.0,std::chrono::steady_clock::now(),0.1,0.9);
         tabVague.push_back(ennemi);
    }
}


void Game::mouveVague(){
    for(int i=0 ;i<tabVague.size();i++){
        tabVague[i].bougerHorizontal();
        tabVague[i].tirerBalle();
        tabVague[i].deplacerBalle();

    }
}

void Game::lancerVague() {
    //Uint32 temps = SDL_GetTicks();
    // Obtenir le temps actuel
    auto maintenant = std::chrono::steady_clock::now();

    // Vérifier si suffisamment de temps s'est écoulé depuis le dernier tir
    if (std::chrono::duration_cast<std::chrono::milliseconds>(maintenant - tempsDerniereVague).count() >= 3000) {
        // Si oui, créer une balle
        generationVague();

        // Mettre à jour le temps du dernier tir
        tempsDerniereVague = maintenant;
    }
}



void Game::update(char c,const Point & collision, int x, int y) {
    gestionClavier(c,collision,x,y);
    avion.misAjourBalle(collision);
   lancerVague();
   mouveVague();
    collisionAvionBalle();//collision balles  ennemi vers avion
    collisionEnnemiBalle(); //collision balles avion vers ennemis
    gameOver();
}

void Game::gestionClavier(char c, const Point & collision, int x , int y) {

    switch (c) {
        case 'l':
            avion.bougerAvionGauche(collision);
            break;
        case 'r':
            avion.bougerAvionDroite(collision);
            break;
        case 'u':
            avion.bougerAvionHaut(collision);
            break;
        case 'd':
            avion.bougerAvionBas(collision);
            break;
        case 'x':
            avion.tirer(x,y);
            break;
    }
}