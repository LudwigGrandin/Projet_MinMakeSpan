#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


/**  PROTOTYPES  **/
void menuUtilisateur(int *choix, int *m, int *n,int *nbK, int *borneInferieurMoyenne, int *borneInferieurMax);
void generationIm(int m, int *n,int *D);
void generationIpM(int m, int *n,int *D);
void generationIR(int *D, int n, int min,int max);
int LSA(int m, int n, int *D, int *M,int *borneInferieurMoyenne);
int LTP(int m, int n, int *D, int *M,int *borneInferieurMoyenne);
void initM(int *M, int n);
//void calculBorne(int *M, int m, int *borneInferieurMax, int *borneInferieurMoyenne);

int main()
{
    /**     DEFINITION DES VARIABLES        **/
    srand(time(NULL));
    int continuer = 0, choix = 0;
    //m = nbMachine , n = nombre de tâches
    int m=0,n=0,borneInferieurMoyenne=0,borneInferieurMax=0, nbK = 0, min = 0 , max = 0;
    int K = 0;
    float borneInfMaxLSA=0,borneInfMaxLTP=0;
    int tempsTotal;
    float maxb=0, resultatLSA=0 , resultatLTP=0;
    float ratioLSA=0, ratioLTP=0;
    int tabval[27]={2,3,4,5,6,7,8,9,10,20,30,40,50,60,70,80,90,100,150,200,250,300,350,400,450,500,550}, nbval=27;
    int i=0, y=0;
    int nMax;
    int D[302500]={0}, M[1000]={0};



    //Boucle pour avoir toutes les valeurs de tabVal

 /**DEBUT DE L'ALGORITHME**/
do
{

    if(choix == 0)
    {
        menuUtilisateur(&choix,&m,&n,&nbK,&min,&max);
    }
    else{}

    /*nMax = m*m+1;
    int D[nMax], M[n];*/

 for(y=0;y<nbval;y++)
    {


    initM(M,n);
    //m=tabval[y];

    printf("m=%d\n",m);
    //printf("\n\n les valeurs sont les suivantes :\nm = %d\nn = %d, k = %d\n borneInferieurMoyenne = %d\ borneInferieurMax = %d\n",m,n,k,borneInferieurMoyenne,borneInferieurMax);


//selon le choix de l'utilisation on ne générera pas la même instance

    switch(choix)
    {
        case 1 :
            generationIm(m,&n,D);
            break;
        case 2 :
            generationIpM(m,&n,D);
            break;
        case 3 :
            generationIR(D,n,min,max);
            break;
        default:
            break;

    }


    resultatLSA = LSA(m,n,D,M,&borneInferieurMoyenne);
    borneInfMaxLSA=resultatLSA;
    initM(M,n);
    resultatLTP=LTP(m,n,D,M,&borneInferieurMoyenne);
    //BorneInfMax = Durée la plus grande
    borneInfMaxLTP=resultatLTP;
    //Calcul Borne Inf Max
    if(borneInfMaxLSA>=borneInfMaxLTP)
    {borneInferieurMax = borneInfMaxLSA;}
    else
    {borneInferieurMax = borneInfMaxLTP;}




    //Calcul MaxB
    if(borneInferieurMax >= borneInferieurMoyenne)
    {maxb=borneInferieurMax;}
    else
    {maxb=borneInferieurMoyenne;}
    ratioLSA = resultatLSA / maxb;
    ratioLTP = resultatLTP / maxb;

    //Affichage final

    printf("BorneInferieurMax : %d\n", borneInferieurMax);
    printf("BorneInferieurMoyenne : %d\n",borneInferieurMoyenne);
    printf("Resultat LSA : %.0f\n",resultatLSA);
    printf("maxb : %f\n",maxb);
    printf("Ratio LSA : %.2f\n",ratioLSA);
    printf("Resultat LTP : %.0f\n", resultatLTP);
    printf("Ratio LTP : %.2f\n\n", ratioLTP);
    }
    if(nbK != 0)
    {
        nbK --;
        continuer = 1;
    }
    else
    {
        choix = 0;
        printf("Souhaitez vous continuer ?  1 : oui ; 0 : non : ");
        scanf("%d", &continuer);
    }

}while(continuer == 1);

    return 0;
}

/**DEBUT FONCTIONS**/

//Procédure menuUtilisateur
void menuUtilisateur(int *choix, int *m, int *n,int *nbK, int *min, int *max)
{
    printf("Choisissez ce que vous voulez faire : \n - 1 : Generation d une instance de type Im\n - 2 : Generation d une instance IprimeM\n - 3 : Generation d instances multiples\n\nVotre choix : ");
    scanf("%d", choix);
    do
    {
        switch(*choix)
        {
            case 1 ://Génération de l'instance Im
                printf("Saisissez le nombre de machine m : ");
                scanf("%d", m);
                break;
            case 2 ://Génération de l'instance I'm
                printf("Saisissez le nombre de machine m : ");
                scanf("%d", m);
                break;
            case 3 ://Génération des instances aléatoires
                printf("Saisissez le nombre de machine m : ");
                scanf("%d", m);
                printf("Saisissez le nombre de taches n : ");
                scanf("%d", n);
                printf("Saisissez le nombre de d'instance k :");
                scanf("%d", nbK);
                //Mettre sécurité en fonction des contraintes
                printf("Saisissez la duree minimum des taches :");
                scanf("%d", min);
                printf("Saisissez la duree maximum des taches :");
                scanf("%d", max);

                break;
            default:
                break;
        }
    }while( !(*m > 0) && !(*n > 0) && !(*nbK > 0) && !(*max > 0) && !(*min < *max) );
}

