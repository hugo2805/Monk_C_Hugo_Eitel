#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// On définie les primitives______________________________________________________________________________________________________________

#define PISTEUR_MAX 10
#define VIE_MONSTRE 4
#define LARGEUR 29
#define HAUTEUR 14

//Prototypes_______________________________________________________________________________________________________________________________
/*
color(int, int);
Affiche_Titre();
Affiche_Accueil();
Affiche_Regles();
change_ecran();
Affiche_Terrain();
*/



//Programme_Principal______________________________________________________________________________________________________________________

int main()
{
    //Declaration des tableaux
   char T_Affiche_Terrain [16][31]=
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
    // Déclaration des variables
    int n_i, n_j;

    //Appel des differentes fonction et procedures
    Affiche_Titre();
    Affiche_Accueil();
    change_ecran();
    Affiche_Regles();
    change_ecran();
    Affiche_Terrain(T_Affiche_Terrain);




    return 0;
}

//Procedures____________________________________________________________________________________________________________________________________

//Procedure pour générer la couleur d'affichage du texte
void color(int t,int f)
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(H,f*16+t);
}

//Procedure d'affichage du titre en rouge
void Affiche_Titre()
{

    color(12,0);
    printf("MMMMMMMM               MMMMMMMM     OOOOOOOOO     NNNNNNNN        NNNNNNNNKKKKKKKKK    KKKKKKK             CCCCCCCCCCCCC");
    printf("M:::::::M             M:::::::M   OO:::::::::OO   N:::::::N       N::::::NK:::::::K    K:::::K          CCC::::::::::::C");
    printf("M::::::::M           M::::::::M OO:::::::::::::OO N::::::::N      N::::::NK:::::::K    K:::::K        CC:::::::::::::::C");
    printf("M:::::::::M         M:::::::::MO:::::::OOO:::::::ON:::::::::N     N::::::NK:::::::K   K::::::K       C:::::CCCCCCCC::::C");
    printf("M::::::::::M       M::::::::::MO::::::O   O::::::ON::::::::::N    N::::::NKK::::::K  K:::::KKK      C:::::C       CCCCCC");
    printf("M:::::::::::M     M:::::::::::MO:::::O     O:::::ON:::::::::::N   N::::::N  K:::::K K:::::K        C:::::C              ");
    printf("M:::::::M::::M   M::::M:::::::MO:::::O     O:::::ON:::::::N::::N  N::::::N  K::::::K:::::K         C:::::C              ");
    printf("M::::::M M::::M M::::M M::::::MO:::::O     O:::::ON::::::N N::::N N::::::N  K:::::::::::K          C:::::C              ");
    printf("M::::::M  M::::M::::M  M::::::MO:::::O     O:::::ON::::::N  N::::N:::::::N  K:::::::::::K          C:::::C              ");
    printf("M::::::M   M:::::::M   M::::::MO:::::O     O:::::ON::::::N   N:::::::::::N  K::::::K:::::K         C:::::C              ");
    printf("M::::::M    M:::::M    M::::::MO:::::O     O:::::ON::::::N    N::::::::::N  K:::::K K:::::K        C:::::C              ");
    printf("M::::::M     MMMMM     M::::::MO::::::O   O::::::ON::::::N     N:::::::::NKK::::::K  K:::::KKK      C:::::C       CCCCCC");
    printf("M::::::M               M::::::MO:::::::OOO:::::::ON::::::N      N::::::::NK:::::::K   K::::::K       C:::::CCCCCCCC::::C");
    printf("M::::::M               M::::::M OO:::::::::::::OO N::::::N       N:::::::NK:::::::K    K:::::K        CC:::::::::::::::C");
    printf("M::::::M               M::::::M   OO:::::::::OO   N::::::N        N::::::NK:::::::K    K:::::K          CCC::::::::::::C");
    printf("MMMMMMMM               MMMMMMMM     OOOOOOOOO     NNNNNNNN         NNNNNNNKKKKKKKKK    KKKKKKK             CCCCCCCCCCCCC");
    color(15,0);

}

//Procedure d'affichage du texte d'accueil
void Affiche_Accueil()
{
    printf("\n\n");
    printf("************************************************************************************************************************");
    printf("Bienvenu dans cette version de MONK C en C !\n");
    printf("Ce programme a ete realise par Hugo Eitel,\n");
    printf("Dans le cadre de l'epreuve D12 de l'examen de Cycle I de 2020-2021.\n");
    printf("************************************************************************************************************************\n");

}

//Procedure d'affichage des regles du jeu
void Affiche_Regles()
{
    color(14,0);
    printf("***************************************************REGLES_DU_JEU********************************************************\n\n");
    printf("Au debut de la partie, vous allez devoir decider combien de pisteur vous souhaitez pour cette partie.\n");
    printf("Le nombre maximum de pisteur autorise est 10. Notez que les meilleurs, ne jouent qu'avec un seul pisteur.\n");
    printf("Avant de debuter le jeu vous choisirez la position de base de chacun de vos pisteurs.\n");
    printf("A chaque tour vos pisteurs, vous informent si il y a des traces du monstre ou le monstre lui meme.\n");
    printf("Dans le cas ou ils detectent des traces, ils vous informeront de la fraicheur de celles-ci,\n");
    printf("La fraicheur des traces est determinee par une valeur entre 2 et 15, plus la valeur est elevee, plus elles sont fraiche.");
    printf("Si votre pisteur vous informe qu'il voit le monstre, vous aurez la possibilite de tirer. Votre tir sera soumit a un\n");
    printf("lancement de des, vous offrant un taux de 40 pourcent de reussite de celui-ci.\n");
    printf("Une fois que tous vos pisteurs vous ont informes, vous pouvez les deplacer dans un rayon de 4 cases sur les axes X ou Y,");
    printf("autour de leur position actuelle. Une fois que vous aurez deplace tous vos pisteurs, c'est le monstre qui se deplacera,\n");
    printf("dans un rayon d'une case sur l'axe X ou Y. Le monstre dispose de 4 vie.\n");
    printf("La partie se termine si vous n'avez plus de pisteur ou que vous avez tue le monstre.\n\n");
    printf("                                            BONNE CHANCE AVENTURIER !!!\n");
    printf("\n");
    printf("************************************************************************************************************************\n\n");
    color(15,0);

}

//Procedure pour effacer l'ecran et afficher la suite
void change_ecran()
{
    color(1,0);
    printf("Appuyez sur Entree pour passer a la suite...\n");
    getchar();
    system("cls");
    color(15,0);
}

//Procedure pour afficher le terrain
void Affiche_Terrain(char Terrain[16][31])
{
    int n_i, n_j;

    printf("******************************************************-TERRAIN-*********************************************************\n\n");


    for(n_i=0;n_i<16;n_i++){//ligne
    for(n_j=0;n_j<31;n_j++){//col
            if (Terrain[n_i][n_j] == '*')
                {
                  color(0,6);
                  printf("[%c]",Terrain[n_i][n_j]);
                  color(15,0);
                }
                else
                {
                 color(0,8);
                 printf("[%c]",Terrain[n_i][n_j]);
                 color(15,0);
                }

    }
    printf("\n");

    }
}





