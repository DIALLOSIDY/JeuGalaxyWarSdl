#ifndef PROJETCONCEPTION_AVION_H
#define PROJETCONCEPTION_AVION_H
#include <iostream>
#include <vector>
#include "balle.h"
#include"point.h"
#include "direction.h"
#include <chrono>

//#include "direction.h"

/**
 * @class Avion
 *
 * @brief Classe qui gere un un avion et ses caractéristiques.
 *
*/


class Avion{
private:
    Point position; ///< Un vecteur pour la position de l'avion
    float vitesse; ///< La vitesse de l'avion qui dira de combien de pixels il doit se deplacer
    Direction dir; ///< Une direction de type enumeree pour la balle
    std::vector <Balle> tab; ///< un tableau dynamique de balles
    float vie; ///< un entier qui represente le vie de l'avion
    std::chrono::steady_clock::time_point dernierTir; ///< Le temps du dernier tir


public:

    /**
     * @brief fonction qui recupere la direction de l'avion
     */
     Direction getdir();

    /**
     * @brief Recupere la cordonnée x du pofloat
     *
     */

    float getPosX() const;


    /**
     * @brief Recupere la cordonnée y du pofloat
     *
     */

    float getPosY() const;


    /**
     * @brief Recupere la taille du tableau de balles
     *
     */
    std::vector<Balle> getTab() const;

    /**
     *
     * @brief modifie la position x de l'avion
     */

    void setPosX(float x);


    /**
     *
     * @brief modifie la position y de l'avion
     */

    void setPosY(float y);


    /**
     * @brief Recupere la vie de l'avion
     *
     */


    float getVie() const;
    /**
   * @brief Recupere la vie de l'avion
   *
   */


    /**
    * @brief modifie la vie de l'avion
    *
    */
    void setVie(float vie);

    /**
     *
     * @brief consturcteur par defaut de l'avion
     */
    Avion();

    /**
     * @brief constructeur qui initialise sa position, sa vitesse, et sa vie
     * @param x position en x
     * @param y position en Y
     * @param vitesse la vitesse de l'avion
     * @param vie son nombre de vie
     */
    Avion(float x, float y, float vitesse, float vie);

    /**
     * @brief destructeur de la classe , mets sa postion et sa vitesse à 0
     */
    ~Avion();

    /**
     * @fn bougerAvionGauche() Fonction qui fait bouger l'avion vers la gauche
     * @brief Sa position est modifée
     *
     */

    void bougerAvionGauche(const Point & collision);
    /**
       *
       * @brief Fonction qui fait bouger l'avion vers la droite
       * @param collision le point qui sera la largeur et la hauteur de la fenetre
       * Ce point servira à faire un rectangle entre les point (0,0) , (0,hauteur de la fenetre),
       * (0,largeur de la fenetre) et (hauteur,largeur)
       *
       */

    void bougerAvionDroite(const Point & collision);

    /**
    *
    * @brief Fonction qui fait bouger l'avion vers le haut, sa position est modifée
    * @param collision le point qui sera la largeur et la hauteur de la fenetre
    *
    */

    void bougerAvionHaut(const Point & collision);

    /**
     *
     * @brief Fonction qui fait bouger l'avion vers le bas , sa position est modifée
     *  @param collision le point qui sera la largeur et la hauteur de la fenetre
     *
     */

    void bougerAvionBas(const Point & collision);


    /**
     *
     * @brief Elle tire une balle dans une direction donnéé , les parametres servent à creer la balle au bon endroit
     * Elle qui une balle et la stock dans le tableau dynamique de balles
     * @param x la largeur de l'avion
     * @param y la hauteur de l'avion
     *
     */

    void tirer(int x, int y);

    /**
     * @brief S'assure que tout fonctionne bien
     */

    static void testRegression();

    /**
     * @brief, Cette fonction met à jour le tableau de balle en supprimant les balles déja sortis de la fenêtre
     * @param collision , forme un rectangle comme dans les fonctions plus haut
     *
     */

    void misAjourBalle(const Point & collision);

    /**
     * @brief , Cette fonction recupere en fonction de la direction de l'avion, un angle de rotation qui va permettre
     * de faire tourner le sprite de l'avion
     * @param dir sera la direction de l'avion lors de l'appel de la fonction
     */
    static float angle(const Direction & dir );
};

#endif //PROJETCONCEPTION_AVION_H

