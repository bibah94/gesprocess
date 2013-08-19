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
    int n,i,j,y, b = 0,som = 0, a, c = 0;
    printf("Entrer le quantum: ");
    scanf("%d", &y);
    printf("Entrer le nombre de processus a traite: ");

    scanf("%d",&n);
    proc tmp;
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

    for(i=1; i<n; i++)
    {
        tmp.temps = t[0].temps;
        if(tmp.temps < t[i].temps)
        {
            tmp.temps = t[i].temps;
        }
    }
    while (tmp.temps > 0)
    {
        a = t[i].id;
        if (a != c)
        {
            for(i=0; i<n; i++)
            {
                if ((t[i].temps >= y) && (t[i].temps != 0))
                {
                    printf("Execution processus %d: ", t[i].id);
                    for(j=0; j<y; j++)
                    {
                        printf("\4");
                        _sleep(1000);
                    }
                    b = b + y;
                    t[i].temps = t[i].temps - y;
                    if (t[i].temps == 0)
                    {
                        som = som + b;
                    }
                }
                else if ((t[i].temps < y) && (t[i].temps != 0))
                {
                    printf("Execution processus %d: ", t[i].id);
                    for(j=0; j<t[i].temps; j++)
                    {
                        printf("\4");
                        _sleep(1000);
                    }
                    som = som+b;
                    b=b+t[i].temps;
                    t[i].temps = 0;

                }
                c = t[i].id;
                printf("\n");
            }

        tmp.temps = tmp.temps - y;
        }
            else
            {
                som = som + b;
                break;
            }


            printf("\n");



    }
<<<<<<< HEAD
    printf("Le TMGA est : %.2f", float(som)/n);
=======
    printf("Le TMGA est : %.2f", (float)(som)/n);
    system("PAUSE");
    return 0;
}
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
    int n,i,j,y, b = 0,som = 0, a, c = 0;
    printf("Entrer le quantum: ");
    scanf("%d", &y);
    printf("Entrer le nombre de processus a traite: ");

    scanf("%d",&n);
    proc tmp;
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

    for(i=1; i<n; i++)
    {
        tmp.temps = t[0].temps;
        if(tmp.temps < t[i].temps)
        {
            tmp.temps = t[i].temps;
        }
    }
    while (tmp.temps > 0)
    {
        a = t[i].id;
        if (a != c)
        {
            for(i=0; i<n; i++)
            {
                if ((t[i].temps >= y) && (t[i].temps != 0))
                {
                    printf("Execution processus %d: ", t[i].id);
                    for(j=0; j<y; j++)
                    {
                        printf("\4");
                        _sleep(1000);
                    }
                    b = b + y;
                    t[i].temps = t[i].temps - y;
                    if (t[i].temps == 0)
                    {
                        som = som + b;
                    }
                }
                else if ((t[i].temps < y) && (t[i].temps != 0))
                {
                    printf("Execution processus %d: ", t[i].id);
                    for(j=0; j<t[i].temps; j++)
                    {
                        printf("\4");
                        _sleep(1000);
                    }
                    som = som+b;
                    b=b+t[i].temps;
                    t[i].temps = 0;

                }
                c = t[i].id;
                printf("\n");
            }

        tmp.temps = tmp.temps - y;
        }
            else
            {
                som = som + b;
                break;
            }


            printf("\n");



    }
    printf("Le TMGA est : %.2f", (float)(som)/n);
>>>>>>> e4b1dad5a8ca2c669b3173ad2ad8c2dfa7c34715
    return 0;
}
