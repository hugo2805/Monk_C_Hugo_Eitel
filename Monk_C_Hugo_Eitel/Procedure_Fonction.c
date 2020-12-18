#include "define.h"

//PROCEDURES____________________________________________________________________________________________________________________________________

//Procedure pour générer la couleur d'affichage du texte
void color(int t,int f)
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,f*16+t);
}

//Procedure qui initialise toutes les valeurs des tableaux de traces a 0
void init_tab_traces(int tab_monstre[HAUTEUR][LARGEUR], int tab_pisteur[HAUTEUR][LARGEUR])
{
    int i, j;

    for (i=0; i<HAUTEUR; i++){
        for(j=0;j<LARGEUR;j++){
            tab_monstre[i][j]= 0;
            tab_pisteur[i][j]= 0;
        }
    }
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
    printf("Bienvenue dans cette version de MONK C en C !\n");
    printf("Ce programme a ete realise par Hugo Eitel,\n");
    printf("Dans le cadre de l'epreuve D12 de l'examen de Cycle I de 2020-2021.\n");
    printf("************************************************************************************************************************\n");

}

//Procedure d'affichage des regles du jeu
void Affiche_Regles()
{
    color(14,0);
    printf("***************************************************REGLES_DU_JEU********************************************************\n\n");
    printf("Au debut de la partie, vous allez devoir decider combien de pisteurs vous souhaitez pour cette partie.\n");
    printf("Le nombre maximum de pisteurs autorise est 10. Notez que les meilleurs, ne jouent qu'avec un seul pisteur.\n");
    printf("Avant de debuter le jeu vous choisirez la position de base de chacun de vos pisteurs.\n");
    printf("A chaque tour vos pisteurs, vous informent si il y a des traces du monstre ou le monstre lui meme.\n");
    printf("Dans le cas ou ils detectent des traces, ils vous informeront de la fraicheur de celles-ci,\n");
    printf("La fraicheur des traces est determinee par une valeur entre 2 et 15, plus la valeur est elevee, plus elles sont fraiches.");
    printf("Si votre pisteur vous informe qu'il voit le monstre, vous aurez la possibilite de tirer. Votre tir sera soumit a un\n");
    printf("lancement de des, vous offrant un taux de 40 pourcent de reussite de celui-ci.\n");
    printf("Une fois que tous vos pisteurs vous ont informes, vous pouvez les deplacer dans un rayon de 4 cases sur les axes X ou Y,");
    printf("autour de leur position actuelle. Une fois que vous aurez deplace tous vos pisteurs, c'est le monstre qui se deplacera,\n");
    printf("dans un rayon d'une case sur l'axe X ou Y. Le monstre dispose de 4 vies.\n");
    printf("La partie se termine si vous n'avez plus de pisteur ou que vous avez tue le monstre.\n\n");
    printf("                                            BONNE CHANCE AVENTURIER !!!\n");
    printf("\n");
    printf("************************************************************************************************************************\n\n");
    color(15,0);

}

//Procedure pour effacer l'ecran et afficher la suite
void change_ecran()
{
    fflush(stdin);
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
                switch (Terrain[n_i][n_j])
                {
                case '*':
                    color(0,6);
                    break;
                case 'P':
                    color(10,8);
                    break;
                case '?':
                    color(14,8);
                    break;
                case '!':
                    color(4,8);
                    break;
                case 'X':
                    color(5,8);
                    break;
                case ' ':
                    color(0,8);
                    break;
              /*  case 'M':
                    color(4,8);
                    break;*/

                }
        printf("[%c]",Terrain[n_i][n_j]);
        color(15,0);

        }
    printf("\n");

    }
}

void Affiche_nbTour(int *pn_Tour)
{
     color(6,0);
     printf("================================================-VOUS_ETES_AU_TOUR_%d-==================================================\n\n",*pn_Tour );
     color(15,0);
}

