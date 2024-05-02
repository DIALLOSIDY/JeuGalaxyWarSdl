


#pragma once
#include <SDL.h>
#include <string>
#include <iostream>
#ifdef  __linux__
#include "SDL2/SDL_mixer.h"
#else
#include <SDL_mixer.h>
#endif

/**
 * @class SDLSound
 * @brief s'occupe de la gestion de la musique
 */
class SDLSound {
public:
    /**
     * @brief constructeur de la classe
     * @param frequency la frequence du son
     * @param format le format
     * @param channels lechannel
     * @param chunksize le size
     */
    SDLSound(int frequency, Uint16 format, int channels, int chunksize);

    /**
     * @brief descripteur de la classe
     */
    ~SDLSound();

    /**
     * @brief fonction pour charger un chunk
     * @param pathChunk le chemin vers le fichier a charger
     * @return chunk
     */
    Mix_Chunk* LoadChunkFromFile(const char * pathChunk);

    /**
     * @brief fonction pour charger une musique
     * @param pathMusic le chemin vers le fichier a charger
     * @return Music
     */
    Mix_Music* LoadMusicFromFile(const char * pathMusic);

    /**
     * @brief fonction pour jouer chunk
     * @param chunk chunk a jouer
     */
    void PlayeChunk(Mix_Chunk* chunk);

    /**
     * @brief fonction pour jouer une musique
     * @param music  a jouer
     */
    void PlayeMusic(Mix_Music* music);
};


