//implement the naval battle game
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"
#include "color.h"
#include "ordinateur.h"

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

static void bullshit(int mon_plateau[][5], int plateau_adversaire[][5], int plateau_ordinateur_adversaire[][5])
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
        
        yellow();
        printf("\nPlateau de l'advairesaire de l'ordinateur : \n");
        reset();

        affichePlateau(plateau_ordinateur_adversaire);

        printf("\nPour placer un bateau, entrez la ligne, la colonne, la direction et la taille du bateau.\n");
        printf("Vous devez placer 3 bateaux, de taille 2, 3 et 4.\n");
        printf("La direction est 0 pour horizontal et 1 pour vertical.\n\n");
}

int main()
{
    int mon_plateau[5][5];
    int plateau_adversaire[5][5];
    int plateau_ordinateur[5][5];
    int plateau_ordinateur_adversaire[5][5];
    int cmp_taille = 2;

    
    debutPlateau(mon_plateau);
    debutPlateau(plateau_adversaire);

    debutPlateau(plateau_ordinateur);
    debutPlateau(plateau_ordinateur_adversaire);
    bateauOrdi(plateau_ordinateur);

    affichePlateau(plateau_ordinateur);
    while (1) 
    {
        int ligne, colonne, direction, taille;

        bullshit(mon_plateau, plateau_adversaire, plateau_ordinateur_adversaire);
        while (cmp_taille <= 4)
        {
            printf("placement du bateau de taille %d\n", cmp_taille);
            printf("Entrez la ligne, la colonne, la direction et la taille du bateau  en les separant par des espace exemple 0 0 1 2: ");
            scanf("%d %d %d %d", &ligne, &colonne, &direction, &taille);
        
            if (verfierBateau(mon_plateau, ligne,colonne, taille, direction) == 0 && taille == cmp_taille) {
                printf("Bateau ajouté avec succès.\n\n");
                ajoutBateau(mon_plateau, ligne, colonne, direction, taille);
                bullshit(mon_plateau, plateau_adversaire, plateau_ordinateur_adversaire);
                cmp_taille++;
            } else {
                    red();
                    printf("\nErreur lors de l'ajout du bateau.\n\n");
                    reset();
            }
        }
        
        printf("Entrez la ligne et la colonne de la case que vous voulez tirer : ");
        scanf("%d %d", &ligne, &colonne);
        if (tire(plateau_ordinateur, plateau_adversaire, ligne, colonne) == 1) {
            printf("Vous avez touché un bateau.\n");
        } else {        
            printf("Vous avez raté. Au tour de l'ordinateur\n");
            if (tire_ordinateur(mon_plateau, plateau_ordinateur_adversaire, mon_plateau) == 1) {
                while(tire_ordinateur(mon_plateau, plateau_ordinateur_adversaire, mon_plateau) == 1)
                {
                    red();
                    printf("\n> L'ordinateur a touché un de vos bateaux.\n");
                    reset();
                }
            } else {
                blue();
                printf("\n> L'ordinateur a raté.\n");
                reset();
            }
        }

        bullshit(mon_plateau, plateau_adversaire, plateau_ordinateur_adversaire);
        if (finish(plateau_ordinateur_adversaire) == 1) {
            red();
            printf("\n\nVous avez perdu.\n");
            reset();
            break;
        } else if (finish(plateau_adversaire) == 1) {
            blue();
            printf("\n\nVous avez gagné.\n");
            reset();
            break;
        }
    }
    return 0;
}
