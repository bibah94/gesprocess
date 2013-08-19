#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


typedef struct processus{

                            int id;

                            int temps;

                            int prio;

                            //char *adresse;

                        }proc;
proc ini (int id, int te, int prio)
{
    proc p;
    p.id = id;
    p.temps = te;
    p.prio = prio;
    return p;
}

int main ()
{
    //proc tab[N];
    int n,i,j,y = 0, som = 0, tps = 0;
    proc tmp;

    printf("Entrer le nombre de processus a traite: ");

    scanf("%d",&n);
    proc t[n];
    for(i=0; i<n; i++)
    {
        printf("\nProcessus %d\n", i+1);
        printf("Entrez le temps d'execution: ");
        scanf("%d",&t[i].temps);
        printf("Entrez la priorite: ");
        scanf("%d",&t[i].prio);
        t[i].id = i+1;
        printf("ID %d", i+1);
    }
    printf("\n");

    while (y==0)
    {
        y=1;
        for(i=0; i<n ;i++)
        {
             if(t[i+1].temps < t[i].temps )
             {
                 tmp=t[i];
                 t[i]=t[i+1];
                 t[i+1]=tmp;
                 y=0;
             }
        }
    }

    for(i=0; i<n; i++)
    {
        printf("Execution processus %d: ", t[i].id);
        for(j=0; j<t[i].temps; j++)
        {
            printf("\4");
            _sleep(1000);
        }
        printf("\n");
    }
    for (i=0; i<n-1; i++)
    {
        tps = t[i].temps + tps;
        som = som + tps;
    }
    printf("Le TMGA est : %.2f",float(som)/n);
<<<<<<< HEAD
    printf("Le TMGA est : %.2f",float(som)/n);
=======
>>>>>>> e4b1dad5a8ca2c669b3173ad2ad8c2dfa7c34715

    return 0;
}


