#include "header.h"


/*-------------------------------INITIALISER ET GENERER LES NOMBRES----------------------------------------------*/
int* initialise(int a, int b)
{
    int taille = b-a;
    int* resultat=(int*)malloc((taille)*sizeof (int));
    int i=0;
    for(i = 0; i< taille; i++)
    {
        resultat[i]=i+a;
    }
    return resultat;
}
void melanger(int* tableau, int taille)
{
    int i=0;
    int nombre_tire=0;
    int temp=0;
    for(i = 0; i< taille;i++)
    {
        nombre_tire=rand()%taille;
        temp = tableau[i];
        tableau[i] = tableau[nombre_tire];
        tableau[nombre_tire]=temp;
    }
}

/*---------------------------------------------------------------------------------------------------------------*/

List_chaine* construct()
      {
          List_chaine* liste=(List_chaine*)malloc(sizeof(List_chaine));
          liste-> first=NULL;
          return liste;
      }

void add_head(List_chaine* liste, int id,int temps,int prio)
{
        Processus* pr =(Processus*)malloc(sizeof(Processus));
        pr->id=id;
        pr-> temps=temps;
        pr->prio=prio;
        pr->next=liste->first;
        liste->first=pr;
}

void add_tail(List_chaine* liste, int id,int temps,int prio)
{
        Processus* pr =(Processus*)malloc(sizeof(Processus));
        pr->next=NULL;
        pr->id=id;
        pr->temps=temps;
        pr->prio=prio;
        Processus* pr1 =NULL;
        pr1=liste->first;
        if(pr1!=NULL)
        {
            while(pr1->next!=NULL)
            {
                  pr1=pr1->next;
            }
            pr1->next=pr;
        }
        else
        {
             liste->first=pr;
        }
}

void getListe(List_chaine* liste)
{
        Processus* pr =NULL;
        pr=liste->first;
        while(pr!=NULL)
        {
              printf("\nPROCESSUS %d:\nId: %d\tTemps d'execution: %d\tPriorite: %d\n",pr->id ,pr->id ,pr->temps ,pr->prio);
              pr=pr-> next;
        }
}

void suprimmeFisrt(List_chaine* liste)
{
     Processus* pr=NULL;
     if(liste->first!=NULL)
     {
         pr=liste->first;
         pr=pr->next;
         free(liste->first);
         liste->first=pr;
     }

}

void suprimmeID(List_chaine* liste,int id)
{
      Processus* pr=NULL;
      Processus* pr1=NULL;
      pr=liste->first;
      pr1=liste->first;
      if(liste->first!=NULL)
      {
            while(pr!=NULL)
            {

                  if(pr->id==id) break;
                  pr1=pr;
                  pr=pr->next;
            }
            if(pr!=NULL && pr1==liste->first)
            {

                 free(liste->first);
                 liste->first=pr->next;
            }
            else if(pr!=NULL)
            {
                 free(pr1->next);
                 pr1->next=pr->next;
            }
       }
}

void trieID(List_chaine *liste)
{
    int ya=0;
    Processus *pr=NULL, *pr1=NULL , temp;
    while(ya==0)
    {
        pr=liste->first;
        pr1=pr->next;
        ya=1;
        while(pr1 != NULL)
        {
            if(pr->id > pr1->id)
            {
                temp.id=pr->id;
                temp.temps=pr->temps;
                temp.prio=pr->prio;
                pr->id=pr1->id;
                pr->temps=pr1->temps;
                pr->prio=pr1->prio;
                pr1->id=temp.id;
                pr1->temps=temp.temps;
                pr1->prio=temp.prio;
                ya=0;
            }
            pr1=pr1->next;
            pr=pr->next;
          }
    }
}

