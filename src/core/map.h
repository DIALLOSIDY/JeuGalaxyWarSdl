#ifndef GALAXY_WAR_MAP_H
#define GALAXY_WAR_MAP_H
#include <cassert>
class Map{
/**
 * @class Map
 * @brief La classe Map représente une carte avec des cases de différents types.
 * Elle entre pas en jeu dans le fonctionnement du projet juste la version txt
 */
public:
    int dimX; ///< La dimension en X de la carte.
    int dimY; ///< La dimension en Y de la carte.

    /**
     * @brief L'énumération Typecase représente les différents types de cases possibles.
     */
    enum Typecase {
        MUR = '#',   ///< Case de type mur.
        LIBRE = '_'  ///< Case de type libre.
    };

    /**
     * @brief Le tableau de cases représentant la carte.
     *
     * Ce tableau contient les types de cases pour chaque position (x, y) de la carte.
     * La taille du tableau est déterminée par les dimensions de la carte (dimX et dimY).
     */
    Typecase tab[642][425];

    /**
     * @brief Constructeur par défaut de la classe Map.
     */
    Map();

    /**
     * @brief Obtient le type de case à la position (x, y).
     *
     * @param x La coordonnée X de la case.
     * @param y La coordonnée Y de la case.
     * @return Le type de case à la position (x, y).
     */
    Typecase getObjet(int x, int y) const;

    /**
     * @brief Obtient le caractère représentant le type de case à la position (x, y).
     *
     * @param x La coordonnée X de la case.
     * @param y La coordonnée Y de la case.
     * @return Le caractère représentant le type de case à la position (x, y).
     */
    unsigned char getObjetChar(int x, int y) const;
};
inline unsigned char Map::getObjetChar(int x, int y) const {
    assert(x>=0 && x<dimX);
    assert(y>=0 && y<dimY);
    return (char) tab[x][y];
}
inline Map:: Typecase Map::getObjet(int x, int y) const {
    assert(x>=0 && x<dimX);
    assert(y>=0 && y<dimY);
    return tab[x][y];
}

#endif //GALAXY_WAR_MAP_H
