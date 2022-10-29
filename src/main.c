//implement the naval battle game
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"
#include "color.h"

#define MAX 100

int main()
{
    int mon_plateau[5][5];
    int plateau_adversaire[5][5];

    correspondanceLettres();
    debutPlateau(mon_plateau);
    debutPlateau(plateau_adversaire);
    
    blue();
    printf("Mon plateau de jeu : \n");
    reset();

    affichePlateau(mon_plateau);

    red();
    printf("\nPlateau de l'adversaire : \n");
    reset();

    affichePlateau(plateau_adversaire);

    return 0;
}
