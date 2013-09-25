#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<time.h>


int main ()
{
    srand(time(NULL));
    Processus p;
    int *t, Max=50, min=1;
    int lng=Max-min;
    int i=0,j;
    FILE *proc;
    proc=fopen("processus.bin","wb");
/*------------------------------------------GENRERATION DES PROCESSUS------------------------------------------------*/
    t=initialise(min,Max);
    melanger(t,lng);
    for(i=0;i<lng;i++)
    {
        p.id=t[i];
        p.temps=(rand()%(Max - min + 1))+ min;
        p.prio=(rand()%(Max - min + 1))+ min;
        fwrite(&p,sizeof(p),1,proc);
    }
    fclose(proc);
/*-------------------------------------INSERTION ET TRIE DES PROCESSUS DANS LA LISTE---------------------------------*/
    List_chaine* liste=construct();
    proc=fopen("processus.bin","rb");
    while(fread(&p,sizeof (p),1,proc)>0)
    {
        add_head(liste, p.id, p.temps, p.prio);
    }
    fclose(proc);
    free(t);
    trieID(liste);
    getListe(liste);
/*-------------------------------------EXECUTION ET TMGA DES PROCESSUS-----------------------------------------------*/
    int a;
    stock tab[5]={0,0};
    i = 1;
    printf("\n\n\t\t.*Algorithme d'ordonnancement des processus*.\n\t\t\t  Entrer le mode d'ordonnancement:\n\t\t\t  1-FIFO (First In First Out)\n\t\t\t  2-SJF (Shortest Job First)\n\t\t\t  3-Priorite\n\t\t\t  4-RR (Round Robbin)\n\t\t\t  5-Quitter\nChoix: ");
    scanf("%d", &a);
    while ((a >= 1) && (a < 5))
    {
        switch(a)
        {
            case 1:
                printf("\n\t\t\t\t\tFIFO");
                trieID(liste);
                tab[i].nom= "FIFO";
                tab[i].tmga=fifo(liste);
            break;
            case 2:
                trieTEMPS(liste);
                printf("\n\t\t\t\tTrie en fonction du temps\n");
                getListe(liste);
                printf("\n\t\t\t\t\tSJF");
                tab[i].nom= "SJF";
                tab[i].tmga=sjf(liste);
                break;
            case 3:
                triePRIO(liste);
                printf("\n\t\t\t\tTrie en fonction de la priorite\n");
                getListe(liste);
                printf("\n\t\t\t\t\tPRIORITE");
                tab[i].nom= "PRIO";
                tab[i].tmga=prio(liste);
            break;
            case 4:
                printf("\n\t\t\t\t\tR.R");
                trieID(liste);
                tab[i].nom= "R.R";
                tab[i].tmga=rr(liste, lng);
            break;
        }
        if (i>=2)
        {
            for (j=0; j<i; j++)
            {
                if (tab[i].tmga == tab[j].tmga)
                {
                    i--;
                }
            }
        }

        i++;
        if(i == 5) break;
        printf("\n\n\t\t\t  Entrer le mode d'ordonnancement:\n\t\t\t  1-FIFO (First In First Out)\n\t\t\t  2-SJF (Shortest Job First)\n\t\t\t  3-Priorite\n\t\t\t  4-RR (Round Robbin)\n\t\t\t  5-Quitter\nChoix: ");
        scanf("%d", &a);
    }
    printf("\n\n\n");

    printf("NOM |%s   |  %s   | %s   | %s",tab[1].nom, tab[2].nom, tab[3].nom, tab[4].nom);
    printf("\nTMGA|%.2f | %.2f | %.2f | %.2f\n", tab[1].tmga, tab[2].tmga, tab[3].tmga, tab[4].tmga);

    return 0;
}
