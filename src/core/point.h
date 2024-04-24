#pragma once


/**
 * @brief La structure Point représente un point dans un espace 2D.
 */
    struct Point {
        float posX; ///< La coordonnée X du point.
        float posY; ///< La coordonnée Y du point.
        int items ;//propre ppour le menu du jeu

        /**
         * @brief Constructeur par défaut de la structure Point.
         *
         * Initialise les coordonnées X et Y à 150.
         */
        Point() : posX(150), posY(150) {}

        /**
         * @brief Constructeur de la structure Point.
         *
         * @param x La coordonnée X du point.
         * @param y La coordonnée Y du point.
         */
        Point(float x, float y) : posX(x), posY(y) {}

        /**
         * @brief Obtient la coordonnée X du point.
         *
         * @return La coordonnée X du point.
         */
        float getPosX() {
            return posX;
        }

        /**
         * @brief Obtient la coordonnée Y du point.
         *
         * @return La coordonnée Y du point.
         */
        float getPosY() {
            return posY;
        }

        /**
         * @brief Définit la coordonnée X du point.
         *
         * @param x La nouvelle coordonnée X du point.
         */
        void setX(float x) {
            posX = x;
        }

        /**
         * @brief Définit la coordonnée Y du point.
         *
         * @param y La nouvelle coordonnée Y du point.
         */
        void setY(float y) {
            posY = y;
        }

    };