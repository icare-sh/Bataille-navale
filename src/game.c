#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"

#define MAX 100

void debutplateau(int plateau[][5]) //initialise le plateau
{
    int ligne, colonne;
    for (ligne = 0; ligne < 5; ligne++) //  0 1 2 3 4
        for (colonne = 0; colonne < 5; colonne++) // 0 1 2 3 4
            plateau[ligne][colonne] = -1;
}

static void correspondanceLettres(void )
{
    printf("\n## Correspondance des lettres ##\n\n");
    printf(" H -> Espace vide sur ton plateau \n");
    printf(" O -> Espace vide pour l'adverssaire \n");
    printf(" X -> Bateau touché \n");
    printf(" B -> Bateau \n");
    printf("\n\n");
}

void afficheplateau(int plateau[][5]) {

    int ligne, colonne;

    correspondanceLettres();

    printf("\t0 \t1 \t2 \t3 \t4"); // 1 2 3 4 5
    printf("\n");

    for (ligne = 0; ligne < 5; ligne++) // for l 0 1 2 3 4
    {
        printf("%d", ligne);
        for (colonne = 0; colonne < 5; colonne++) {
            if (plateau[ligne][colonne] == -1) {
                printf("\tH");
            } else if (plateau[ligne][colonne] == 0) {
                printf("\tO");
            } else if (plateau[ligne][colonne] == 1) {
                printf("\tX");
            }

        }
        printf("\n");
    }

}
