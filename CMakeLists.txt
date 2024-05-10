cmake_minimum_required(VERSION 3.22)
project(galaxy-war)

set(CMAKE_CXX_STANDARD 23)


set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/build)



# Définition des chemins de sortie pour les exécutables

set(mainSDL_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# Définition des dossiers sources
set(SRC_CORE_DIR ./src/core)
set(SRC_SDL_DIR ./src/SDL)
set(SRC_TXT_DIR ./src/jeuTxt)

# Définition des fichiers sources pour chaque composant

set(SRC_CORE ${SRC_CORE_DIR}/game.cpp ${SRC_CORE_DIR}/ennemi.cpp ${SRC_CORE_DIR}/avion.cpp
        )
set(HEADER_CORE ${SRC_CORE_DIR}/game.h ${SRC_CORE_DIR}/ennemi.h ${SRC_CORE_DIR}/avion.h ${SRC_CORE_DIR}/balle.h ${SRC_CORE_DIR}/point.h ${SRC_CORE_DIR}/config.h ${SRC_CORE_DIR}/rectangle.h


        )

set(SRC_SDL ${SRC_SDL_DIR}/mainSDL.cpp ${SRC_SDL_DIR}/SDLGame.cpp ${SRC_SDL_DIR}/SDLGame.h
        src/SDL/SDLMusic.h
        src/SDL/SDLMusic.cpp
        src/SDL/SDLTtf.h
        src/SDL/SDLTtf.cpp
        src/SDL/menu.h
        src/SDL/menu.cpp)
set(SRC_TXT ${SRC_TXT_DIR}/mainTxt.cpp ${SRC_TXT_DIR}/jeuTxt.cpp ${SRC_TXT_DIR}/winTxt.h ${SRC_TXT_DIR}/winTxt.cpp
        src/SDL/SDLMusic.h)


# Configuration des librairies SDL2 en fonction du système d'exploitation
if (WIN32)
    set(SDL2_DIR ${PROJECT_SOURCE_DIR}/extern/SDL2_mingw-cb20/SDL2-2.0.12/x86_64-w64-mingw32)
    set(SDL2_INCLUDE_DIR ${SDL2_DIR}/include/SDL2)
    set(SDL2_LIBRARY ${SDL2_DIR}/lib)

    set(SDL2_IMAGE_DIR ${PROJECT_SOURCE_DIR}/extern/SDL2_mingw-cb20/SDL2_image-2.0.5/x86_64-w64-mingw32)
    set(SDL2_IMAGE_INCLUDE_DIR ${SDL2_IMAGE_DIR}/include/SDL2)
    set(SDL2_IMAGE_LIBRARY ${SDL2_IMAGE_DIR}/lib)

    set(SDL2_TTF_DIR ${PROJECT_SOURCE_DIR}/extern/SDL2_mingw-cb20/SDL2_ttf-2.0.15/x86_64-w64-mingw32)
    set(SDL2_TTF_INCLUDE_DIR ${SDL2_TTF_DIR}/include/SDL2)
    set(SDL2_TTF_LIBRARY ${SDL2_TTF_DIR}/lib)

    set(SDL2_MIXER_DIR ${PROJECT_SOURCE_DIR}/extern/SDL2_mingw-cb20/SDL2_mixer-2.0.4/x86_64-w64-mingw32)
    set(SDL2_MIXER_INCLUDE_DIR ${SDL2_MIXER_DIR}/include/SDL2)
    set(SDL2_MIXER_LIBRARY ${SDL2_MIXER_DIR}/lib)
endif (WIN32)

if (UNIX)
    set(SDL2_INCLUDE_DIR /usr/include/SDL2)
    set(SDL2_LIBRARY /usr/lib)

    set(SDL2_IMAGE_INCLUDE_DIR ${SDL2_INCLUDE_DIR})
    set(SDL2_IMAGE_LIBRARY ${SDL2_LIBRARY})

    set(SDL2_TTF_INCLUDE_DIR ${SDL2_INCLUDE_DIR})
    set(SDL2_TTF_LIBRARY ${SDL2_LIBRARY})

    set(SDL2_MIXER_INCLUDE_DIR ${SDL2_INCLUDE_DIR})
    set(SDL2_MIXER_LIBRARY ${SDL2_LIBRARY})
endif (UNIX)


# Définition des exécutables
add_executable(mainSDL ${SRC_CORE} ${HEADER_CORE} ${SRC_SDL} src/SDL/TextureLoader.cpp src/SDL/TextureLoader.h)
#add_executable(JeuTxt  ${SRC_TXT})


#


# Configuration des propriétés des exécutables
set_target_properties(mainSDL PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${mainSDL_OUTPUT_PATH})






# Options de compilation C++
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -ggdb")

# Inclusion des fichiers de compilation

target_include_directories(mainSDL PUBLIC ${SRC_CORE_DIR} ${SRC_SDL_DIR} ${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR} ${SDL2_MIXER_INCLUDE_DIR})


# Liaison des librairies
target_link_directories(mainSDL PUBLIC ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY} ${SDL2_MIXER_LIBRARY})


# Configuration des librairies selon le système d'exploitation
if (WIN32)
    target_link_libraries(mainSDL mingw32 SDL2main SDL2 SDL2_image SDL2_ttf SDL2_mixer)

endif (WIN32)

if (UNIX)
    target_link_libraries(mainSDL SDL2 SDL2_image SDL2_ttf SDL2_mixer GL)

endif (UNIX)

# Copie des fichiers DLL SDL pour Windows
if (WIN32)
    file(COPY ${SDL2_DIR}/bin/SDL2.dll ${SDL2_IMAGE_DIR}/bin/libjpeg-9.dll ${SDL2_IMAGE_DIR}/bin/libpng16-16.dll ${SDL2_IMAGE_DIR}/bin/libtiff-5.dll ${SDL2_IMAGE_DIR}/bin/libwebp-7.dll ${SDL2_IMAGE_DIR}/bin/SDL2_image.dll ${SDL2_IMAGE_DIR}/bin/zlib1.dll ${SDL2_TTF_DIR}/bin/libfreetype-6.dll ${SDL2_TTF_DIR}/bin/SDL2_ttf.dll ${SDL2_MIXER_DIR}/bin/libFLAC-8.dll ${SDL2_MIXER_DIR}/bin/libmodplug-1.dll ${SDL2_MIXER_DIR}/bin/libmpg123-0.dll ${SDL2_MIXER_DIR}/bin/libogg-0.dll ${SDL2_MIXER_DIR}/bin/libopus-0.dll ${SDL2_MIXER_DIR}/bin/libopusfile-0.dll ${SDL2_MIXER_DIR}/bin/libvorbis-0.dll ${SDL2_MIXER_DIR}/bin/libvorbisfile-3.dll ${SDL2_MIXER_DIR}/bin/SDL2_mixer.dll DESTINATION ${CMAKE_BINARY_DIR})
endif (WIN32)




