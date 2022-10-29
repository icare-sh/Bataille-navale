#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"
#include "color.h"

#define MAX 100

void debutPlateau(int plateau[][5]) //initialise le plateau
{
    int ligne, colonne;
    for (ligne = 0; ligne < 5; ligne++) //  0 1 2 3 4
        for (colonne = 0; colonne < 5; colonne++) // 0 1 2 3 4
            plateau[ligne][colonne] = -1;
}

void correspondanceLettres(void )
{
    blue();
    printf("\n## Correspondance des lettres ##\n\n");
    reset();
    printf(" H -> Espace vide sur le plateau \n");
    printf(" O -> Espace vide pour l'adverssaire \n");
    printf(" X -> Bateau touché \n");
    printf(" B -> Bateau \n");
    printf("\n\n");
}

void affichePlateau(int plateau[][5]) {

    int ligne, colonne;

    violet();
    printf("\t0 \t1 \t2 \t3 \t4"); // 1 2 3 4 5
    reset();
    printf("\n");

    for (ligne = 0; ligne < 5; ligne++) // for l 0 1 2 3 4
    {   
        violet();
        printf("%d", ligne);
        reset();
        for (colonne = 0; colonne < 5; colonne++) {
            if (plateau[ligne][colonne] == -1) {
                green();
                printf("\tH"); // la mer
                reset();
            } else if (plateau[ligne][colonne] == 0) {
                yellow();
                printf("\tO"); // Toucher l'eau
                reset();
            } else if (plateau[ligne][colonne] == 1) {
                red();
                printf("\tB"); // Bateau
                reset();
            } else if (plateau[ligne][colonne] == 2) {
                red();
                printf("\tX"); // X = bateau touché
                reset();
            }

        }
        printf("\n");
    }

}

int ajoutBateau(int plateau[][5], int ligne, int colonne, int direction, int taille) {
    int i;
    if (direction == 0) {
        for (i = 0; i < taille; i++) {
            if (plateau[ligne][colonne + i] == 1 ) {
                return 0;
                printf("Erreur lors de l'ajout du bateau.\n");
            }
        }
        for (i = 0; i < taille; i++) {
            plateau[ligne][colonne + i] = 1;
        }
    } else if (direction == 1) {
        for (i = 0; i < taille; i++) {
            if (plateau[ligne + i][colonne] == 1) {
                return 0;
                printf("Erreur lors de l'ajout du bateau.\n");
            }
        }
        for (i = 0; i < taille; i++) {
            plateau[ligne + i][colonne] = 1;
        }
    }
    return 1;
}

int verfierBateau(int plateau[][5], int ligne, int colonne, int taille, int direction) {
    int i;

    if (direction == 0) {
        for (i = 0; i < taille; i++) {
            if (plateau[ligne][colonne + i] == 1 || plateau[ligne][colonne + i] != -1) {
                return 1; // il y a un bateau ou un bateau touché sur la case
            }
        }
    } else if (direction == 1) {
        for (i = 0; i < taille; i++) {
            if (plateau[ligne + i][colonne] == 1 || plateau[ligne + i][colonne] != -1) {
                return 1; // il y a un bateau ou un bateau touché sur la case
            }
        }
    }
    return 0;
}
