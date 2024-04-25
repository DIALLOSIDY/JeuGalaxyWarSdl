#include "SDLTtf.h"

SDLTtf::SDLTtf() {
    _surface= nullptr;
    _texture= nullptr ;
    if(TTF_Init()==-1){
        SDL_Log("Erreur d'initialisation de ttf");
        return ;
    };
}

SDLTtf::~SDLTtf() {
    SDL_DestroyTexture(_texture);
}

TTF_Font *SDLTtf::loadFont(const char *path, int size) {

    TTF_Font *font = TTF_OpenFont(path ,size);
    return font ;

}




void SDLTtf::drawS(SDL_Renderer *renderer ,TTF_Font *font ,const char * message ,SDL_Color color,Point posMessage,int w,int h){
    _surface = TTF_RenderText_Solid(font, message, color);
    //je creer une texture a partir de la surface
    _texture = SDL_CreateTextureFromSurface(renderer,_surface);
    SDL_Rect rectDest ={static_cast<int>(posMessage.posX) ,static_cast<int>(posMessage.posY) ,_surface->w,_surface->h} ;
    SDL_RenderCopy(renderer ,_texture , nullptr,&rectDest);

    SDL_FreeSurface( _surface);
    SDL_DestroyTexture( _texture);

}