//Procedure pour afficher la legende
void Affiche_Legende()
{
    printf("*****************************************************-LEGENDE-**********************************************************\n\n");
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

    printf("\tPour les deplacements des pisteurs, les directions correspondent a des chiffres entre 1 et 4 :\n");
    printf("\t\t\t 1 = HAUT\t 2 = DROITE\t 3 = BAS\t 4 = GAUCHE\n");

    printf("************************************************************************************************************************\n\n");

}

//Procedure qui demande et recupere le nombre de pisteur demande par l'utilisateur
void Cb_Pisteurs(int *pn_pisteur)
{
    int nb_pist=0;


    while (nb_pist<=0 || nb_pist>PISTEUR_MAX)
        {
        printf("Combien souhaitez vous de pisteurs (Entre 1 et 10) ?\n");
        scanf("%d", &nb_pist);
        fflush(stdin);
        //printf("%d",nb_pist);
        *pn_pisteur = nb_pist;

        }


}

//Procedure qui place les pisteurs a la position demndé par le joueur
void Placement_pisteur(int *pn_pisteur,char Terrain[HAUTEUR][LARGEUR], struct coord_Pisteur T_Pisteur[PISTEUR_MAX], int *pn_Tour)
{
    int i;
    int axe_X;
    int axe_y;

    for (i=1;i<=*pn_pisteur;i++)
    {
        axe_X = 0;
        axe_y = 0;

        while (axe_X<1 || axe_X > 29)
        {
        printf("Entrez le point sur l'axe X du pisteur %d (Compris entre 1 et 29): \n", i);
        scanf("%d",&axe_X);
        fflush(stdin);
        }

        while (axe_y<1 || axe_y > 14)
        {
        printf("Entrez le point sur l'axe Y du pisteur %d (Compris entre 1 et 14): \n", i);
        scanf("%d",&axe_y);
        fflush(stdin);

        }

        Terrain[axe_y][axe_X]='P';

        T_Pisteur[i].x = axe_X;
        T_Pisteur[i].y = axe_y;

        system("cls");
        Affiche_Terrain(Terrain);
        Affiche_Legende();
        Affiche_nbTour(pn_Tour);

    }
}

//Procedure qui genere la position de depart du monstre tout en s'assurant qu'il ne soit pas sur ou dans le voisinage d'un pisteur
void Placement_Monstre(char Terrain[HAUTEUR][LARGEUR], int Tab_Monstre[HAUTEUR][LARGEUR],coord_Monstre *Point_Monstre)
{
    int Monstre_x, Monstre_y;
    int i, j, k, l, count;
    int Cg_X, Cg_Y, Cd_X, Cd_Y;
    int isOk;

    isOk = 0;

    while (isOk == 0)
    {
        count = 9;
        while (count > 0)
        {
             srand(time(NULL));
            Monstre_x = (rand()%(RMAX_X)+1);
            Monstre_y = (rand()%(RMAX_Y)+1);
            //force la position du monstre
            //Monstre_x = 8;
           // Monstre_y = 8;
            i = Monstre_y;
            j = Monstre_x;

        if (Terrain[i][j]== ' ')
        {



            Cg_Y = i-1;
            Cd_Y = i+1;
            Cg_X = j-1;
            Cd_X = j+1;

             //Ces Instructions permettent de vérifier que je lis bien les 8 cases autour de ma position aleatoire

            /* printf("i = %d, j = %d",i , j);  //ici on affiche le point centrale donc la potentielle position du monstre
             printf("\n");
             printf("Cg_X = %d, Cg_Y = %d" ,Cg_X, Cg_Y);  // ici on affiche la position de la case en haut a gauche de notre voisinage donc la numero 1
            printf("\n");
             printf("Cd_X = %d, Cd_Y = %d" ,Cd_X, Cd_Y);  // ici on affiche la position de la case en bas a droite de notre voisinage donc la numero 9
             printf("\n\n");*/


            for (k=Cg_Y;k<=Cd_Y;k++)
                {
                    for (l=Cg_X;l<=Cd_X;l++)
                    {

                        if (Terrain[k][l]!= 'P')
                        {
                        count--;
                        }
                    }
                }
        }
    isOk = 1;
        }
    //Terrain[i][j]= 'M';  pour verifier si le monstre prend bien sa position
    Tab_Monstre[i][j] = 16;
    Point_Monstre->x = j;
    Point_Monstre->y = i;
    }
}

