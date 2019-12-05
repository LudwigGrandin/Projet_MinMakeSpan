#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/**  PROTOTYPES  **/
void menuUtilisateur(int *choix, int *m, int *n,int *nbK, int *borneInferieurMoyenne, int *borneInferieurMax);
void generationIm(int m, int *n,int *D);
void generationIpM(int m, int *n,int *D);
int LSA(int m, int n, int *D, int *M,int *borneInferieurMoyenne);
int LTP(int m, int n, int *D, int *M,int *borneInferieurMoyenne);
//void calculBorne(int *M, int m, int *borneInferieurMax, int *borneInferieurMoyenne);

int main()
{
    /**     DEFINITION DES VARIABLES        **/
    int continuer = 0, choix = 0;
    int m=0,n=0,borneInferieurMoyenne=0,borneInferieurMax=0, nbK = 0;
    int borneInfMaxLSA=0,borneInfMaxLTP=0;
    int tempsTotal;
    float maxb=0, resultatLSA=0 , resultatLTP=0;
    float ratioLSA=0, ratioLTP=0;
    int tabval[27]={2,3,4,5,6,7,8,9,10,20,30,40,50,60,70,80,90,100,150,200,250,300,350,400,450,500,550}, nbval=27;
    int i, y;
    int D[302500]={0}, M[1000]={0};//, k[n];
    //Boucle pour avoir toutes les valeurs de tabVal
   for(y=0;y<nbval;y++)
    {
 /**DEBUT DE L'ALGORITHME**/
    //menuUtilisateur(&choix,&m,&n,&nbK,&borneInferieurMoyenne,&borneInferieurMax);

for(i = 0; i<1000; i++)
    {M[i] = 0;}
        m=tabval[y];
        printf("m=%d\n",m);
    //printf("\n\n les valeurs sont les suivantes :\nm = %d\nn = %d, k = %d\n borneInferieurMoyenne = %d\ borneInferieurMax = %d\n",m,n,k,borneInferieurMoyenne,borneInferieurMax);


        choix =2;

//selon le choix de l'utilisation on ne g�n�rera pas la m�me instance
    if(choix == 1)
    {
        generationIm(m,&n,D);
    }
    else
    {
        generationIpM(m,&n,D);
    }

    resultatLSA = LSA(m,n,D,M,&borneInferieurMoyenne);
    //calculBorne(M, m, &borneInferieurMax, &borneInferieurMoyenne);
    borneInfMaxLSA=resultatLSA;
    for(i = 0; i<1000; i++)
    {M[i] = 0;}

    resultatLTP=LTP(m,n,D,M,&borneInferieurMoyenne);
    //BorneInfMax = Dur�e la plus grande
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

    return 0;
}

/**DEBUT FONCTIONS**/

//Proc�dure menuUtilisateur
void menuUtilisateur(int *choix, int *m, int *n,int *nbK, int *borneInferieurMoyenne, int *borneInferieurMax)
{
    printf("Choisissez ce que vous voulez faire : \n - 1 : Generation d une instance de type Im\n - 2 : Generation d une instance IprimeM\n - 3 : Generation d instances multiples\n\nVotre choix : ");
    scanf("%d", choix);
    do
    {
        switch(*choix)
        {
            case 1 ://G�n�ration de l'instance Im
                printf("Saisissez le nombre de machine m : ");
                scanf("%d", m);
                break;
            case 2 ://G�n�ration de l'instance I'm
                printf("Saisissez le nombre de machine m : ");
                scanf("%d", m);
                break;
            case 3 ://G�n�ration des instances al�atoires
                printf("Saisissez le nombre de machine m : ");
                scanf("%d", m);
                printf("Saisissez le nombre de t�ches n : ");
                scanf("%d", n);
                printf("Saisissez le nombre de d'instance k :");
                scanf("%d", nbK);
                //Mettre s�curit� en fonction des contraintes
                printf("Saisissez la dur�e borneInferieurMoyenneimum des t�ches :");
                scanf("%d", borneInferieurMoyenne);
                printf("Saisissez la dur�e borneInferieurMaximum des t�ches :");
                scanf("%d", borneInferieurMax);

                break;
            default:
                break;
        }
    }while( (*m > 0) && (*n > 0) && (*nbK > 0) && (*borneInferieurMoyenne >= 0) && (*borneInferieurMoyenne < *borneInferieurMax) && (*borneInferieurMax > *borneInferieurMoyenne) );
}

void generationIm(int m, int *n,int *D)
{
    int i, tailleBoucle;
    *n = (m * m) + 1 ;// n = m� + 1
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
        if(i<3)//3 t�ches de dur�e m
        {
            D[i] = m;
        }
        else if(i>=3)//2 t�che de dur�e m+1, 2t�che de dur�e m+2 etc ... jusqu'a 2 t�ches de dur�e m+m-1
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

/*void generationIR(int m, int *n, int nbK, int borneInferieurMoyenne, int borneInferieurMax, int *D)
{
    int nbAlea,i;
    int a=0, b=1;//a valeur borneInferieurMoyenne al�atoire et b valeur borneInferieurMax al�atoire

    nbAlea = rand()%(b-a)�+ a;

    for(i=0; i<nbK; i++)
    {
       if(nbAlea == 0)//G�n�re Im
       {

       }
       else//G�n�re IpM
       {

       }
    }

}*/

int LSA(int m, int n, int *D, int *M,int *borneInferieurMoyenne)
{
    int i=0,y=0,z=0,machinex=0,tempsMin=0, numMachineSauv=0;
    int tempsTotal=0;
    *borneInferieurMoyenne = 0;
    tempsMin=m+m-1;
    for(i=0 ; i<n ; i++)
    {
        //Dur�e de la t�che la plus longue. Temps Min car c'est cette variable va stock� le temps de la machine qui a fini la premi�re et qui a donc le temps minimum � l'intant t

        //On regarde la premi�re machine disponible
        for(y=0 ; y<m ;y++)
        {
            //Si on a une machine qui � un temps plus petit que les autres alors c'est cette machine l� que l'on s�lectionne
            machinex = M[y];
            if(M[y] < tempsMin)
            {
                z = D[i];
                machinex = M[y];
                //Dans ces cas l�, tempsMin est �gal au temps minimum existant pour toutes les machines
                tempsMin = M[y]+D[i];
                //On sauvegarde le num�ro de machine afin de pouvoir ajouter la dur�e � celle-ci
                numMachineSauv = y;
                //y = m pour finir la boucle for avant d'arriver � la fin des machines
                //En effet, si l'on a trouv� une machine qui a fini, c'est celle qu'on selectionnera forcement
                y = m;
            }
            else if(y == m-1)
            {
                tempsMin=m+m-1;
                y =0;
            }
            else
            {}
        }
        //On fait ici la somme des dur�es  dans borneInf�rieurMoyenne pour pour calculer la moyenne de l'�chantillon
        *borneInferieurMoyenne += D[i];
        //Notre machine obtien la dur�e de la t�che

        z = D[i];
        M[numMachineSauv] += D[i];
        machinex = M[numMachineSauv];
        //Si jamais cette machine � le temps le plus grand de toute les machines alors temps total sera �gal au temps de cette machine
        if(M[numMachineSauv] > tempsTotal)
        {
            tempsTotal = M[numMachineSauv];
        }
    }
    //Calcul de la moyenne par le calcul borneInferieurMoyenne = Somme(Dur�es) / nbMachines
    //ci-dessous, c'est �gal � *borneInferieurMoyenne = *borneInferieurMoyenne / m;
    *borneInferieurMoyenne /= m;

    return tempsTotal;

}

int LTP(int m, int n, int *D, int *M,int *borneInferieurMoyenne)
{
    int i,j,tmp,fini=0,tempsMax, valActuelle;

//tri dans l'ordre d�croissant
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
