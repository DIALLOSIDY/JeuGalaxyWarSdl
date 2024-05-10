
#include "SDLGame.h"

int main (int argc, char* argv[]) {
    // Création de l'instance de SDLGame
    SDLGame sg;

    // Attendre que l'utilisateur ferme la fenêtre


    while(sg.isOpen){
        sg.evenement();
        //std::cout<<"menu itempos="<<sg.menu.itempos<<std::endl;
        switch (sg.menu.itempos) {
            case 0:
                sg.runMenu();
                //std::cout<<"blabla"<<sg.menu.itempos<<std::endl ;
                break;
            case 1:
                sg.runProject();
                break;
            case 2:
                sg.isOpen = false;
                break;


        }
    }

    return 0;
}