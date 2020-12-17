//Ici on inclu le fichier define.h qui contient notre header
#include "define.h"

//PROGRAMME_PRINCIPAL______________________________________________________________________________________________________________________

int main()
{
        // Déclaration des variables

    int n_pisteur;
    int n_tour = 1;
    int vie_Monstre = VIE_MONSTRE;
    int *pn_pisteur = &n_pisteur;
    coord_Monstre Point_Monstre;





    //Declaration des tableaux

    int Tab_Traces_Monstre[HAUTEUR][LARGEUR];

    int Tab_Traces_Pisteur[HAUTEUR] [LARGEUR];

    coord_Pisteur T_Pisteur[PISTEUR_MAX];

   char T_Affiche_Terrain [HAUTEUR][LARGEUR]=
   {
   {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
   {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
   {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
   {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
   {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
   {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
   {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
   {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
   {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
   {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
   {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
   {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
   {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
   {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
   {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
   {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'}
   };

    //Appel des differentes fonction et procedures
    init_tab_traces(Tab_Traces_Monstre, Tab_Traces_Pisteur);
    Affiche_Titre();
    Affiche_Accueil();
    change_ecran();
    Affiche_Regles();
    change_ecran();
    Affiche_Terrain(T_Affiche_Terrain);
    Affiche_Legende();
    Affiche_nbTour(&n_tour);
    Cb_Pisteurs(&pn_pisteur);
    n_pisteur = &pn_pisteur;
    Placement_pisteur(&pn_pisteur,T_Affiche_Terrain,T_Pisteur, &n_tour);
    Placement_Monstre(T_Affiche_Terrain, Tab_Traces_Monstre, &Point_Monstre);
    //Boucle de Gameplay Principal

        //vie_Monstre = 0; // test ecran de victoire
        //n_pisteur = 0;    // test ecran de defaite


    while (vie_Monstre > 0 && n_pisteur > 0)
    {
        traces_pisteurs(&pn_pisteur, Tab_Traces_Pisteur, T_Pisteur);
        traces_Monstre(Tab_Traces_Monstre, &Point_Monstre, &n_tour);
        change_ecran();
        Rapport_Pisteur(&pn_pisteur, T_Pisteur, Tab_Traces_Monstre, T_Affiche_Terrain,&n_tour, &vie_Monstre);
        Deplace_Pisteur(&pn_pisteur, T_Affiche_Terrain, &n_tour, T_Pisteur);
        Deplace_Monstre(Tab_Traces_Monstre, &Point_Monstre, T_Affiche_Terrain, Tab_Traces_Pisteur);
        n_tour++;
    }

    if (vie_Monstre <= 0)
    {
        ecran_victoire(&n_tour);
    }

    if (n_pisteur <= 0)
    {
        ecran_defaite();
    }





    return 0;
}















