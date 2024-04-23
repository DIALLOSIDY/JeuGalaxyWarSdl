#include "jeuTxt.h"
#include <iostream>

int main(int argc, char **argv)
{
    termClear();
    Game G;
    boucleJeuTxt(G);
    termClear();
    return 0;
}

switch (this->tab[i].balleDirection)
{
case Direction::HAUT :
if(c=='x')
this->tab[i].posBalle.posY --;
break;
case Direction::BAS:  if(c=='x')
this->tab[i].posBalle.posY ++;
break;
case Direction::DROITE: if(c=='x')
this->tab[i].posBalle.posX --;
break;
case Direction::GAUCHE:  if(c=='x')
this->tab[i].posBalle.posX --;
break;
}
