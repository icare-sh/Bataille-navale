//implement the naval battle game
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"
#include "color.h"
#include "ordinateur.h"


static void affiche(int mon_plateau[][5], int plateau_adversaire[][5], int plateau_ordinateur_adversaire[][5])
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
        
        printf("\n/**********************************************************************/\n");
        printf("- Pour placer un bateau, entrez la ligne, la colonne, la direction et la taille du bateau.\n");
        printf("- Vous devez placer 3 bateaux, de taille 2, 3 et 4.\n");
        printf("- La direction est 0 pour horizontal et 1 pour vertical.\n");
        printf("/**********************************************************************/\n\n");
}

int main()
{
    int mon_plateau[5][5]; //mon plateau de jeu
    int plateau_adversaire[5][5]; //plateau ardoise de l'adversaire
    int plateau_ordinateur[5][5]; //plateau de l'ordinateur
    int plateau_ordinateur_adversaire[5][5]; //plateau ardoise de l'ordinateur
    int cmp_taille = 2;

    // Creation des plateaux du joueur et de l'ordinateur
    debutPlateau(mon_plateau);
    debutPlateau(plateau_adversaire);

    debutPlateau(plateau_ordinateur);
    debutPlateau(plateau_ordinateur_adversaire);

    bateauOrdi(plateau_ordinateur);

    //affichePlateau(plateau_ordinateur); //affiche le plateau de l'ordinateur
    while (1) 
    {
        int ligne, colonne, direction, taille;

        affiche(mon_plateau, plateau_adversaire, plateau_ordinateur_adversaire);
        // placement des bateaux
        while (cmp_taille <= 4)
        {   
            yellow();
            printf("placement du bateau de taille %d\n\n", cmp_taille);
            reset();
            printf("Entrez la ligne, la colonne, la direction et la taille du bateau  en les separant par des espace exemple 0 0 1 2: ");
            scanf("%d %d %d %d", &ligne, &colonne, &direction, &taille);
        
            if (verfierBateau(mon_plateau, ligne,colonne, taille, direction) == 0 && taille == cmp_taille) {
                yellow();
                printf("\nBateau ajouté avec succès.\n\n");
                reset();
                ajoutBateau(mon_plateau, ligne, colonne, direction, taille);
                affiche(mon_plateau, plateau_adversaire, plateau_ordinateur_adversaire);
                cmp_taille++;
            } else {
                    red();
                    printf("\nErreur lors de l'ajout du bateau.\n\n");
                    reset();
            }
        }
        blue();
        printf("|------------------------------------------------------------>\n");
        reset();
        cyan();
        printf("Entrez la ligne et la colonne de la case que vous voulez tirer : ");
        reset();
        scanf("%d %d", &ligne, &colonne);
        if (tire(plateau_ordinateur, plateau_adversaire, ligne, colonne) == 1) {
            blue();
            printf("Vous avez touché un bateau.\n");
            reset();
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

        affiche(mon_plateau, plateau_adversaire, plateau_ordinateur_adversaire);
        if (finish(plateau_ordinateur_adversaire) == 1) {
            red();
            printf("\n\nVous avez perdu.\n");
            reset();
            break;
        } else if (finish(plateau_adversaire) == 1) {
            blue();
            printf("\n\nVous avez gagné !!!!\n");
            reset();
            break;
        }
    }
    return 0;
}