void trieTEMPS(List_chaine *liste)
{
    int ya=0;
    Processus *pr=NULL, *pr1=NULL , temp;
    while(ya==0)
    {
        pr=liste->first;
        pr1=pr->next;
        ya=1;
        while(pr1 != NULL)
        {
            if(pr->temps > pr1->temps)
            {
                temp.id=pr->id;
                temp.temps=pr->temps;
                temp.prio=pr->prio;
                pr->id=pr1->id;
                pr->temps=pr1->temps;
                pr->prio=pr1->prio;
                pr1->id=temp.id;
                pr1->temps=temp.temps;
                pr1->prio=temp.prio;
                ya=0;
            }
            else if((pr->temps == pr1->temps) && (pr->id > pr1->id))
            {
                temp.id=pr->id;
                temp.temps=pr->temps;
                temp.prio=pr->prio;
                pr->id=pr1->id;
                pr->temps=pr1->temps;
                pr->prio=pr1->prio;
                pr1->id=temp.id;
                pr1->temps=temp.temps;
                pr1->prio=temp.prio;
                ya=0;
            }
            pr1=pr1->next;
            pr=pr->next;
          }
    }
}

void triePRIO(List_chaine *liste)
{
    int ya=0;
    Processus *pr=NULL, *pr1=NULL , temp;
    while(ya==0)
    {
        pr=liste->first;
        pr1=pr->next;
        ya=1;
        while(pr1 != NULL)
        {
            if(pr->prio > pr1->prio)
            {
                temp.id=pr->id;
                temp.temps=pr->temps;
                temp.prio=pr->prio;
                pr->id=pr1->id;
                pr->temps=pr1->temps;
                pr->prio=pr1->prio;
                pr1->id=temp.id;
                pr1->temps=temp.temps;
                pr1->prio=temp.prio;
                ya=0;
            }
            else if((pr->prio == pr1->prio) && (pr->id > pr1->id))
            {
                temp.id=pr->id;
                temp.temps=pr->temps;
                temp.prio=pr->prio;
                pr->id=pr1->id;
                pr->temps=pr1->temps;
                pr->prio=pr1->prio;
                pr1->id=temp.id;
                pr1->temps=temp.temps;
                pr1->prio=temp.prio;
                ya=0;
            }
            pr1=pr1->next;
            pr=pr->next;
          }
    }
}

float fifo (List_chaine *liste)
{
    int i = 0, tps = 0,som = 0;
    Processus *pr = NULL;
    pr = liste->first;
    printf("\n\t\t\t\tExecution des processus\n");
    while(pr!=NULL)
    {
        printf("Processus %d: ", pr->id);
        if(pr->id <= 9)
        {
                printf(" ");
        }
        for(i=0; i<pr->temps; i++)
        {
            printf("\4");
        }
        pr = pr->next;
        printf("\n");
    }
    pr = liste->first;
    i = 0;
    while(pr!=NULL)
    {
        i++;
        tps = pr->temps + tps;
        som = som + tps;
        pr = pr->next;
        if (pr == NULL)
        {
            som = som - tps;
        }
    }

    printf("\nLe TMGA est : %.3f", (float)som/i);
    return (float)som/i;
}

float sjf (List_chaine *liste)
{
    int i = 0, tps = 0,som = 0;
    Processus *pr = NULL;
    pr = liste->first;
    printf("\n\t\t\t\tExecution des processus\n");
    while(pr!=NULL)
    {
        printf("Processus %d: ", pr->id);
        if(pr->id <= 9)
        {
                printf(" ");
        }
        for(i=0; i<pr->temps; i++)
        {

            printf("\4");
        }
        pr = pr->next;
        printf("\n");
    }
    pr = liste->first;
    i = 0;
    while(pr!=NULL)
    {
        i++;
        tps = pr->temps + tps;
        som = som + tps;
        pr = pr->next;
        if (pr == NULL)
        {
            som = som - tps;
        }
    }

    printf("\nLe TMGA est : %.3f", (float)som/i);
    return (float)som/i;
}

