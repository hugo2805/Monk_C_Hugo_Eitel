#ifndef DEFINE_H_INCLUDED
#define DEFINE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>



// ON_DEFINIE_LES_PRIMITIVES______________________________________________________________________________________________________________

#define PISTEUR_MAX 10
#define VIE_MONSTRE 4
#define LARGEUR 31
#define HAUTEUR 16
#define RMAX_X 29
#define RMAX_Y 14
#define RMAX_DIR 4
#define RANGE_MONSTRE 1



// DECLARATION_DE_TYPE_STRUCTURE____________________________________________________________________________________________________________
    typedef struct coord_Pisteur{
        int x;
        int y;
    } coord_Pisteur;

    typedef struct coord_Monstre{
        int x;
        int y;
    } coord_Monstre;

//PROTOTYPES_______________________________________________________________________________________________________________________________

extern void init_tab_traces(int tab_monstre[HAUTEUR][LARGEUR], int tab_pisteur[HAUTEUR][LARGEUR]);
extern void color(int t,int f);
extern void Affiche_Titre();
extern void Affiche_Accueil();
extern void Affiche_Regles();
extern void change_ecran();
extern void Affiche_Terrain(char Terrain[HAUTEUR][LARGEUR]);
extern void Affiche_nbTour(int *pn_Tour);
extern void Affiche_Legende();
extern void Cb_pisteur(int *pn_pisteur);
extern void Placement_pisteur(int *pn_pisteur,char Terrain[HAUTEUR][LARGEUR],struct coord_Pisteur T_Pisteur[PISTEUR_MAX], int *pn_Tour);
extern void Placement_Monstre(char Terrain[HAUTEUR][LARGEUR], int Tab_Monstre[HAUTEUR][LARGEUR],coord_Monstre *Point_Monstre);
extern void traces_pisteurs(int *pn_pisteurs, int T_Traces_Pist[HAUTEUR][LARGEUR],struct coord_Pisteur T_Pisteur[PISTEUR_MAX]);
extern void traces_Monstre(int Tab_Monstre[HAUTEUR][LARGEUR],coord_Monstre *Point_Monstre, int *pn_Tour);
extern void Rapport_Pisteur(int *pn_pisteurs, struct coord_Pisteur T_Pisteur[PISTEUR_MAX], int Tab_Monstre[HAUTEUR][LARGEUR], char Terrain[HAUTEUR][LARGEUR], int *pn_Tour, int *vie_Monstre);
extern int Tir();
extern void Deplace_Pisteur(int *pn_pisteurs, char Terrain[HAUTEUR][LARGEUR], int *pn_Tour, struct coord_Pisteur T_Pisteur[PISTEUR_MAX]);
extern void Deplace_Monstre( int Tab_Monstre[HAUTEUR][LARGEUR],coord_Monstre *Point_Monstre,  char Terrain[HAUTEUR][LARGEUR],int T_Traces_Pist[HAUTEUR][LARGEUR]);
extern void ecran_victoire(&n_tour);
extern void ecran_defaite();




#endif // DEFINE_H_INCLUDED
