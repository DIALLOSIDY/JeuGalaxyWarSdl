#ifndef BALLE_H
#define BALLE_H

#include "point.h"      /**< Inclut le fichier d'en-tête "point.h" */
#include "direction.h"  /**< Inclut le fichier d'en-tête "direction.h" */

/**
 * @brief La classe Balle représente une balle.
 */
class Balle {
public:
    Point posBalle;         /**< Position de la balle */
    Direction balleDirection; /**< Direction de la balle */

    /**
     * @brief Constructeur de la classe Balle.
     * @param x La coordonnée X initiale de la balle.
     * @param y La coordonnée Y initiale de la balle.
     * @param DIR La direction initiale de la balle.
     */

    Balle(float x, float y, Direction DIR) {

        posBalle.posX = x;  /**< Initialise la position X de la balle avec la valeur passée en paramètre */
        posBalle.posY = y;  /**< Initialise la position Y de la balle avec la valeur passée en paramètre */
        balleDirection = DIR; /**< Initialise la direction de la balle avec la valeur passée en paramètre */

    };
};

#endif