//Procedure qui enregistre les traces des pisteurs
void traces_pisteurs(int *pn_pisteurs, int T_Traces_Pist[HAUTEUR][LARGEUR], struct coord_Pisteur T_Pisteur[PISTEUR_MAX])
{
    int i;
    for (i=1; i <=*pn_pisteurs;i++)
    {
        T_Traces_Pist[T_Pisteur[i].x][T_Pisteur[i].y] = 5;
    }
}

//Procedure qui met a jour les traces du monstre a chaque debut de tour
void traces_Monstre( int Tab_Monstre[HAUTEUR][LARGEUR],coord_Monstre *Point_Monstre, int *pn_Tour)
{
    int i, j, val;
    val = 0;

            for (i=0; i<HAUTEUR;i++)
            {
                for (j=0;j<LARGEUR;j++)
                {
                    if (Tab_Monstre[i][j] = 0)
                    {
                    val = Tab_Monstre[i][j];
                    Tab_Monstre[i][j] = val-1;
                    }


                }
            }
        Tab_Monstre[Point_Monstre->x][Point_Monstre->y] = 16;

}

//Procedure qui permet de faire le rapport des pisteurs
void Rapport_Pisteur(int *pn_pisteurs, struct coord_Pisteur T_Pisteur[PISTEUR_MAX], int Tab_Monstre[HAUTEUR][LARGEUR], char Terrain[HAUTEUR][LARGEUR], int *pn_Tour, int *vie_Monstre)
{
    int n_i,i,j, k, l, Qcase, fraicheur, count, reussite;
    int Cg_X, Cg_Y, Cd_X, Cd_Y;
    char reponse = ' ';


    for (n_i=1; n_i<=*pn_pisteurs;n_i++)
    {
        Qcase = 0;
        i = T_Pisteur[n_i].y;
        j = T_Pisteur[n_i].x;

        if (i>0 && j>0)
        {

        Terrain[i][j]= '!';
        system("cls");
        Affiche_Terrain(Terrain);
        Affiche_Legende();
        Affiche_nbTour(pn_Tour);
        Terrain[i][j]= 'P';

        if(Tab_Monstre[i][j]== 16)
        {
           printf("Le pisteur %d, s'est fait devorer !\n", n_i);
           T_Pisteur[n_i].x = 0;
           T_Pisteur[n_i].y = 0;
           *pn_pisteurs = *pn_pisteurs-1;
           n_i++;
        }

        color(12,0);
        printf("***********************************************-RAPPORT_DU_PISTEUR_%d-***************************************************\n", n_i);
        color(15,0);

            /* if (i-1<0){Cg_Y = 0;} else {Cg_Y = i-1;}
             if (i+1>=HAUTEUR){Cd_Y = HAUTEUR-1;} else {Cd_Y = i+1;}
             if (j-1<0){Cg_X = 0;} else {Cg_X = j-1;}
             if (j+1>=LARGEUR){Cd_X = LARGEUR-1;} else {Cd_X = j+1;}*/

             Cg_Y = i-1;
             Cd_Y = i+1;
             Cg_X = j-1;
             Cd_X = j+1;


             //Ces Instructions permettent de vérifier que je lis bien les 8 cases autour de ma position aleatoire

            /* printf("i = %d, j = %d",i , j);  //ici on affiche le point centrale donc la potentielle position du monstre
             printf("\n");
             printf("Cg_X = %d, Cg_Y = %d" ,Cg_X, Cg_Y);  // ici on affiche la position de la case en haut a gauche de notre voisinage donc la numero 1
            printf("\n");
             printf("Cd_X = %d, Cd_Y = %d" ,Cd_X, Cd_Y);  // ici on affiche la position de la case en bas a droite de notre voisinage donc la numero 9
             printf("\n\n");*/


             count = 0;

             for (k=Cg_Y;k<=Cd_Y;k++)
                {
                    for (l=Cg_X;l<=Cd_X;l++)
                    {
                        Qcase++;

                        if (Tab_Monstre[k][l]> 0 && Tab_Monstre[k][l] < 16)
                        {
                            fraicheur = Tab_Monstre[k][l];
                            printf("Traces en %d, de fraicheur : %d\n\n", Qcase, fraicheur);
                        }
                        if (Tab_Monstre[k][l] == 16)
                        {
                            printf("Je vois le Monstre\n");
                            printf("Si vous voulez tirer, appuyez sur T, sinon appuyez sur N : \n");
                            scanf("%c", &reponse);
                            fflush(stdin);
                            if (reponse == 'T' || reponse == 't')
                            {
                               reussite = Tir();

                               if (reussite == 1)
                               {
                                   printf("BRAVO !! Vous l'avez touche!\n\n");
                                   vie_Monstre = vie_Monstre-1;

                               }
                               else
                               {
                                   printf("OUPS !! Vous l'avez loupe!\n\n");
                               }
                            }
                            if (reponse == 'n'|| reponse == 'N')
                            {
                                printf("Une prochaine fois peut-etre !\n\n");
                            }
                        }

                        if (Tab_Monstre[k][l]== 0)
                        {
                            count++;
                        }
                        if (count == 9)
                        {
                        printf("Rien en 1,2,3,4,5,6,7,8,9\n\n");
                        }


                    }

                }

            fflush(stdin);
            color(1,0);
            printf("Pour passer a la suite appuyez sur entree\n");
            color(15,0);
            getchar();



    }

 }

        system("cls");
        Affiche_Terrain(Terrain);
        Affiche_Legende();
        Affiche_nbTour(pn_Tour);
}

