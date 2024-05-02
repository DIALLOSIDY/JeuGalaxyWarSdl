#include "SDLGame.h"
#ifdef  __linux__
#include "SDL2/SDL_image.h"
#else
#include "SDL_image.h"
#endif
#include <iostream>

#define height 426
#define width 800

Point point (width -avionWidth ,height-avionHeigh);


void erreur(){

    std::cerr << "Erreur : " << SDL_GetError() << std::endl;
    SDL_Quit() ;
}

 SDLGame::SDLGame():game(),menu(),ttf(),etat(true) , m(44100,MIX_DEFAULT_FORMAT,2,248)/*initialise le game*/ { // Initialisation de SDL
     isOpen =true ;
     text= nullptr;
     textureAvion = nullptr;
     textureBalleAvion = nullptr;
    //rectScore ={150,10,vie,10};
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
         erreur();

     }

     // Création de la fenêtre
     fenetre = SDL_CreateWindow("Ma Fenetre SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height,
                                SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);
     if (fenetre == nullptr) {
         erreur();
     }

     //creation du rendu
     renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
     if (renderer == nullptr) {
         SDL_DestroyWindow(fenetre);
         erreur();
     }

     //TODO SDL trouve l*image en comptatnt depuis l'executable

     text = TextureLoader::loadTexture(renderer,"sample1.bmp");
     bag= TextureLoader::loadTexture(renderer,"ciel.bmp");
     ennemi =TextureLoader::loadTexture(renderer,"Ennemi.png");
     textureAvion = TextureLoader::loadTexture(renderer,"avion.png");
     textureBalleAvion = TextureLoader::loadTexture(renderer,"balle.png");

     msc=m.LoadMusicFromFile("../data/audio/shoot.mp3");//pour charger la musique

     font =ttf.loadFont("../data/ttf/police1.ttf",15);
     gameover =ttf.loadFont("../data/ttf/police1.ttf",50);
     ttfmenu =ttf.loadFont("../data/ttf/police1.ttf",30);

 }


SDLGame::~SDLGame()
{
    SDL_DestroyRenderer(renderer);
    renderer = nullptr;
    SDL_DestroyWindow(fenetre);
    fenetre = nullptr;
    TextureLoader::deallocateTextures();
}


void SDLGame::sdlDraw() {

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    SDL_FRect bagroud ={0,0,width,height};

    SDL_RenderCopyF(renderer, bag , nullptr, &bagroud);

    drawVagueTexture();
    drawBalleVagueTexture();

    float x = game.avion.getPosX();
    float y = game.avion.getPosY();
    float angle = Avion::angle(game.avion.getdir());

    dessineTexture(textureAvion,renderer,x,y,angle,avionWidth,avionHeigh);

    drawBalleAvionTexture();

    //mes textures

    //std::itoa(game.score,buf,10) ;
    sprintf( buf, "%d", game.score);
    //ttf.draw(renderer ,{5,5});
    ttf.drawS(renderer,font,"SCORE :",{255,0,255},{5,5},15,10);
    ttf.drawS(renderer, font, buf, {255, 0, 255}, {60, 5},15,10);
    ttf.drawS(renderer, font, "VIE :", {255, 0, 255}, {100, 5},15,10);


    if(game.gameOver()){
        ttf.drawS(renderer, gameover, "game overrr :", {255, 0, 255}, {280, 150},15,10);
        etat=false ;
        dessineTexture(text,renderer,x,y,angle,avionWidth,avionHeigh);
    }


    if(game.avion.getVie()>=0){
       // game.avion.setVie(game.avion.getVie()-1);
        rectScore ={150,10,game.avion.getVie(),10};
        dessinerScore(rectScore,{0,255,0,0});
    }

}

void SDLGame::drawVagueTexture() {

    for(int i=0 ;i<game.tabVague.size();i++){
        float x = game.tabVague[i].pos.posX;
        float y = game.tabVague[i].pos.posY;
        SDL_FRect r1 = {x,y,ennemiWidth,ennemiHeigh};
        SDL_RenderCopyF(renderer, ennemi , nullptr,&r1);
    }
}

