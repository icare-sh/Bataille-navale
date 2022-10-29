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
    printf(" H -> Espace vide sur ton plateau \n");
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
                printf("\tH");
                reset();
            } else if (plateau[ligne][colonne] == 0) {
                yellow();
                printf("\tO");
                reset();
            } else if (plateau[ligne][colonne] == 1) {
                red();
                printf("\tX");
                reset();
            }

        }
        printf("\n");
    }

}