//Procedure qui permet au joueur de deplacer ses pisteurs
void Deplace_Pisteur(int *pn_pisteurs, char Terrain[HAUTEUR][LARGEUR], int *pn_Tour, struct coord_Pisteur T_Pisteur[PISTEUR_MAX])
{
    int n_i, i, j, direction , cb_Case, isOk, isFx;

     for (n_i=1; n_i<=*pn_pisteurs;n_i++)
    {

        isOk = 0;
        isFx = 0;

        i = T_Pisteur[n_i].y;
        j = T_Pisteur[n_i].x;

        if (i>0 && j>0)
        {


        while (isOk == 0)
        {
        Terrain[i][j]= '?';
        system("cls");
        Affiche_Terrain(Terrain);
        Affiche_Legende();
        Affiche_nbTour(pn_Tour);
        Terrain[i][j]= ' ';
        if (isFx == 1)
        {
          color(12,0);
            printf("Vous ne pouvez pas sortir du terrain !\n");
            color(15,0);
        }




        direction = 0;
        cb_Case = -1;
        isFx = 0;

        color(14,0);
        printf("**********************************************-DEPLACEMENT_DU_PISTEUR_%d-************************************************\n\n", n_i);
        color(15,0);
         while (direction < 1 || direction > 4)
        {
        printf("Dans quelle direction voulez vous deplacer le pisteur %d, valeur entre 1 et 4 :\n",n_i);
        scanf("%d", &direction);
        fflush(stdin);
        }
         while (cb_Case < 0 || cb_Case > 4)
        {
        printf("De combien de cases voulez vous deplacer le pisteur %d, valeur entre 0 et 4 :\n",n_i);
        scanf("%d", &cb_Case);
        fflush(stdin);

        }

        switch (direction)
        {
        case 1 :
            if (i-cb_Case> 0)
            {
            Terrain[i-cb_Case][j]= 'P';
             T_Pisteur[n_i].y = i-cb_Case;
             T_Pisteur[n_i].x = j;
             isOk =1;

            }
            else
            {
                isOk = 0;
                isFx = 1;
            }
            break;

        case 2 :
            if (j+cb_Case<29)
            {
            Terrain[i][j+cb_Case]= 'P';
            T_Pisteur[n_i].y = i;
            T_Pisteur[n_i].x = j+cb_Case;
            isOk =1;

            }
            else
            {
                isOk = 0;
                isFx = 1;
            }
            break;
        case 3 :
            if (i+cb_Case<14)
            {
            Terrain[i+cb_Case][j]= 'P';
            T_Pisteur[n_i].y = i+cb_Case;
            T_Pisteur[n_i].x = j;
             isOk =1;

            }
            else
            {
                isOk = 0;
                isFx = 1;
            }
            break;
        case 4 :
            if (j-cb_Case> 0)
            {
            Terrain[i][j-cb_Case]= 'P';
            T_Pisteur[n_i].y = i;
            T_Pisteur[n_i].x = j-cb_Case;
              isOk =1;

            }
            else
            {
                isOk = 0;
                isFx = 1;
            }
            break;

         }
        }

    fflush(stdin);
    color(1,0);
    printf("Pour Deplacer le pisteur %d appuyez sur entree\n",n_i);
    color(15,0);
    getchar();
    system("cls");
    Affiche_Terrain(Terrain);
    Affiche_Legende();
    Affiche_nbTour(pn_Tour);

        }
    }

}

