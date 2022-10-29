#ifndef GAME_H
#define GAME_H

void debutPlateau(int plateau[][5]); //initialise le plateau
void correspondanceLettres(void ); //affiche la correspondance des lettres
void affichePlateau(int plateau[][5]); //affiche le plateau
int ajoutBateau(int plateau[][5], int ligne, int colonne, int direction, int taille); //ajoute un bateau sur le plateau
int verfierBateau(int plateau[][5], int ligne, int colonne, int taille, int direction); //verifie si il y a un bateau sur la case
int tire(int plateau[][5], int plateau_adversaire[][5], int ligne, int colonne); //tire sur une case
int finish(int plateau[][5]); //verifie si le jeu est fini

#endif