void generationIm(int m, int *n,int *D)
{
    int i, tailleBoucle;
    *n = (m * m) + 1 ;// n = m² + 1
    tailleBoucle = (*n)-1;

    //printf("taille boucle = %d\n", tailleBoucle);
    for(i=0 ; i < tailleBoucle ; i++)
    {
        D[i] = 1;
    }
    tailleBoucle = m;
    D[i] = m;
}


void generationIpM(int m, int *n,int *D)
{
    int i, tailleBoucle, compteur = 1;
    *n= (2*m) + 1;
    tailleBoucle = *n;

    for(i=0 ; i<tailleBoucle ; i++)
    {
        if(i<3)//3 tâches de durée m
        {
            D[i] = m;
        }
        else if(i>=3)//2 tâche de durée m+1, 2tâche de durée m+2 etc ... jusqu'a 2 tâches de durée m+m-1
        {
            D[i] = m + compteur;
            if(i%2 == 0 )
            {
                compteur ++;
            }
        }
        else
        {}
    }
}

void generationIR(int *D, int n, int min,int max)
{
    int i;

    for(i=0; i<n; i++)
    {
        D[i] = rand()%(max-min) + min;
    }
}

int LSA(int m, int n, int *D, int *M,int *borneInferieurMoyenne)
{
    int i=0,y=0,z=0,machinex=0,tempsMin=0, numMachineSauv=0;
    int tempsTotal=0;
    *borneInferieurMoyenne = 0;
    tempsMin=m+m+1;

    for(i=0 ; i<n ; i++)
    {
        //Durée de la tâche la plus longue. Temps Min car c'est cette variable va stocké le temps de la machine qui a fini la première et qui a donc le temps minimum à l'intant t

        //On regarde la première machine disponible
        for(y=0 ; y<m ;y++)
        {
            //Si on a une machine qui à un temps plus petit que les autres alors c'est cette machine là que l'on sélectionne
            machinex = M[y];

            if(M[y] < tempsMin)
            {
                //Dans ces cas là, tempsMin est égal au temps minimum existant pour toutes les machines
                tempsMin = M[y]+1;
                //On sauvegarde le numéro de machine afin de pouvoir ajouter la durée à celle-ci
                numMachineSauv = y;
                //y = m pour finir la boucle for avant d'arriver à la fin des machines
                //En effet, si l'on a trouvé une machine qui a fini, c'est celle qu'on selectionnera forcement
                y = m;
            }
            else if(y == m-1)
            {
                tempsMin+= 2*tempsMin;
                y =0;
            }
            else
            {}
        }
        //On fait ici la somme des durées  dans borneInférieurMoyenne pour pour calculer la moyenne de l'échantillon
        *borneInferieurMoyenne += D[i];
        //Notre machine obtien la durée de la tâche

        z = D[i];
        M[numMachineSauv] += D[i];
        machinex = M[numMachineSauv];
        //Si jamais cette machine à le temps le plus grand de toute les machines alors temps total sera égal au temps de cette machine
        if(M[numMachineSauv] > tempsTotal)
        {
            tempsTotal = M[numMachineSauv];
        }
    }
    //Calcul de la moyenne par le calcul borneInferieurMoyenne = Somme(Durées) / nbMachines
    //ci-dessous, c'est égal à *borneInferieurMoyenne = *borneInferieurMoyenne / m;
    *borneInferieurMoyenne /= m;

    return tempsTotal;

}

int LTP(int m, int n, int *D, int *M,int *borneInferieurMoyenne)
{
    int i,j,tmp,fini=0,tempsMax, valActuelle;

//tri dans l'ordre décroissant
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(D[j]<D[j+1])
            {
                tmp = D[j];
                D[j]=D[j+1];
                D[j+1]=tmp;
            }
        }
    }

    tempsMax = LSA(m,n,D,M,borneInferieurMoyenne);

    return tempsMax;
}



void calculRatio()
{

}

void initM(int *M,int n)
{
    int i = 0;

    for(i = 0; i<n; i++)
    {M[i] = 0;}
}


/*
void AffichageFinal(int borneInferieurMax,int borneInferieurMoyenne, int resultatLSA, int maxb, float)
{
    printf("BorneInferieurMax : %d\n", borneInferieurMax);
    printf("BorneInferieurMoyenne : %d\n",borneInferieurMoyenne);
    printf("Resultat LSA : %.0f\n",resultatLSA);
    printf("maxb : %f\n",maxb);
    printf("Ratio LSA : %.2f\n",ratioLSA);
    printf("Resultat LTP : %.0f\n", resultatLTP);
    printf("Ratio LTP : %.2f\n\n", ratioLTP);
}*/
