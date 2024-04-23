
#include "jeuTxt.h"
#include "winTxt.h"
#include <unistd.h>

void afficher(WinTXT & win, Game G)
{
    //int x =(int) G.avion.getPosX();
    //int y = (int) G.avion.getPosY();

    win.clear();
    for(int i=0;i<G.M.dimX;i++)
    {
        for(int j=0; j<G.M.dimY;j++)
        {
            win.print(i,j,G.M.getObjetChar(i,j));
        }
    }
    win.print(G.avion.getPosX(),G.avion.getPosY(),'A');
    win.draw();
}

void boucleJeuTxt(Game & G)
{
    WinTXT win(51,51);
    G.collision = {50,50};
    bool jeu = true;
    while(jeu)
    {
        win.clear();
        afficher(win,G);
        sleep(3);
        char c = win.getCh();
        switch (c) {
            case 'h':
                G.gestionClavier('u');
                break;
            case 'b':
                G.gestionClavier('d');
                break;
            case 'g':
                G.gestionClavier('l');
                break;
            case 'd':
                G.gestionClavier('r');
                break;
            case 'q':
                jeu=false;
                break;
            default:
                break;

        }
    }



}
