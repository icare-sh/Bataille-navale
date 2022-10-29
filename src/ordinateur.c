#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "ordinateur.h"
#include "color.h"
#include "game.h"


void bateauOrdi(int plateau[][5]) //initialise le plateau
{
    int ligne, colonne;
    int cmp_taille = 2;
    int direction;
    srand(time(NULL));

    while(cmp_taille <= 4)
    {
        ligne = rand() % 5;
        colonne = rand() % 5;
        direction = rand() % 2;
       
        if (verfierBateau(plateau, ligne,colonne, cmp_taille, direction) == 0) {
            ajoutBateau(plateau, ligne, colonne, direction, cmp_taille);
            cmp_taille++;
        }
    }
}

int tire_ordinateur(int plateau[][5], int plateau_adversaire[][5], int mon_plateau[][5]) {
    int ligne, colonne;
    srand(time(NULL));
    while (1) {
        ligne = rand() % 5;
        colonne = rand() % 5;
        if (plateau_adversaire[ligne][colonne] == 1 || plateau_adversaire[ligne][colonne] == -1) {
            break;
        }
    }
    if (plateau[ligne][colonne] == 1) {
        plateau_adversaire[ligne][colonne] = 2;
        mon_plateau[ligne][colonne] = 2;
        return 1; // touché
    } else if (plateau[ligne][colonne] == 0) {
        return 2; // déjà touché
    } else {
        plateau_adversaire[ligne][colonne] = 0;
        return 0; // raté
    }
}