float prio (List_chaine *liste)
{
    int i = 0, tps = 0,som = 0;
    Processus *pr = NULL;
    pr = liste->first;
    printf("\n\t\t\t\t       Priorite\n\t\t\t\tExecution des processus\n");
    while(pr!=NULL)
    {
        printf("Processus %d: ", pr->id);
        if(pr->id <= 9)
        {
                printf(" ");
        }
        for(i=0; i<pr->temps; i++)
        {

            printf("\4");
        }
        pr = pr->next;
        printf("\n");
    }
    pr = liste->first;
    i = 0;
    while(pr!=NULL)
    {
        i++;
        tps = pr->temps + tps;
        som = som + tps;
        pr = pr->next;
        if (pr == NULL)
        {
            som = som - tps;
        }
    }

    printf("\nLe TMGA est : %.3f", (float)som/i);
    return (float)som/i;
}

float rr (List_chaine* liste, int lng)
{
    int i = 0,j,y, b = 0,som = 0, a= 0, c = 0, d, max;
    Processus *pr = NULL, *pr1=NULL;
    pr = liste->first;
    max = pr->temps;
    pr1 = pr->next;
/*-------------------------------------------------RECHERCHE DU MAX DE TEMPS-----------------------------------------*/
    while(pr1 != NULL)
    {
        if(max < pr1->temps)
        {
            max = pr1->temps;
        }
        pr1 = pr1->next;
    }
/*-------------------------------------------------------------------------------------------------------------------*/
    printf("\nEntrer le quantum: ");
    scanf("%d", &y);
    while ((max > 0) && (a == 0)) ///s'arrete si a != 0
    {
        pr = liste->first;
        printf("-----------------TOUR %d------------------\n",i+1);
        i++;
        while(pr != NULL)
        {
            if ((pr->temps >= y) && (pr->temps != 0) && (a==0))
            {
                if ((c == pr->id) && (d == 0)) ///derniere execution si l'avant dernier processus est < a y
                {
                    //printf("\tTA%d=%d",t[i].temps, b);
                    som = som + b;
                    a = 1; ///nous permet de ne pas répété le derniere processus qui reste
                    break;
                }
                if ((c == pr->id) && (d != 0)) ///derniere execution si l'avant dernier processus est = a y
                {
                    //printf("\tTA%d=%d",pr->temps, b);
                    b -=y;
                    som = som + b;
                    a = 1; ///nous permet de ne pas répété le derniere processus qui reste
                    break;
                }
                if (a == 0) /// on entre si ce nest pas le dernier processus qui reste
                {
                    printf("Execution processus %d: ", pr->id);
                    if(pr->id <= 9)
                    {
                        printf(" ");
                    }
                    for(j=0; j<y; j++)
                    {
                        printf("\4");
                    }
                    b = b + y;
                    pr->temps = pr->temps - y;
                    c = pr->id;
                    if (pr->temps == 0)
                    {
                        b -=y;
                        //printf("\tTA%d=%d",pr->temps, b);
                        som = som + b;
                        b +=y;
                        d= 1; /// dire que l'avant dernier processus est = a y si c =t[i+1].id
                        printf("\n");
                    }
                }
            }
            else if ((pr->temps < y) && (pr->temps != 0) && (a==0))
            {
                printf("Execution processus %d: ", pr->id);
                if(pr->id <= 9)
                {
                    printf(" ");
                }
                for(j=0; j<pr->temps; j++)
                {
                    printf("\4");
                }
                // printf("\tTA%d=%d",pr->temps, b);
                som = som+b;
                b=b+pr->temps;
                pr->temps = 0;
                d = 0; /// dire que l'avant dernier processus est < a y si c =t[i+1].id
                printf("\n");
            }
            if ((a == 0) && (pr->temps != 0)) /// pour embellir l'affichage
            {
                printf("\n");
            }
            pr = pr->next;
        }
        max = max - y;
        if (a == 0) /// pour embellir l'affichage
        {
            printf("\n");
        }
    }
    printf("\-----------------FIN TOUR-------------------\n\n");
    printf("Le TMGA est : %.2f", (float)(som)/lng);
    return (float)(som)/lng;
}

