//implement the naval battle game
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"
#include "color.h"

#define MAX 100
/*
static void placementBateau(int plateau[][5], int ligne, int colonne, int taille, int direction)
{
    int cmp_taille = 2;
    printf("\nPour placer un bateau, entrez la ligne, la colonne, la direction et la taille du bateau.\n");
    printf("Vous devez placer 3 bateaux, de taille 2, 3 et 4.\n");
    printf("La direction est 0 pour horizontal et 1 pour vertical.\n\n");

    while (cmp_taille <= 4)
    {
        printf("placement du bateau de taille %d\n", cmp_taille);
        printf("Entrez la ligne, la colonne, la direction et la taille du bateau  en les separant par des espace exemple 0 0 1 2: ");
        scanf("%d %d %d %d", &ligne, &colonne, &direction, &taille);
        
        if (verfierBateau(plateau, ligne,colonne) == 0 && taille == cmp_taille) {
                printf("Bateau ajouté avec succès.\n");
                ajoutBateau(plateau, ligne, colonne, direction, taille);
                cmp_taille++;
            } else {
                printf("Erreur lors de l'ajout du bateau.\n");
        }
    }
}*/

static void bullshit(int mon_plateau[][5], int plateau_adversaire[][5])
{
    correspondanceLettres();
        blue();
        printf("Mon plateau de jeu : \n");
        reset();

        affichePlateau(mon_plateau);

        red();
        printf("\nPlateau de l'adversaire : \n");
        reset();

        affichePlateau(plateau_adversaire);
        
        printf("\nPour placer un bateau, entrez la ligne, la colonne, la direction et la taille du bateau.\n");
        printf("Vous devez placer 3 bateaux, de taille 2, 3 et 4.\n");
        printf("La direction est 0 pour horizontal et 1 pour vertical.\n\n");
}
int main()
{
    int mon_plateau[5][5];
    int plateau_adversaire[5][5];
    int cmp_taille = 2;
    int i = 0;

    
    debutPlateau(mon_plateau);
    debutPlateau(plateau_adversaire);

    while (i < 2) 
    {
        int ligne, colonne, direction, taille;

        bullshit(mon_plateau, plateau_adversaire);
        while (cmp_taille <= 4)
        {
            printf("placement du bateau de taille %d\n", cmp_taille);
            printf("Entrez la ligne, la colonne, la direction et la taille du bateau  en les separant par des espace exemple 0 0 1 2: ");
            scanf("%d %d %d %d", &ligne, &colonne, &direction, &taille);
        
            if (verfierBateau(mon_plateau, ligne,colonne, colonne, direction) == 0 && taille == cmp_taille) {
                printf("Bateau ajouté avec succès.\n\n");
                ajoutBateau(mon_plateau, ligne, colonne, direction, taille);
                bullshit(mon_plateau, plateau_adversaire);
                cmp_taille++;
            } else {
                    printf("Erreur lors de l'ajout du bateau.\n\n");
            }
        }
        i++;
    }
/* debutPlateau(plateau_adversaire);
    
    blue();
    printf("Mon plateau de jeu : \n");
    reset();

    affichePlateau(mon_plateau);

    red();
    printf("\nPlateau de l'adversaire : \n");
    reset();

    affichePlateau(plateau_adversaire);
*/

    return 0;
}