//Procedure qui deplace le monstre
void Deplace_Monstre( int Tab_Monstre[HAUTEUR][LARGEUR],coord_Monstre *Point_Monstre,  char Terrain[HAUTEUR][LARGEUR],int T_Traces_Pist[HAUTEUR][LARGEUR])
{
    int i, j, direction_R, isOk;

    isOk = 0;
    j = Point_Monstre->x;
    i = Point_Monstre->y;

    // Si le monstre voit un pisteur il vas sur sa case
    if (isOk == 0)
    {
        if (Terrain[i-RANGE_MONSTRE][j]== 'P')
        {
            Point_Monstre->x = j;
            Point_Monstre->y = i-RANGE_MONSTRE;
            Tab_Monstre[i-RANGE_MONSTRE][j] = 16;
            isOk = 1;
        }
        if (Terrain[i+RANGE_MONSTRE][j]== 'P')
        {
            Point_Monstre->x = j;
            Point_Monstre->y = i+RANGE_MONSTRE;
            Tab_Monstre[i-RANGE_MONSTRE][j] = 16;
            isOk = 1;
        }
        if (Terrain[i][j-RANGE_MONSTRE]== 'P')
        {
            Point_Monstre->x = j-RANGE_MONSTRE;
            Point_Monstre->y = i;
            Tab_Monstre[i][j-RANGE_MONSTRE] = 16;
            isOk = 1;
        }
        if (Terrain[i][j+RANGE_MONSTRE]== 'P')
        {
            Point_Monstre->x = j+RANGE_MONSTRE;
            Point_Monstre->y = i;
            Tab_Monstre[i][j+RANGE_MONSTRE] = 16;
            isOk = 1;
        }

    }
    // si le monstre voit une trace de pisteur il prend sa place
    if (isOk == 0)
    {
        if (T_Traces_Pist[i-RANGE_MONSTRE][j]>0)
        {
            Point_Monstre->x = j;
            Point_Monstre->y = i-RANGE_MONSTRE;
            Tab_Monstre[i-RANGE_MONSTRE][j] = 16;
            isOk = 1;
        }
        if (T_Traces_Pist[i+RANGE_MONSTRE][j]>0)
        {
            Point_Monstre->x = j;
            Point_Monstre->y = i+RANGE_MONSTRE;
            Tab_Monstre[i-RANGE_MONSTRE][j] = 16;
            isOk = 1;
        }
        if (T_Traces_Pist[i][j-RANGE_MONSTRE]>0)
        {
            Point_Monstre->x = j-RANGE_MONSTRE;
            Point_Monstre->y = i;
            Tab_Monstre[i][j-RANGE_MONSTRE] = 16;
            isOk = 1;
        }
        if (T_Traces_Pist[i][j+RANGE_MONSTRE]>0)
        {
            Point_Monstre->x = j+RANGE_MONSTRE;
            Point_Monstre->y = i;
            Tab_Monstre[i][j+RANGE_MONSTRE] = 16;
            isOk = 1;
        }

    }
    // si le monstre n'as rien vu il vas dans une direction au hasard
    while (isOk == 0)
        {
            direction_R = (rand()%(RMAX_DIR)+0);


        switch (direction_R)
        {
        case 1 :
            if (i-RANGE_MONSTRE> 0)
            {
            Tab_Monstre[i-RANGE_MONSTRE][j] = 16;
            Point_Monstre->x = j;
            Point_Monstre->y = i-RANGE_MONSTRE;
            isOk =1;

            }
            else
            {
                isOk = 0;
            }
            break;

        case 2 :
            if (j+RANGE_MONSTRE<29)
            {
            Tab_Monstre[i][j+RANGE_MONSTRE] = 16;
            Point_Monstre->x = j+RANGE_MONSTRE;
            Point_Monstre->y = i;
            isOk =1;

            }
            else
            {
                isOk = 0;
            }
            break;
        case 3 :
            if (i+RANGE_MONSTRE<14)
            {
            Tab_Monstre[i+RANGE_MONSTRE][j] = 16;
            Point_Monstre->x = j;
            Point_Monstre->y = i+RANGE_MONSTRE;
            isOk =1;

            }
            else
            {
                isOk = 0;
            }
            break;
        case 4 :
            if (j-RANGE_MONSTRE> 0)
            {
            Tab_Monstre[i][j-RANGE_MONSTRE] = 16;
            Point_Monstre->x = j-RANGE_MONSTRE;
            Point_Monstre->y = i;
            isOk =1;

            }
            else
            {
                isOk = 0;
            }
            break;

         }
        }

}

