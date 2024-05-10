DESCRIPTION :SDLGalaxy
 
SDLGalaxy est un jeu d'action et de tir spatial palpitant 
où les joueurs prennent le contrôle d'un vaisseau spatial dans
une lutte épique contre les forces ennemies dans la galaxie. 
Le destin de l'univers repose entre vos mains alors que vous affrontez 
des vagues incessantes d'ennemis.

    Déplacer l'avion avec les touches directionnelles.
    Tirer avec la touche "x".
    Survivre dans une vague d'ennemis générée automatiquement.

Compilation
Linux

//README LINUX


Assurez-vous d'avoir au minimum la version 3.22 de CMake. Si vous ne l'avez pas, vous pouvez l'installer avec les commandes suivantes :

sudo apt-get update
sudo apt-get install cmake

Assurez-vous également d'installer les bibliothèques SDL nécessaires. Vous pouvez les installer avec la commande suivante :

sudo apt-get update -y
sudo apt-get install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev libpng-dev libglew-dev codeblocks doxygen valgrind build-essential manpages-dev imagemagick

Une fois ces outils installés, placez-vous à la racine du projet et exécutez les instructions suivantes :

mkdir build
cd build
cmake ..
make
cd ../bin
./mainSDL

Normalement, une fenêtre SDL devrait apparaître avec un petit menu vous permettant de commencer en appuyant sur "Play" ou de fermer la fenêtre avec "Quit".

Pendant le jeu, sous Linux, vous pouvez fermer la fenêtre en appuyant sur la touche "c".

//FIN LINUX


//WINDOWS

DOCUMEBTATION :

 la documentation complete du code est disponible dans le dossier doc du projet


INSTALLATION :

Avant de commencer les biblotheques suivantes sont indispensbles

SDL2       :techargeable a partir du lien https://www.libsdl.org/
SDL2_image :techargeable a partir du lien https://github.com/libsdl-org/SDL_image
SDL2_ttf : techargeable a partir du lien https://github.com/libsdl-org/SDL_ttf
SDL2_mixer : techargeable a partir du lien https://github.com/libsdl-org/SDL_mixer

CONFIGURATION WINDOWS

Pour les utilisateurs de Windows, suivez ces étapes :
Téléchargez et installez les librairies SDL2, SDL2_image, SDL2_ttf et SDL2_mixer depuis les liens fournis ci-dessus.
Ouvrez le fichier CMakeLists.txt et modifiez les chemins de destination dans la clause if(WIN32) en fonction de l'emplacement où vous avez installé les librairies SDL2.

OBJECTIF DU JEU :
Dans SDLGalaxy, votre mission est d'eliminer le plus grand nombre d'ennemi tout en evitant 
de se faire tuer


COMMENT JOUER /

Clonez ce dépôt sur votre machine.
Configurez les librairies SDL2 selon votre système d'exploitation en suivant les instructions ci-dessus.
Utilisez CMake pour générer les fichiers de construction.
Compilez le jeu en exécutant la commande make.
Lancez le jeu en exécutant l'application générée.
Le botton play du menu permet de lancer le jeu
Les touches directionnelles pour se deplacer 
La touche 'x' pour tirer des balles 
La touche 'c' pour quitter le jeu 

//FIN WINDOWS

AUTEUR :
Ce jeu a été développé par DIALLO SIDY 


REJOIGNEZ LA BATAILLE :

Préparez-vous à une aventure intergalactique passionnante avec Galaxy War. 
Téléchargez dès maintenant et embarquez pour un voyage au cœur de l'espace infini,où 
seuls les plus courageux pourront triompher !
