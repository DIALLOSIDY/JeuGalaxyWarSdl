#include "avion.h"
#include <cassert>

#include <iostream>

Direction Avion::getdir() {return this->dir;}

float  Avion::getPosX() const {
    return this->position.posX;
}
float  Avion::getPosY() const{
    return  this->position.posY;
}

std::vector<Balle> Avion::getTab() const {return this->tab;}

float Avion::getVie() const {
    return vie ;
}

void Avion::setVie(float _vie) {
    this->vie =_vie;
}

void Avion::setPosX(float x) {
    this->position.posX =x ;
}

void Avion::setPosY(float y) {
    this->position.posY =y;
}


Avion::Avion()
{
    this->position.posX=0;
    this->position.posY=0;
    this->vitesse = 0;
    this->vie = 1;
    this->dir = Direction::HAUT;
    dernierTir = std::chrono::steady_clock::now();
}
Avion::Avion(float x, float y, float vitesse, float vie)
{
    this->position.posX = x;
    this->position.posY = y;
    this->vitesse = vitesse;
    this->vie = vie;
    this->dir = Direction::HAUT;
}

Avion::~Avion()
{
    this->vie=0;
    this->position.posX = -10;
    this->position.posY = -10;
}

void Avion::bougerAvionDroite(const Point & collision)
{
    if(this->position.posX < collision.posX-1)
    {
        this->position.posX+=vitesse;

    } else
        this->position.posX = position.posX;
    this->dir = Direction::DROITE;
}

void  Avion::bougerAvionGauche(const Point & collision)
{
    if(this->position.posX > 1)
    {
        this->position.posX-=vitesse;

    } else
        this->position.posX = position.posX;
    this->dir = Direction::GAUCHE;
}

void Avion::bougerAvionHaut(const Point & collision)
{
    if(this->position.posY > 1)
    {
        this->position.posY-=vitesse;

    }else
        this->position.posY = position.posY;
    this->dir = Direction::HAUT;
}

void Avion::bougerAvionBas(const Point & collision)
{
    if(this->position.posY >= collision.posY-1)
    {
        this->position.posY = position.posY;
    }
    else
    {
        this->position.posY+=vitesse;
    }
    this->dir = Direction::BAS;
}

void Avion::tirer(int x, int y) {

    auto maintenant = std::chrono::steady_clock::now();


    auto dureeDepuisDernierTir = std::chrono::duration_cast<std::chrono::milliseconds>(maintenant - dernierTir);


    if (dureeDepuisDernierTir.count() >=150) {

        if(dir == Direction::DROITE) {
            Balle b = {this->position.posX+x, this->position.posY+(y/2), this->dir};
            this->tab.emplace_back(b);
        }else if(dir == Direction::GAUCHE)
        {
            Balle b = {this->position.posX-x, this->position.posY+(y/2), this->dir};
            this->tab.emplace_back(b);
        }
        else if(dir == Direction::HAUT)
        {
            Balle b = {this->position.posX+(x/2), this->position.posY, this->dir};
            this->tab.emplace_back(b);
        }
        else
        {
            Balle b = {this->position.posX+(x/2), this->position.posY+y, this->dir};
            this->tab.emplace_back(b);
        }

        dernierTir = maintenant;
    }
}


void  Avion::misAjourBalle(const Point & collision) {
    std::vector<Balle> nouveau;
    for(int i=0; i<tab.size();i++)
    {
        bool axeX = tab[i].posBalle.posX > 0 && tab[i].posBalle.posX <= collision.posX+10;
        bool axeY = tab[i].posBalle.posY > 0 && tab[i].posBalle.posY <= collision.posY+10;
        switch (this->tab[i].balleDirection)
        {
            case Direction::HAUT :
                    this->tab[i].posBalle.posY -=0.3;
                break;
            case Direction::BAS:
                    this->tab[i].posBalle.posY +=0.3;
                break;
            case Direction::DROITE:
                    this->tab[i].posBalle.posX +=0.3;
                break;
            case Direction::GAUCHE:
                    this->tab[i].posBalle.posX -=0.3;
                break;
        }
        if(axeX && axeY)
        {
            nouveau.push_back(tab[i]);
        }
    }
    tab = nouveau;
}
float Avion::angle(const Direction & dir)
{
    switch (dir) {
        case Direction::HAUT:
            return 0;
        case Direction::BAS:
            return 180;
        case Direction::GAUCHE:
            return 270;
        case Direction::DROITE:
            return 90;
        default:
            return 0;
    }
}

void  Avion::testRegression()
{
    Avion A;
    Point test(50,50);
    assert(A.position.posX == 0);
    assert(A.position.posY == 0);
    A.bougerAvionDroite(test);
    assert((A.position.posX-A.vitesse)==0);

    A.bougerAvionHaut(test);
    assert((A.position.posY-A.vitesse) ==0);

    A.bougerAvionGauche(test);
    assert((A.position.posX-A.vitesse) == 0);

    std::cout << "------------ test avion reussi ------------ \n";

}
