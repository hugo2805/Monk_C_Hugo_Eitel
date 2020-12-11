#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

// On définie les primitives______________________________________________________________________________________________________________

#define PISTEUR_MAX 10
#define VIE_MONSTRE 4
#define LARGEUR 31
#define HAUTEUR 16
#define RMAX_X 29
#define RMAX_Y 14

//Prototypes_______________________________________________________________________________________________________________________________

void color(int, int);
void Affiche_Titre();
void Affiche_Accueil();
void Affiche_Regles();
void change_ecran();
void Affiche_Terrain();
void Affiche_Legende();
void Cb_pisteur();
void Placement_pisteur();
void Placement_Monstre();




// Décalration Types structure____________________________________________________________________________________________________________
    typedef struct coord_Pisteur{
        int x;
        int y;
    } coord_Pisteur;

        typedef struct coord_Monstre{
        int x;
        int y;
    } coord_Monstre;

//Programme_Principal______________________________________________________________________________________________________________________

int main()
{
        // Déclaration des variables
    int n_i, n_j;
    int n_pisteur;
    int *pn_pisteur = &n_pisteur;




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
    Affiche_Titre();
    Affiche_Accueil();
    change_ecran();
    Affiche_Regles();
    change_ecran();
    Affiche_Terrain(T_Affiche_Terrain);
    Affiche_Legende();
    Cb_Pisteurs(&pn_pisteur);
    Placement_pisteur(&pn_pisteur,T_Affiche_Terrain,T_Pisteur);
    Placement_Monstre(T_Affiche_Terrain, Tab_Traces_Monstre);





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
void Affiche_Terrain(char Terrain[HAUTEUR][LARGEUR])
{
    int n_i, n_j;

    printf("******************************************************-TERRAIN-*********************************************************\n\n");


    for(n_i=0;n_i<HAUTEUR;n_i++){//ligne
    for(n_j=0;n_j<LARGEUR;n_j++){//col
            if (Terrain[n_i][n_j] == '*')
                {
                  color(0,6);
                  printf("[%c]",Terrain[n_i][n_j]);
                  color(15,0);
                }
                if (Terrain[n_i][n_j] == 'P')
                {
                  color(10,8);
                  printf("[%c]",Terrain[n_i][n_j]);
                  color(15,0);
                }
                if (Terrain[n_i][n_j] == '?')
                {
                  color(14,8);
                  printf("[%c]",Terrain[n_i][n_j]);
                  color(15,0);
                }
                if (Terrain[n_i][n_j] == '!')
                {
                  color(4,8);
                  printf("[%c]",Terrain[n_i][n_j]);
                  color(15,0);
                }
                if (Terrain[n_i][n_j] == 'X')
                {
                  color(5,8);
                  printf("[%c]",Terrain[n_i][n_j]);
                  color(15,0);
                }
                if (Terrain[n_i][n_j] == ' ')
                {
                 color(0,8);
                 printf("[%c]",Terrain[n_i][n_j]);
                 color(15,0);
                }

    }
    printf("\n");

    }
}

//Procedure pour afficher la legende
void Affiche_Legende()
{
    printf("******************************************************-LEGENDE-*********************************************************\n\n");
    color(10,8);
    printf("[P]");
    color(15,0);
    printf(": Vos pisteurs");
    printf("\t");

    color(4,8);
    printf("[!]");
    color(15,0);
    printf(": Le pisteur qui fait son rapport");
    printf("\t");

    color(14,8);
    printf("[?]");
    color(15,0);
    printf(": Le pisteur qui attend un ordre de deplacement\n");
    printf("\t\t   ");

    color(5,8);
    printf("[X]");
    color(15,0);
    printf(": Dernier endroit ou le monstre a ete vu apres avoir ete touche\n\n");

    printf("************************************************************************************************************************\n\n");

}

//Procedure qui demande et recupere le nombre de pisteur demande par l'utilisateur
void Cb_Pisteurs(int *pn_pisteur)
{
    int nb_pist;
    printf("Combien souhaitez vous de pisteurs ?\n");
    scanf("%d", &nb_pist);

    if (nb_pist<=PISTEUR_MAX)
        {
           *pn_pisteur = nb_pist;
        }
    else
        {
        printf("Combien souhaitez vous de pisteurs ?\n");
        scanf("%d", &nb_pist);
        }



}

//Procedure qui place les pisteurs a la position demndé par le joueur
void Placement_pisteur(int *pn_pisteur,char Terrain[HAUTEUR][LARGEUR], struct coord_Pisteur T_Pisteur[PISTEUR_MAX])
{
    int i;
    int axe_X;
    int axe_y;

    for (i=1;i<=*pn_pisteur;i++)
    {
        printf("Entrez le point sur l'axe X du pisteur %d (Compris entre 1 et 29): \n", i);
        scanf("%d",&axe_X);

        printf("Entrez le point sur l'axe Y du pisteur %d (Compris entre 1 et 14): \n", i);
        scanf("%d",&axe_y);

        Terrain[axe_y][axe_X]='P';

        T_Pisteur[i].x = axe_X;
        T_Pisteur[i].y = axe_y;

        system("cls");
        Affiche_Terrain(Terrain);
        Affiche_Legende();

    }
}

//Procedure qui genere la position de depart du monstre tout en s'assurant qu'il ne soit pas sur ou dans le voisinage d'un pisteur
void Placement_Monstre(char Terrain[HAUTEUR][LARGEUR], int Tab_Monstre[HAUTEUR][LARGEUR])
{
    int Monstre_x, Monstre_y;
    int i, j, k, l, count;
    int Cg_X, Cg_Y, Cd_X, Cd_Y;

    srand(time(NULL));
    Monstre_x= (rand()%(RMAX_X)+1);
    Monstre_y= (rand()%(RMAX_Y)+1);
    i = Monstre_y;
    j = Monstre_x;

    while (count > 0)
    {
        if (Terrain[i][j]== ' ')
        {

             if (i-1<0){Cg_Y = 0;} else {Cg_Y = i-1;}
             if (i+1>=HAUTEUR){Cd_Y = HAUTEUR-1;} else {Cd_Y = i+1;}
             if (j-1<0){Cg_X = 0;} else {Cg_X = j-1;}
             if (j+1>=LARGEUR){Cd_X = LARGEUR-1;} else {Cd_X = j+1;}

             //Ces Instructions permettent de vérifier que je lis bien les 8 cases autour de ma position aleatoire

             /*printf("i = %d, j = %d",i , j);  //ici on affiche le point centrale donc la potentielle position du monstre
             printf("\n");
             printf("Cg_X = %d, Cg_Y = %d" ,Cg_X, Cg_Y);  // ici on affiche la position de la case en haut a gauche de notre voisinage donc la numero 1
            printf("\n");
             printf("Cd_X = %d, Cd_Y = %d" ,Cd_X, Cd_Y);  // ici on affiche la position de la case en bas a droite de notre voisinage donc la numero 9
             printf("\n\n");*/

             count =0;
             for (k=Cg_Y;k<=Cd_Y;k++)
                {
                    for (l=Cg_X;l<=Cd_X;l++)
                    {

                        if (Terrain[k][l]== 'P')
                        {
                        count++;
                        }


                    }


                }
        }


    }

    coord_Monstre.x = j;
    coord_Monstre.y= i;
    Tab_Monstre[i][j] = 15;
}