void ecran_victoire(int *pn_Tour)
{
    system("cls");
    color(6,0);
    printf("        (                   ) (   (       \n");
    color(12,0);
    printf("        )\\ )  (    *   ) ( /( )\\ ))\\ )    \n");
    color(6,0);
    printf(" (   ( (()/(  )\\ ` )  /( )\\()|()/(()/((   \n");
    color(12,0);
    printf(" )\\  )\\ /(_)|((_) ( )(_)|(_)\\ /(_))(_))\\  \n");
    color(4,0);
    printf("((_)((_|_)) )\\___(_(_())  ((_|_))(_))((_) \n");
    color(15,0);
    printf("\\ \\ / /|_ _| / __|_   _| / _ \\ |_ _| | _ \\ | __| \n");
    printf(" \\ V /  | | | (__  | |  | (_) | | |  |   / | _| \n");
    printf("  \\_/  |___| \\___| |_|   \\___/ |___| |_|_\\ | __| \n\n");

    printf("BRAVO !!!\n\n");
    printf("Vous avez battu le MONK C en %d tour !\n\n",*pn_Tour);

}

void ecran_defaite()
{
    system("cls");
    color(10,0);
    printf("oooooooooo.   oooooooooooo oooooooooooo   .o.       ooooo ooooooooooooo oooooooooooo \n");
    printf("`888'   `Y8b  `888'     `8 `888'     `8  .888.      `888' 8'   888   `8 `888'     `8 \n");
    printf(" 888      888  888          888         .8'888.      888       888       888         \n");
    printf(" 888      888  888oooo8     888oooo8   .8' `888.     888       888       888oooo8    \n");
    printf(" 888      888  888    '     888    '  .88ooo8888.    888       888       888    '    \n");
    printf(" 888     d88'  888       o  888      .8'     `888.   888       888       888       o \n");
    printf("o888bood8P'   o888ooooood8 o888o    o88o     o8888o o888o     o888o     o888ooooood8 \n\n");
    color(15,0);

    printf("Dommage vous avez perdu !\n");
    printf("Le Monstre a mange tous vos pisteurs !\n");

}









//FONCTION__________________________________________________________________________________________________________________________________________________

//fonction qui determine via un lance de des ayant 40% de reussite, si le tir touche le monstre ou non
int Tir ()
{
    int Jet_des;
    int reussite = 0;
    srand(time(NULL));
    Jet_des= (rand()%(10));

if (Jet_des<=4)
    {
    reussite = 1;
    return reussite;
    }
else
    {
    reussite = 0;
    return reussite;
    }


}