void SDLGame::drawBalleVagueTexture()  {
    for (int i = 0; i < game.tabVague.size(); i++) {
        for (int j = 0; j < game.tabVague[i].tabBalle.size(); j++) {
            float x = game.tabVague[i].tabBalle[j].posBalle.posX;
            float y = game.tabVague[i].tabBalle[j].posBalle.posY;
            SDL_FRect r1 = {x,y,balleWidth,balleHeigh };
            SDL_RenderCopyF(renderer, text , nullptr,&r1);
        }
    }
}

void SDLGame::drawBalleAvionTexture() const {
    for(int i=0 ;i<game.avion.getTab().size();i++){

        float x = game.avion.getTab()[i].posBalle.posX;
        float y = game.avion.getTab()[i].posBalle.posY;
        // +5 juste pour differencier les balles de l'avion et l'ennemi
        SDL_FRect r1 = {x,y,balleWidth+5,balleHeigh+5 };
        SDL_RenderCopyF(renderer, textureBalleAvion , nullptr,&r1);
    }
}


void SDLGame::dessinerScore(Rectangle rect, SDL_Color color) const {
    SDL_FRect rectD ={rect.x,rect.y ,30,rect.h};
    //pour les contours du rectangle de score

    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 0);
    SDL_RenderDrawRectF(renderer, &rectD);

     //pour remplir le rectangle du score
    SDL_FRect rectVert ={rect.x,rect.y ,rect.w,rect.h};
    SDL_SetRenderDrawColor(renderer, color.r,color.g ,color.b ,color.a );
    SDL_RenderFillRectF(renderer, &rectVert);

}

void SDLGame::dessineTexture(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y, float angle, int w, int h) {
SDL_Rect dst;
dst.x = x;
dst.y = y;
dst.w = w;
dst.h = h;
SDL_RenderCopyEx(renderer, texture, NULL, &dst, angle, NULL, SDL_FLIP_NONE);

}



void SDLGame::evenement() {
    // Attendre que l'utilisateur ferme la fenêtre

    SDL_Event event;
    while (SDL_PollEvent(&event) != 0) {
        //m.PlayeMusic(msc);
        switch (event.type) {
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT) {
                    float mouseX = event.button.x; // Coordonnée X du clic de souris
                    float  mouseY = event.button.y; // Coordonnée Y du clic de souris
                    menu.itempos=menu.detectionClic({mouseX, mouseY});
                }

                break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_x:
                            game.controlleur = 'x';
                        break;
                    case SDLK_LEFT:
                        game.controlleur = 'l'; // ou toute autre valeur que vous souhaitez utiliser
                        break;
                    case SDLK_RIGHT:
                        game.controlleur = 'r'; // ou toute autre valeur que vous souhaitez utiliser
                        break;
                    case SDLK_UP:
                        game.controlleur = 'u'; // ou toute autre valeur que vous souhaitez utiliser
                        break;
                    case SDLK_DOWN:
                        game.controlleur = 'd'; // ou toute autre valeur que vous souhaitez utiliser
                        break;

                    case SDLK_c: //pour fermer la fenetre du sdl
                        isOpen = false;
                        break;

                    case SDLK_q:
                        if (Mix_PausedMusic()) {
                            Mix_ResumeMusic();
                        } else {
                            Mix_PauseMusic();
                        }
                        break;
                }
                break;
            case SDL_KEYUP:
                // Réinitialisez 'controlleur' lorsque la touche est relâchée
                game.controlleur = '\0';
                break;

        }
    }
}

void SDLGame::runProject() {
    if (etat) {
        game.update(game.controlleur, point,avionWidth,avionHeigh);
    }
    sdlDraw();
    SDL_RenderPresent(renderer) ;

    }

void SDLGame::runMenu() {
        menu.drawMenu(renderer ,ttfmenu,{255, 0, 255});
        SDL_RenderPresent(renderer) ;
}


